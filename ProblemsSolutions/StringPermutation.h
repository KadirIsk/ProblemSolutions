#pragma once
#include <list>
#include <utility>
#include <memory>
class StringPermutation
{
public:
	static void findAllPermutation(std::shared_ptr<std::string>);
	static std::list<std::shared_ptr<std::pair<int, char>>> getCharList(std::shared_ptr<std::string>);
	static void recursivelyPrint(std::list<std::shared_ptr<std::pair<int, char>>>, std::shared_ptr<std::string>);
	static std::list<std::shared_ptr<std::pair<int, char>>> erase(int, std::list<std::shared_ptr<std::pair<int, char>>>);
};

