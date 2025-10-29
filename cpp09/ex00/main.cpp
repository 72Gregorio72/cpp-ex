#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: " << av[0] << " <input_file>" << std::endl;
		return 1;
	}

	BitcoinExchange bitcoinExchange;
	try {
		bitcoinExchange.setBitCoinValues("data.csv");
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	std::map<std::string, double> bitcoinValues = bitcoinExchange.getBitCoinValues();
	for (std::map<std::string, double>::const_iterator it = bitcoinValues.begin(); 
		it != bitcoinValues.end(); ++it) {
		std::cout << it->first << " => " << it->second << std::endl;
	}

	return 0;
}