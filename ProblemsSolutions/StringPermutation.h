#pragma once
#include <list>
#include <utility>
class StringPermutation
{
public:
	static void findAllPermutation(std::string*);
	static std::list<std::pair<int, char>*> getCharList(std::string*);
	static void recursivelyPrint(std::list<std::pair<int, char>*>, std::string*);
	static std::list<std::pair<int, char>*> erase(int, std::list<std::pair<int, char>*>);
};

