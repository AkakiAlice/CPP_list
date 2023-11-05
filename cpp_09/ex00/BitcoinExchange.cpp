#include "BitcoinExchange.hpp"

std::map<std::string, float>	BitcoinExchange::_btcDatabase;
std::string	BitcoinExchange::_inputDate;
std::string	BitcoinExchange::_inputLine;
float		BitcoinExchange::_amount;
float		BitcoinExchange::_price;
std::string	BitcoinExchange::_databaseLine;

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
	*this = src;
}

BitcoinExchange::~BitcoinExchange(void) {}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const & rhs) {
	(void)rhs;
	return *this;
}

void	BitcoinExchange::btcExchange(std::string inputLine) {
	_inputLine = inputLine;
	initBtcMap();
	parseInputLine();
	calculatePrice();
	printBtcInfo();
}

/*----------------------------INIT_BTC_MAP------------------------------------*/

void	BitcoinExchange::initBtcMap(void) {
	std::ifstream	in;

	in.open(DATABASE, std::ifstream::in);
	getline(in, _databaseLine);
	while (!in.eof()) {
		getline(in, _databaseLine);
		_btcDatabase.insert(std::pair<std::string, float>(getDate(), getValue()));
	}
	in.close();
}

std::string	BitcoinExchange::getDate(void) {
	size_t pos = _databaseLine.find(",");
	return _databaseLine.substr(0, pos);
}

float	BitcoinExchange::getValue(void) {
	int		aux;
	float	value;

	sscanf(_databaseLine.c_str(), "%d-%d-%d,%f", &aux, &aux, &aux, &value);
	return value;
}

/*----------------------------PARSE_INPUT_LINE--------------------------------*/

void	BitcoinExchange::parseInputLine(void) {
	parseInputDate();
	validadeInputDate();
	parseAmount();
}

void	BitcoinExchange::parseInputDate(void) {
	size_t pos = _inputLine.find(" | ");
	if (pos == std::string::npos)
		throw std::runtime_error("bad input");
	_inputDate = _inputLine.substr(0, pos);
}

void	BitcoinExchange::validadeInputDate(void) {
	int	year, month, day;

	if (sscanf(_inputDate.c_str(), "%d-%d-%d", &year, &month, &day) != 3)
		throw std::runtime_error("bad input");
	if (!isValidDate(year, month, day))
		throw std::runtime_error("invalid date");
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
	int daysInMonths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year < 1 || year > 9999 || month < 1 || month > 12 || day < 1)
		return false;
	if (isLeapYear(year))
		daysInMonths[2] = 29;
	if (day > daysInMonths[month])
		return false;
	return true;
}

bool BitcoinExchange::isLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

void	BitcoinExchange::parseAmount(void) {
	int	aux;

	if (sscanf(_inputLine.c_str(), "%d-%d-%d | %f", &aux, &aux, &aux, &_amount) != 4)
		throw std::runtime_error("bad input");
	if (_amount < 0 || _amount > 1000)
		throw std::runtime_error("input out of range");
}


/*--------------------------CALCULATE_PRICE-----------------------------------*/

void	BitcoinExchange::calculatePrice(void) {
	std::map<std::string, float>::iterator it = _btcDatabase.lower_bound(_inputDate);

	if (it->first != _inputDate)
		--it;
	_price = _btcDatabase[it->first] * _amount;
}


/*--------------------------PRINT_BTC_INFO------------------------------------*/

void	BitcoinExchange::printBtcInfo(void) {
	std::cout << _inputDate << " => ";
	std::cout << std::fixed << std::setprecision(getPrecision(_amount));
	std::cout << _amount << " = ";
	std::cout << std::fixed << std::setprecision(2);
	std::cout << _price << std::endl;
}

int	BitcoinExchange::getPrecision(float number) {
	std::ostringstream stream;
	stream << number;
	std::string numStr = stream.str();
	size_t decimalPoint = numStr.find('.');

	if (decimalPoint != std::string::npos)
		return numStr.size() - decimalPoint - 1;
	return 0;
}
