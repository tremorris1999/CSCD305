#include "Node.h"
#include "Node.cpp"

void createDoublyLinkedList();

int main() {

	createDoublyLinkedList();

	return 0;
}

void createDoublyLinkedList() {
	std::weak_ptr<Node<int>> start;
	std::weak_ptr<Node<int>> end;
	std::shared_ptr<Node<int>> nd(new Node<int>(1));

	start = nd;
	end = start;

	std::shared_ptr<Node<int>> nd1(new Node<int>(2));

	nd1->setPrevious(end);
	end.lock()->setNext(nd1);
	end = nd1;

	std::shared_ptr<Node<int>> nd2(new Node<int>(3));

	nd2->setPrevious(end);
	end.lock()->setNext(nd2);
	end = nd2;

	PrintForward(start.lock());
	PrintReverse(end.lock());

	//deleteList(start); No longer needed.


}