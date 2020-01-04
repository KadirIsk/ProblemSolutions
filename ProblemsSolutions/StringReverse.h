#pragma once
#include <string>
#include <memory>
class StringReverse
{
public:
	static std::shared_ptr<std::string> reverse(std::shared_ptr<std::string>);
	static std::shared_ptr<std::string> reverseRecursiverly(std::shared_ptr<std::string>, int);
};

