#include <iostream>
#include "Node.hpp"
using namespace std;

Node::Node(int data, Node *prevnew, Node *nextnew)
{
    if (prevnew == NULL) //ilk node
    {
        this->data = data;
        this->prev = this;
        this->next = this;
    }
}
int Node::getData()
{
    return data;
}

Node::Node()
{
    prev = NULL;
    next = NULL;
    data = 10;
}

Node::~Node()
{
    free(this);
}
