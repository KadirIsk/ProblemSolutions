#pragma once
#include <memory>
#include <iostream>
#include "Node.h"
template <class T>
class SLinkedList
{
private:
	int count;
	std::shared_ptr<Node<T>> head;
	std::shared_ptr<Node<T>> tail;
	
public:
	SLinkedList() { this->count = 0; }
	int getCount() { return this->count; }
	std::shared_ptr<Node<T>> getHead() { return this->head; }
	void setHead(std::shared_ptr<Node<T>> head) { this->head = head; }
	std::shared_ptr<Node<T>> getTail() { return this->tail; }
	void setTail(std::shared_ptr<Node<T>> tail) { this->tail = tail; }
	bool deleteNode(std::shared_ptr<Node<T>>);
	std::shared_ptr<Node<T>> deleteNode(int);
	bool addNode(std::shared_ptr<Node<T>>);
	bool addNode(std::shared_ptr<Node<T>>, int);
	void printList();
};

template<class T>
bool SLinkedList<T>::addNode(std::shared_ptr<Node<T>> node)
{
	if (head) {
		tail.get()->setNext(node);
	}
	else {
		head = node;
	}
	tail = node;
	count++;
	return true;
}

template<class T>
bool SLinkedList<T>::addNode(std::shared_ptr<Node<T>> node, int index)
{
	if (index >= 0 && index <= count) {
		if (index == 0) {
			if (count == 0) {
				head = node;
				tail = node;
			}
			else {
				node.get()->setNext(head);
				head = node;
			}
			count++;
			return true;
		}

		if (index == count) {
			tail.get()->setNext(node);
			tail = node;
			count++;
			return true;
		}

		auto ptrHead = head;
		for (int i = 0; i < index; i++)	ptrHead = ptrHead.get()->getNext();
		node.get()->setNext(head.get()->getNext());
		head.get()->setNext(node);
		count++;
		return true;
	}
	return false;
}

template<class T>
bool SLinkedList<T>::deleteNode(std::shared_ptr<Node<T>> node)
{
	auto toBeDeleted = head;
	auto isDeleted = false;
	for (int i = 0; toBeDeleted && toBeDeleted.get()->getNext() != tail; toBeDeleted = toBeDeleted.get()->getNext(), i++) {
		if (*toBeDeleted == *node) {
			deleteNode(i);
			isDeleted = true;
		}
	}
	if (toBeDeleted) {
		if (toBeDeleted.get()->getNext() == node) {
			deleteNode(count - 1);
			isDeleted = true;
		}
	}
	return isDeleted;
}

template<class T>
inline std::shared_ptr<Node<T>> SLinkedList<T>::deleteNode(int index)
{
	if (index >= 0 && index < count) {
		if (index == 0) {
			if (count > 0) {
				auto removed = head;
				head = head.get()->getNext();
				count--;
				return head;
			}
		}
		if (index == count - 1) {
			auto toBeDeleted = head;
			auto removed = tail;
			for (; toBeDeleted.get()->getNext() != tail; toBeDeleted = toBeDeleted.get()->getNext());
			toBeDeleted.get()->setNext(NULL);
			tail = toBeDeleted;
			count--;
			return removed;
		}
		
		auto toBeRemoved = head;
		for (int i = 0; i < index - 1; i++) toBeRemoved = toBeRemoved.get()->getNext();
		auto removed = toBeRemoved.get()->getNext();
		toBeRemoved.get()->setNext(removed.get()->getNext());
		return removed;
	}
	return std::make_shared<Node<T>>(Node<T>());
}


template<class T>
inline void SLinkedList<T>::printList()
{
	for (auto it = head; it != NULL; it = (*it).getNext()) {
		(*it).printValue();
		std::cout << ((*it).getNext() == NULL ? "" : ", ");
	}
}
