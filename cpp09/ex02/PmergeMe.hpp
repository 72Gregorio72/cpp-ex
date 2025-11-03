#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <climits>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include <sstream>

class PmergeMe{
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe& operator=(const PmergeMe &other);
		bool fillContainer(std::string);
		std::vector<int> getVector();
		std::deque<int> getDeque();
		void printVector();
		void printDeque();
		void sortVector();
		void sortDeque();
		void fordJhonsonVector(std::vector<int> &container);
		void sortContainers();

	private:
		std::vector<int> v;
		std::deque<int> d;

};

#endif