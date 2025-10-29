#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange {
	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);

		void setBitCoinValues(std::string filename);
		std::map<std::string, double> getBitCoinValues();
		
		class BadDateException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Bad date format";
				}
		};

		class BadValueException : public std::exception {
			public:
				virtual const char* what() const throw() {
					return "Bad value";
				}
		};
	private:
		std::map<std::string, double> bitCoinValues;
		std::map<std::string, double> prices;
		void fillBitCoinData(std::ifstream& bitCoinData);
		bool checkDate(std::string date);
		bool checkBitCoinsValue(std::string valueStr);
};

#endif