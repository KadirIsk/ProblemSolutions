#pragma once
#include <memory>
#include "SLinkedList.h"
template <class T>
class SLListReverseWithoutRecursion
{
public:
	static SLinkedList<T> reverseWithoutRecursion(SLinkedList<T>);
};

template<class T>
inline SLinkedList<T> SLListReverseWithoutRecursion<T>::reverseWithoutRecursion(SLinkedList<T> linkedList)
{
	if (linkedList.getSize() > 1) {
		std::shared_ptr<Node<T>> prev = NULL;
		std::shared_ptr<Node<T>> cur = linkedList.getHead();
		std::shared_ptr<Node<T>> next = NULL;

		for (; cur != NULL;) {
			next = cur.get()->getNext();
			cur.get()->setNext(prev);
			prev = cur;
			cur = next;
		}

		auto newHead = linkedList.getTail();
		linkedList.setTail(linkedList.getHead());
		linkedList.setHead(newHead);
	}
	return linkedList;
}
