#include "Node.h"
#include "Node.cpp"
#include <memory>

int main(void)
{
    std::weak_ptr<Node<int>> start;
    std::weak_ptr<Node<int>> end;
    std::shared_ptr<Node<int>> node(new Node<int>(5));

    start = node;
    end = start;

    std::shared_ptr<Node<int>> nn(new Node<int>(6));
    end.lock()->setNext(nn);
    nn->setPrevious(end);
    end = nn;

    std::shared_ptr<Node<int>> nn2(new Node<int>(7));
    end.lock()->setNext(nn2);
    nn2->setPrevious(end);
    end = nn2;

    PrintForward(start.lock());
    PrintReverse(end.lock());
    return 0;
}