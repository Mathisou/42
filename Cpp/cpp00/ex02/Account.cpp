#include "Account.hpp"
#include <iostream>

Account::Account(int initial_deposit){
	this->_accountIndex = 1; //?
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::~Account(void){
	return ;
}

int	Account::getNbAccounts( void ){
	return _nbAccounts;
}
int	Account::getTotalAmount( void ){
	return _totalAmount;
}
int	Account::getNbDeposits( void ){
	return _totalNbDeposits;
}
int	Account::getNbWithdrawals( void ){
	return _totalNbWithdrawals;
}

void	Account::_displayTimestamp( void ){

	time_t curr = time(0);
	tm *ltm = localtime(&curr);

	std::cout	<< '['
				<< 1900 + ltm->tm_year;
	if (1 + ltm->tm_mon >= 0 && 1 + ltm->tm_mon <= 9)
		std::cout	<< '0' << 1 + ltm->tm_mon;
	else
		std::cout	<< 1 + ltm->tm_mon;
	if (ltm->tm_mday >= 0 && ltm->tm_mday <= 0)
		std::cout	<< '0' << ltm->tm_mday;
	else
		std::cout	<< ltm->tm_mday;

	std::cout	<< '_'
				<< 5+ltm->tm_hour
				<< 30+ltm->tm_min
				<< ltm->tm_sec
				<< "] ";
}

void	Account::displayAccountsInfos( void ){

	_displayTimestamp();

	std::cout	<< "accounts:" << getNbAccounts() << ';'
				<< "total:" << getTotalAmount() << ';'
				<< "deposits:" << getNbDeposits() << ';'
				<< "withdrawals:" << getNbWithdrawals()
				<< std::endl;
}

void	Account::makeDeposit( int deposit ){
	this->_nbDeposits++;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ){
	if (withdrawal > this->_amount)
		return (false);
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	return (true);
}

int		Account::checkAmount( void ) const{ // ?
	return 1;
}

void	Account::displayStatus( void ) const{ // ?
	return;
}