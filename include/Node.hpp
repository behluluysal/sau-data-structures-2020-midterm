#ifndef Node_hpp
#define Node_hpp

#pragma once
#include "iostream"
class Node
{
public:
    Node();
    Node(int data, Node *prevnew, Node *nextnew);
    int getData();
    ~Node();
    Node *next;
    Node *prev;
    int data;
};

#endif