#ifndef DoublyLinkedList_hpp
#define DoublyLinkedList_hpp

#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
class DoublyLinkedList
{
public:
    DoublyLinkedList(int data);
    ~DoublyLinkedList();
    void addleft(string vek[], int size, Node *start_ref);
    void addright(string vek[], int size, Node *start_ref);
    void readtxt(string line);
    long halfTotal;
    vector<string> split(string target, string delim);
    void bubbleSort(Node *start);
    Node *mid;
};

#endif