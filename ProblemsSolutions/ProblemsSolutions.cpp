#include <iostream>
#include <memory>
#include "QuestionTag.h"
#include "StringPermutation.h"
#include "StringReverse.h"

int main()
{
    QUESTIONTAG questionTag = QUESTIONTAG::STRINGREVERSE;
	switch (questionTag)
	{
	case QUESTIONTAG::STRINGPERMUTATION:
	{
		std::shared_ptr<std::string> str(std::make_shared<std::string>("XYZ"));
		StringPermutation::findAllPermutation(str);
	}
	break;
	case QUESTIONTAG::STRINGREVERSE:
	{
		std::shared_ptr<std::string> str(std::make_shared<std::string>("XYZ"));
		str = StringReverse::reverse(str);
		std::cout << *str << std::endl;
	}
	break;
	default:
		break;
	}
}
