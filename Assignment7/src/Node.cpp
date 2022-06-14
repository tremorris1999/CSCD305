#include "Node.h"

template <class T>
T Node<T>::getValue()
{
	return Value;
}

template <class T>
shared_ptr<Node<T>> Node<T>::getNext()
{
	return next;
}

template <class T>
void Node<T>::setNext(shared_ptr<Node<T>> nextPtr)
{
	next = nextPtr;
}

template <class T>
weak_ptr<Node<T>> Node<T>::getPrevious()
{
	return prev;
}

template <class T>
void Node<T>::setPrevious(weak_ptr<Node<T>> prevPtr)
{
	prev = prevPtr;
}


template<typename T>
void PrintForward(shared_ptr<Node<T>> start) {
	shared_ptr<Node<T>> temp = start;

	while (temp) {

		cout << temp->getValue() << "-> ";
		temp = temp->getNext();
	}
	cout << endl;
}
template<typename T>
void PrintReverse(shared_ptr<Node<T>> end) {

	shared_ptr<Node<T>> temp = end;
	while (temp) {
		cout << "<-" << temp->getValue() << " ";
		temp = temp->getPrevious().lock();
	}
	cout << endl;
}

// deleteList no longer needed.