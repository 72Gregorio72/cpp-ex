#include "PmergeMe.hpp"
#include <sstream>
#include <iostream>
#include <cctype>
#include <climits>
#include <string>
#include <sys/time.h>
#include <stdexcept>

PmergeMe::PmergeMe() : v(), d() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other){
	v = other.v;
	d = other.d;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other){
	if (this == &other)
		return *this;
	v = other.v;
	d = other.d;
	return *this;
}

bool PmergeMe::fillContainer(std::string s) {
	std::istringstream ss(s);
	std::string token;

	while (ss >> token) {
		for (size_t i = 0; i < token.size(); i++) {
			if (!std::isdigit(static_cast<unsigned char>(token[i]))) {
				std::cout << "Error: " << token << " is not a valid number\n";
				return false;
			}
		}

		long value;
		try {
			value = std::atof(token.c_str());
		} catch (const std::exception&) {
			std::cout << "Error: invalid number '" << token << "'\n";
			return false;
		}

		if (value < 0 || value > INT_MAX) {
			std::cout << "Error: out of range value '" << token << "'\n";
			return false;
		}

		v.push_back(static_cast<int>(value));
		d.push_back(static_cast<int>(value));
	}

	if (v.empty() || d.empty()) {
		std::cerr << "Error: no numbers found\n";
		return false;
	}

	return true;
}

std::deque<int> PmergeMe::getDeque(){
	return d;
}

std::vector<int> PmergeMe::getVector(){
	return v;
}

std::vector<size_t> jacobsthalSequence(size_t n) {
	std::vector<size_t> seq;

	if (n == 0)
		return seq;
	if (n == 1) {
		seq.push_back(1);
		return seq;
	}

	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (true) {
		size_t next = jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2];
		if (next > n)
			break;
		jacob.push_back(next);
	}

	std::vector<size_t> order;
	size_t prev = 1;
	for (size_t i = 2; i < jacob.size(); ++i) {
		size_t j = jacob[i];
		for (size_t k = j; k > prev; --k)
			order.push_back(k);
		prev = j;
	}

	for (size_t i = 1; i <= n; ++i) {
		if (std::find(order.begin(), order.end(), i) == order.end())
			order.push_back(i);
	}

	return order;
}

void PmergeMe::sortContainers(){
    struct timeval start_v, end_v;
    struct timeval start_d, end_d;

    gettimeofday(&start_v, NULL); 
    
    std::vector<std::pair<int, int> > pairs_v;
    fordJhonsonVector(v, pairs_v);
    
    gettimeofday(&end_v, NULL); 
    gettimeofday(&start_d, NULL);
    
    std::deque<std::pair<int, int> > pairs_d;
    fordJhonsonDeque(d, pairs_d);
    
    gettimeofday(&end_d, NULL);
    long duration_v = (end_v.tv_sec - start_v.tv_sec) * 1000000L + (end_v.tv_usec - start_v.tv_usec);
    long duration_d = (end_d.tv_sec - start_d.tv_sec) * 1000000L + (end_d.tv_usec - start_d.tv_usec);

	std::cout << "After:   ";
	printVector();
    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " 
              << duration_v << " us" << std::endl;
    std::cout << "Time to process a range of " << d.size() << " elements with std::deque : " 
              << duration_d << " us" << std::endl;
}

void PmergeMe::fordJhonsonVector(std::vector<int> &container, std::vector<std::pair<int, int> > pairs){
	
	std::vector<std::pair<int, int> > empty;
	
	if (container.size() <= 1)
		return ;

	if (!pairs.empty())
		empty = pairs;

	pairs.clear();

	for(size_t i = 0; i + 1 < container.size(); i += 2){
		int a = container[i], b = container[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	bool hasOdd = (container.size() % 2);
	int leftover = 0;
	if (hasOdd) leftover = container.back();

	std::vector<int> mainChain;
	std::vector<int> pendingChain;

	for(size_t i = 0; i < pairs.size(); i++){
		mainChain.push_back(pairs[i].first);
		pendingChain.push_back(pairs[i].second);
	}

	fordJhonsonVector(mainChain, pairs);
	std::vector<int> newPending;
	newPending.reserve(mainChain.size());
	std::vector<int> firstValues;
	firstValues.reserve(mainChain.size());

	for (size_t i = 0; i < mainChain.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (mainChain[i] == pairs[j].first) {
				newPending.push_back(pairs[j].second);
				firstValues.push_back(pairs[j].first);
				break;
			}
		}
	}

	pendingChain = newPending;

	std::vector<size_t> js = jacobsthalSequence(pendingChain.size());

	for (size_t i = 0; i < js.size(); i++){
		size_t id = js[i] - 1;
		if (id >= pendingChain.size())
			continue;
		std::vector<int>::iterator itStart = std::find(mainChain.begin(), mainChain.end(), firstValues[id]);
		if (itStart == mainChain.end())
			itStart = mainChain.begin();
		std::vector<int>::iterator pos = std::lower_bound(itStart, mainChain.end(), pendingChain[id]);
		mainChain.insert(pos, pendingChain[id]);
	}

	if (hasOdd) {
		std::vector<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	container = mainChain;
}

void PmergeMe::fordJhonsonDeque(std::deque<int> &container, std::deque<std::pair<int, int> > pairs){
	
	std::deque<std::pair<int, int> > empty;
	
	if (container.size() <= 1)
		return ;

	if (!pairs.empty())
		empty = pairs;

	pairs.clear();

	for(size_t i = 0; i + 1 < container.size(); i += 2){
		int a = container[i], b = container[i + 1];
		if (a > b)
			std::swap(a, b);
		pairs.push_back(std::make_pair(a, b));
	}

	bool hasOdd = (container.size() % 2);
	int leftover = 0;
	if (hasOdd) leftover = container.back();

	std::deque<int> mainChain;
	std::deque<int> pendingChain;

	for(size_t i = 0; i < pairs.size(); i++){
		mainChain.push_back(pairs[i].first);
		pendingChain.push_back(pairs[i].second);
	}

	fordJhonsonDeque(mainChain, pairs);
	std::deque<int> newPending;
	std::deque<int> firstValues;

	for (size_t i = 0; i < mainChain.size(); ++i) {
		for (size_t j = 0; j < pairs.size(); ++j) {
			if (mainChain[i] == pairs[j].first) {
				newPending.push_back(pairs[j].second);
				firstValues.push_back(pairs[j].first);
				break;
			}
		}
	}

	pendingChain = newPending;

	std::vector<size_t> js = jacobsthalSequence(pendingChain.size());

	for (size_t i = 0; i < js.size(); i++){
		size_t id = js[i] - 1;
		if (id >= pendingChain.size())
			continue;
		std::deque<int>::iterator itStart = std::find(mainChain.begin(), mainChain.end(), firstValues[id]);
		if (itStart == mainChain.end())
			itStart = mainChain.begin();
		std::deque<int>::iterator pos = std::lower_bound(itStart, mainChain.end(), pendingChain[id]);
		mainChain.insert(pos, pendingChain[id]);
	}

	if (hasOdd) {
		std::deque<int>::iterator pos = std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
		mainChain.insert(pos, leftover);
	}

	container = mainChain;
}

void PmergeMe::printVector(){
	for (size_t i = 0; i < v.size(); i++){
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(){
	for (size_t i = 0; i < d.size(); i++){
		std::cout << d[i] << " ";
	}
	std::cout << std::endl;
}

