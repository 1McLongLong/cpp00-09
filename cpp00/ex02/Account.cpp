#include "Account.hpp"
#include <iostream>
#include <iomanip>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

int	Account::getNbAccounts(void) { return _nbAccounts; }

int	Account::getTotalAmount(void) { return _totalAmount; }

int	Account::getNbDeposits(void) { return _totalNbDeposits; }

int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }

void	Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << _nbAccounts
    << ";total:" << _totalAmount
    << ";deposits:" << _totalNbDeposits
    << ";withdrawals:" << _totalNbWithdrawals << '\n';
}

void	Account::makeDeposit( int deposit ) {
  _totalAmount += deposit;
  _nbDeposits++;
  _totalNbDeposits++;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount
    << ";deposit:" << deposit;
  _amount += deposit;
  std::cout << ";amount:" << _amount
    << ";nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal( int withdrawal ) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
    << ";p_amount:" << _amount; 
  if (_amount < withdrawal) {
    std::cout << ";withdrawal:refused" << '\n';
    return 0;
  }
  else {
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal;
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    std::cout << ";amount:" << _amount
      << ";nb_withdrawals:" << _nbWithdrawals << '\n';
  }
  return 1;
}

int		Account::checkAmount( void ) const { return _amount; }

void	Account::_displayTimestamp(void) {
  time_t	now;

  now = time(NULL);
  std::cout << std::put_time(localtime(&now), "[%Y%m%d_%H%M%S] ");
}

void	Account::displayStatus( void ) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex
    << ";amount:" << _amount
    << ";deposits:" << _nbDeposits
    << ";withdrawals:" << _nbWithdrawals
    << '\n';
}

Account::Account (int initial_deposit) {
  _accountIndex = _nbAccounts;
  _amount = initial_deposit;
  _nbDeposits = 0;
  _nbWithdrawals = 0;
  _nbAccounts++;
  _totalAmount += initial_deposit;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex 
    << ";amount:" << _amount 
    << ";created\n"; 
}

Account::~Account (void) {
  _nbAccounts--;
  _displayTimestamp();
  std::cout << "index:" << _accountIndex 
    << ";amount:" << _amount 
    << ";closed\n"; 
}
