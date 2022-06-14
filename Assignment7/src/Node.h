#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <memory>

using namespace std;

template <typename T>
class Node {
private:
	T Value;
	weak_ptr<Node<T>> prev;
	shared_ptr<Node<T>> next;
public:
	Node<T>(T val) : Value(val) {}
	~Node<T>() {
		cout << "Deleting node with a value " << Value << endl;
	}
	T getValue();
	void setValue(T val) { Value = val; }
	shared_ptr<Node<T>> getNext();
	weak_ptr<Node<T>> getPrevious();
	void setNext(shared_ptr<Node<T>> nextPtr);
	void setPrevious(weak_ptr<Node<T>> previousPtr);
};

#endif
