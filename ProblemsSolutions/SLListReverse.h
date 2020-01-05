// Question: Reverse singly linked list
// Input :	1 -> 2 -> 3
//
// Output:	3 -> 2 -> 1

#pragma once
#include <memory>
#include "SLinkedList.h"
template <class T>
class SLListReverse {
public:
	static SLinkedList<T> reverse(SLinkedList<T>);
	static std::shared_ptr<Node<T>> recursivelyReverse(std::shared_ptr<Node<T>>);
};

template<class T>
inline SLinkedList<T> SLListReverse<T>::reverse(SLinkedList<T> linkedList)
{
	if (linkedList.getHead()) {
		auto newTail = recursivelyReverse(linkedList.getHead());
		(*newTail).setNext(NULL);
		linkedList.setHead(linkedList.getTail());
		linkedList.setTail(newTail);
	}
	return linkedList;
}


template<class T>
inline std::shared_ptr<Node<T>> SLListReverse<T>::recursivelyReverse(std::shared_ptr<Node<T>> current)
{
	if (current) {
		auto prev = recursivelyReverse((*current).getNext());
		if (prev) {
			(*prev).setNext(current);
		}
		return current;
	}
	return NULL;
}
