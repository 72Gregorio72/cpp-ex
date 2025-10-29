#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() : bitCoinValues(), prices() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	this->bitCoinValues = other.bitCoinValues;
	this->prices = other.prices;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		this->bitCoinValues = other.bitCoinValues;
		this->prices = other.prices;
	}
	return *this;
}

void BitcoinExchange::setBitCoinValues(std::string filename){
	std::ifstream bitCoinData(filename.c_str());

	if (bitCoinData.is_open()){
		fillBitCoinData(bitCoinData);
		bitCoinData.close();
	} else {
		std::cout << "File not found!" << std::endl;
	}
}

std::map<std::string, double> BitcoinExchange::getBitCoinValues(){
	return bitCoinValues;
}

bool BitcoinExchange::checkDate(std::string date){
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}

	int year, month, day;
	std::stringstream ss(date);
	char dash1, dash2;
	
	if (!(ss >> year >> dash1 >> month >> dash2 >> day))
		return false;
	
	if (month < 1 || month > 12)
		return false;
	
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
	if (isLeapYear)
		daysInMonth[1] = 29;
	
	if (day < 1 || day > daysInMonth[month - 1])
		return false;
	return true;
}

bool BitcoinExchange::checkBitCoinsValue(std::string valueStr){
	
	if (valueStr.empty())
		return false;
	
	size_t start = 0;
	if (valueStr[0] == '-' || valueStr[0] == '+')
		start = 1;
	
	if (start >= valueStr.length())
		return false;
	
	bool hasDecimal = false;
	bool hasDigit = false;
	
	for (size_t i = start; i < valueStr.length(); i++) {
		if (valueStr[i] == '.') {
			if (hasDecimal)
				return false;
			hasDecimal = true;
		} else if (std::isdigit(valueStr[i])) {
			hasDigit = true;
		} else {
			return false;
		}
	}
	
	if (!hasDigit)
		return false;
	
	double value;
	std::stringstream ss(valueStr);
	if (!(ss >> value) || !ss.eof())
		return false;
	
	if (value < 0)
		return false;
	return true;
}

void BitcoinExchange::fillBitCoinData(std::ifstream &bitCoinData){
	std::string row;
	std::string date;
	std::string valueStr;
	double value;

	std::getline(bitCoinData, row); 

	while (std::getline(bitCoinData, row)){
		std::stringstream ss(row);
		if (std::getline(ss, date, ',')) {
			if (!checkDate(date)) {
				std::cerr << "Errore: Data non valida nella riga: " << row << std::endl;
				throw BadDateException();
			}
			if (std::getline(ss, valueStr)) {
				size_t start = valueStr.find_first_not_of(" \t");
				if (start != std::string::npos) {
					valueStr = valueStr.substr(start);
				}
				
				if (!checkBitCoinsValue(valueStr)) {
					std::cerr << "Errore: Valore non valido nella riga: " << row << std::endl;
					throw BadValueException();
				}
				std::stringstream valueSs(valueStr);
				valueSs >> value;
				this->bitCoinValues[date] = value;
			} else {
				std::cerr << "Errore: Riga dati incompleta (manca il valore): " << row << std::endl;
			}
		} else {
			 std::cerr << "Errore: Riga dati incompleta (manca la data): " << row << std::endl;
		}
	}
}
