// Question: Find all permutations of a string
// Input :	xyz
//
// Output:	xyz
//			xzy
//			yxz
//			yzx
//			zxy
//			zyx

#include <string>
#include <list>
#include <iostream>
#include <memory>
#include "StringPermutation.h"

void StringPermutation::findAllPermutation(std::shared_ptr<std::string> str) {
	auto charList = getCharList(str);
	std::shared_ptr<std::string> tmp = std::make_shared<std::string>("");
	recursivelyPrint(charList, tmp);
}

std::list<std::shared_ptr<std::pair<int, char>>> StringPermutation::getCharList(std::shared_ptr<std::string> str) {
	int i = 0;
	std::list<std::shared_ptr<std::pair<int, char>>> charList;
	std::shared_ptr<std::pair<int, char>> pair;
	for (auto it = str->begin(); it != str->end(); it++) {
		pair = std::make_shared<std::pair<int, char>>(i++, *it);
		charList.push_back(pair);
	}
	return charList;
}

void StringPermutation::recursivelyPrint(std::list<std::shared_ptr<std::pair<int, char>>> charSet, std::shared_ptr<std::string> str) {
	if (!charSet.empty()) {
		std::shared_ptr<std::string> concatenation;
		for (auto it = charSet.begin(); it != charSet.end(); it++) {
			concatenation = std::make_shared<std::string>(*str);
			*concatenation += (*it)->second;
			recursivelyPrint(erase((*it)->first, charSet), concatenation);
		}
	}
	else {
		std::cout << *str << std::endl;
	}
}

std::list<std::shared_ptr<std::pair<int, char>>> StringPermutation::erase(int index, std::list<std::shared_ptr<std::pair<int, char>>> charSet) {
	if (!charSet.empty()) {
		auto copyCharSet(charSet);
		for (auto it = copyCharSet.begin(); it != copyCharSet.end();) {
			if ((*it)->first == index) {
				copyCharSet.erase(it++);
				break;
			}
			it++;
		}
		return copyCharSet;
	}
	return std::list<std::shared_ptr<std::pair<int, char>>>();
}