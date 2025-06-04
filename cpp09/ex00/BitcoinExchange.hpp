#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange {
  std::map<std::string, double> data;
  std::ifstream                 input_file;
  std::ifstream                 data_file;
  std::string                   filename;

  bool checkFloat(std::string value);
  void read_dataFile();
  void read_inputFile();
  void parseDate(std::string date);
  void parseValue(std::string valueStr, std::string line);
  void search(std::string date, std::string value);

public:
  BitcoinExchange();
  BitcoinExchange(char *filename);
  BitcoinExchange(const BitcoinExchange &copy);
  BitcoinExchange &operator=(const BitcoinExchange &copy);
  ~BitcoinExchange();
  void processInput();

};















#endif
