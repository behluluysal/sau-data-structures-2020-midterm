#include "DoublyLinkedList.hpp"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

DoublyLinkedList::DoublyLinkedList(int data)
{
    mid = NULL;
    halfTotal = 0;
}

void DoublyLinkedList::addleft(string vek[], int size, Node *start_ref)
{
    Node *temp = start_ref;
    for (int i = 0; i < size; i++)
    {
        Node *eklenecek = new Node();
        eklenecek->data = stoi(vek[i]);
        eklenecek->next = temp;
        eklenecek->prev = start_ref;
        start_ref->next = eklenecek;
        temp->prev = eklenecek;
        temp = temp->prev;
    }
}

void DoublyLinkedList::addright(string vek[], int size, Node *start_ref)
{
    Node *temp = start_ref;
    while (temp->prev != start_ref)
        temp = temp->prev;
    Node *tmp1 = temp;
    temp = start_ref;
    for (int i = 0; i < size; i++)
    {
        Node *eklenecek = new Node();
        eklenecek->data = stoi(vek[i]);
        eklenecek->prev = temp;
        eklenecek->next = tmp1;
        temp->next = eklenecek;
        temp = temp->next;
        tmp1->prev = eklenecek;
    }
}

void DoublyLinkedList::readtxt(string line)
{
    int temp;
    vector<string> splitted = this->split(line, " ");
    temp = stoi(splitted[0]);
    mid = new Node(temp, NULL, NULL); //ilk node ekleniyor
    vector<string> right;
    vector<string> left;
    halfTotal = splitted.size() / 2;
    for (int i = 1; i <= splitted.size() / 2; i++)
    {
        left.push_back(splitted[i]);
        right.push_back(splitted[splitted.size() - i]);
    }
    reverse(right.begin(), right.end());
    string *leftarr = new string[left.size()];
    string *rightarr = new string[right.size()];
    for (int i = 0; i < left.size(); i++)
        leftarr[i] = left[i];
    for (int i = 0; i < right.size(); i++)
        rightarr[i] = right[i];
    addleft(leftarr, left.size(), mid);
    addright(rightarr, right.size(), mid);
}

DoublyLinkedList::~DoublyLinkedList()
{
}

vector<string> DoublyLinkedList::split(string target, string delim)
{
    vector<string> v;
    if (!target.empty())
    {
        string::size_type start = 0;
        do
        {
            size_t x = target.find(delim, start);
            if (x == string::npos)
                break;

            v.push_back(target.substr(start, x - start));
            start = x + delim.size();
        } while (true);

        v.push_back(target.substr(start));
    }
    return v;
}
