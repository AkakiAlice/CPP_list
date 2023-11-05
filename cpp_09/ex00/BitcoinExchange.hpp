#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <sstream>

#define DATABASE "data.csv"

class BitcoinExchange {
public:
	static void		btcExchange(std::string inputLine);

private:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const & src);
	~BitcoinExchange(void);

	BitcoinExchange&	operator=(BitcoinExchange const & rhs);

	static void			initBtcMap(void);
	static std::string	getDate(void);
	static float		getValue(void);

	static void	parseInputLine(void);
	static void	parseInputDate(void);
	static void	validadeInputDate(void);
	static bool	isValidDate(int year, int month, int day);
	static bool	isLeapYear(int year);
	static void	parseAmount(void);

	static void	calculatePrice(void);

	static void	printBtcInfo(void);
	static int	getPrecision(float n);

	static std::map<std::string, float>	_btcDatabase;
	static std::string	_inputDate;
	static std::string	_inputLine;
	static float		_amount;
	static float		_price;
	static std::string	_databaseLine;
};

#endif
