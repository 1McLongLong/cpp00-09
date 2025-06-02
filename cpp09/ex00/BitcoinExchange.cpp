#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : filename("") {}

BitcoinExchange::BitcoinExchange(char *filename) : filename(filename) {
  this->input_file.open(filename);
  if (!this->input_file.is_open()) {
    throw std::runtime_error("Error: could not open file");
  }
  this->data_file.open("data.csv");
  if (!this->data_file.is_open()) {
    throw std::runtime_error("Error: could not open file");
  }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
  *this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
  if (this != &copy){
    this->filename = copy.filename;
    if (this->input_file.is_open())
      this->input_file.close();
    if (this->data_file.is_open()) 
      this->data_file.close();
    this->input_file.open(this->filename.c_str());
    this->data_file.open("data.csv");  
  }
  return *this;
}


BitcoinExchange::~BitcoinExchange() {
  this->input_file.close();
  this->data_file.close();
}

void BitcoinExchange::processInput() {
  read_dataFile();
  read_inputFile();
}

void BitcoinExchange::read_dataFile() {
  std::string line;
  std::getline(this->data_file, line);
  double value;
  while (std::getline(this->data_file, line)) {
    std::string date = line.substr(0, 10);
    std::string str_value = line.substr(11);

    std::stringstream ss(str_value);
    ss >> value;
    data.insert(std::pair<std::string, double>(date, value));
  }
}

void BitcoinExchange::read_inputFile() {
  std::string line;
  std::getline(this->input_file, line);
  if (line != "date | value") {
    throw std::runtime_error("Error: input file should start with (date | value)");
  }
  while (std::getline(this->input_file, line)) {
    try {
      size_t sep = line.find(" | ");
      if (sep == std::string::npos) {
        throw std::invalid_argument("Error: bad input => " + line);
      }
      std::string date = line.substr(0, sep);
      std::string valueStr = line.substr(sep + 1);
      parseDate(date);
      // parseValue(valueStr, line);
      valueStr = valueStr.substr(2);
      search(date, valueStr);
    }
    catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}



void BitcoinExchange::parseDate(std::string date) {
  if (date.length() != 10 || date[4] != '-' || date[7] != '-')
    throw std::runtime_error("Error: bad input => " + date);

  int year, month, day;
  std::stringstream ss(date.substr(0, 4));
  ss >> year;
  if (ss.fail()) throw std::runtime_error("Error: bad input => " + date);
  ss.clear();
  ss.str(date.substr(5, 2));
  ss >> month;
  if (ss.fail()) throw std::runtime_error("Error: bad input => " + date);
  ss.clear();
  ss.str(date.substr(8, 2));
  ss >> day;
  if (ss.fail()) throw std::runtime_error("Error: bad input => " + date);

  if (month < 1 || month > 12 || day < 1 || day > 31 || year < 2009 || year > 2022)
    throw std::runtime_error("Error: bad input => " + date);

  int days_of_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // Leap year check
  bool is_leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
  int max_day = days_of_month[month - 1];
  if (month == 2 && is_leap)
    max_day = 29;
  if (day > max_day)
    throw std::runtime_error("Error: bad input => " + date);
  if ((year == 2022 && month > 3) ||
     (year == 2022 && month == 3 && day > 29)) {
    throw std::runtime_error("Error: bad input => " + date);
  }
}

void BitcoinExchange::search(std::string date, std::string value) {
  std::stringstream ss(value);
  double val;
  ss >> val;
  if (ss.fail() || checkFloat(value) || val <= 0 || val > 1000) {
    throw std::runtime_error("Error: invalid value => " + value);
  }
  std::map<std::string, double>::const_iterator it = this->data.lower_bound(date);
  if (it == this->data.end() || it->first != date) {
    if (it == this->data.begin()) {
      throw std::runtime_error("Error: no earlier data for " + date);
    }
    --it;
  }

  double price = it->second;
  std::cout << date << " => " << value << " = " << (val * price) << std::endl;
}

bool BitcoinExchange::checkFloat(std::string value) {
  int check = 0;
  if (value[0] == '-' || value[0] == '.' || value[value.size() - 1] == '.')
    return true;

  for (size_t i = 0; i < value.size(); ++i) {
    if (value[i] == '.') {
      check++;
      if (check > 1)
        return true;
    }
    else if (value[i] < '0' || value[i] > '9') {
      return true;
    }
  }
  return false;
}




