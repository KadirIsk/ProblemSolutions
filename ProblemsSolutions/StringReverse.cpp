// Question: Reverse a String using by RECURSION
// Input :	xyz
//
// Output:	zyx

#include "StringReverse.h"

std::shared_ptr<std::string> StringReverse::reverse(std::shared_ptr<std::string> str)
{
	if (str) {
		return reverseRecursiverly(str, 0);
	}
	return std::make_shared<std::string>("");
}

std::shared_ptr<std::string> StringReverse::reverseRecursiverly(std::shared_ptr<std::string> str, int ind) {
	if ((*str).length() != ind) {
		return std::make_shared<std::string>(*reverseRecursiverly(str, (ind + 1)) + (*str).at(ind));
	}
	return std::make_shared<std::string>("");
}