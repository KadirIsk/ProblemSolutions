#include <iostream>
#include "QuestionTag.h"
#include "StringPermutation.h"

int main()
{
    QUESTIONTAG questionTag = QUESTIONTAG::STRINGPERMUTATION;
	switch (questionTag)
	{
	case QUESTIONTAG::STRINGPERMUTATION:
		{
			std::string* str = new std::string("XYZ");
			StringPermutation::findAllPermutation(str);
		}
		break;
	default:
		break;
	}
}
