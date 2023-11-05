#include <iostream>
#include <fstream>
#include <stdexcept>
#include "BitcoinExchange.hpp"

void	checkFile(char const * file) {
	std::ifstream	in;

	in.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	in.open(file, std::ifstream::in);
	in.close();
}

void	checkArg(int argc, char const * fileName) {
	if (argc != 2)
		throw std::invalid_argument("invalid number of arguments");
	checkFile(fileName);
}

void	checkHeader(std::string const & firstLine) {
	if (firstLine != "date | value")
		throw std::runtime_error("invalid header");
}

void	exchange(char const * inputFile) {
	std::ifstream	in;
	std::string		line;

	in.open(inputFile, std::ifstream::in);
	getline(in, line);
	checkHeader(line);
	while (!in.eof()) {
		getline(in, line);
		if (!line.empty()) {
			try {
				BitcoinExchange::btcExchange(line);
			} catch(std::exception & e) {
				std::cout << "Error: " << e.what() << " => " << line << std::endl;
			}
		}
	}
	in.close();
}

int	main(int argc, char **argv) {
	try {
		checkArg(argc, argv[1]);
		exchange(argv[1]);
	} catch(std::exception & e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
}
