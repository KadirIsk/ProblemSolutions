#include <iostream>
#include <memory>
#include <string>
#include "QuestionTag.h"
#include "StringPermutation.h"
#include "StringReverse.h"
#include "SLinkedList.h"
#include "SLListReverse.h"

int main()
{
    QUESTIONTAG questionTag = QUESTIONTAG::SINGLYLLISTREVERSE;
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
	case QUESTIONTAG::SINGLYLLISTREVERSE:
	{
		std::shared_ptr<SLinkedList<int>> slinkedList = std::make_shared<SLinkedList<int>>();
		std::shared_ptr<Node<int>> node;
		for (int i = 0; i < 10; i++) {
			node = std::make_shared<Node<int>>(Node<int>(i + 1));
			slinkedList->addNode(node);
		}
		std::cout << "SINGLY LINKED LIST   : ";
		slinkedList->printList();
		std::cout << std::endl << "REVERSED LINKED LIST :";
		*slinkedList = SLListReverse<int>::reverse(*slinkedList);
		slinkedList->printList();
	}
	break;
	default:
		break;
	}
}
