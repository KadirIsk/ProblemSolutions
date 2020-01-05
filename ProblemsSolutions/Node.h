#pragma once
#include <memory>
#include <iostream>
template<class T>
class Node
{
private:
	std::shared_ptr<T> value;
	std::shared_ptr<Node<T>> next;
	std::shared_ptr<Node<T>> prev;

public:
	Node(){}
	Node(T val) { this->value = std::make_shared<T>(val); }
	void setNext(std::shared_ptr<Node<T>> next) { this->next = next; }
	void setPrev(std::shared_ptr<Node<T>> prev) { this->prev = prev; }
	void setValue(std::shared_ptr<T> value) { this->value = value; }
	void setValue(T val) { this->value = std::make_shared<T>(val); }
	std::shared_ptr<Node<T>> getNext() { return this->next; }
	std::shared_ptr<Node<T>> getPrev() { return this->prev; }
	std::shared_ptr<T> getValue() { return this->value; }
	void printValue() {
		if(value)	std::cout << *value;
	}

	inline bool operator== (const Node<T>& other) {
		return *this->value.get() == *other.value.get();
	}
};