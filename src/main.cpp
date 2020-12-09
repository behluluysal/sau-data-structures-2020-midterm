// veri_part1.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <fstream>
#include <vector>
#include "DoublyLinkedList.hpp"
#include "Node.hpp"

using namespace std;

long getLineCount();
void swapper(DoublyLinkedList *min, DoublyLinkedList *max);
void reverse(Node **head_ref);

int main()
{
    long line_count = 0;
    DoublyLinkedList *max;
    DoublyLinkedList *min;

    line_count = getLineCount(); // satır sayısı alındı
    DoublyLinkedList **dyn_arr = new DoublyLinkedList *[line_count];
    fstream newfile;
    newfile.open("sayilar.txt", ios::in);
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        int sayac = 0;
        while (getline(newfile, tp))
        { //read data from file object and put it into string.
            DoublyLinkedList *n = new DoublyLinkedList(5);
            n->readtxt(tp);
            dyn_arr[sayac++] = n;
        }
        newfile.close(); //close the file object.
    }
    max = dyn_arr[0]; //ilk deger set
    min = dyn_arr[0]; //ilk deger set

    for (int i = 0; i < line_count; i++) //sırala
    {
        if (max->mid->data < dyn_arr[i]->mid->data) //max set
        {
            max = dyn_arr[i];
        }
        if (min->mid->data > dyn_arr[i]->mid->data) //min set
        {
            min = dyn_arr[i];
        }
    }
    swapper(min, max);

    cout << "En Buyuk Liste Orta Dugum Adres: " << max->mid << endl;
    cout << "En Buyuk Liste Degerler\n";
    Node *temp = max->mid;
    for (int i = 0; i < max->halfTotal; i++)
    {
        temp = temp->prev;
    }
    for (int i = 0; i <= max->halfTotal * 2; i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n\nEn Kucuk Liste Orta Dugum Adres: " << max->mid << endl;
    cout << "En Kucuk Liste Degerler\n";
    temp = min->mid;
    for (int i = 0; i < min->halfTotal; i++)
    {
        temp = temp->prev;
    }
    for (int i = 0; i <= min->halfTotal * 2; i++)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    //free memory
    for (int i = 0; i < line_count; i++)
    {
        Node *next = dyn_arr[i]->mid;

        for (int j = 0; j <= dyn_arr[i]->halfTotal * 2; j++)
        {
            Node *node = next;
            next = node->next;
            node->~Node();
        }
        free(dyn_arr[i]);
    }
}

long getLineCount()
{
    long line_count = 0;
    fstream newfile;
    newfile.open("sayilar.txt", ios::in);
    if (newfile.is_open())
    { //checking whether the file is open
        string tp;
        while (getline(newfile, tp))
        { //read data from file object and put it into string.
            line_count++;
        }
        newfile.close(); //close the file object.
    }
    return line_count;
}

void swapper(DoublyLinkedList *min, DoublyLinkedList *max)
{
    Node *minendLeft = min->mid->prev;
    Node *minstartLeft = min->mid;

    Node *minstartRight = min->mid->next;
    Node *minendRight = min->mid;
    for (int i = 0; i < min->halfTotal; i++)
    {
        minstartLeft = minstartLeft->prev;
        minendRight = minendRight->next;
    }

    //-------------------------------------
    Node *maxendLeft = max->mid->prev;
    Node *maxstartLeft = max->mid;

    Node *maxstartRight = max->mid->next;
    Node *maxendRight = max->mid;
    for (int i = 0; i < max->halfTotal; i++)
    {
        maxstartLeft = maxstartLeft->prev;
        maxendRight = maxendRight->next;
    }

    minstartLeft->prev = NULL;
    minendLeft->next = NULL;
    minendRight->next = NULL;
    minstartRight->prev = NULL;

    maxstartLeft->prev = NULL;
    maxendLeft->next = NULL;
    maxendRight->next = NULL;
    maxstartRight->prev = NULL;

    reverse(&minstartRight);
    reverse(&minstartLeft);

    reverse(&maxstartRight);
    reverse(&maxstartLeft);

    maxendRight = maxstartRight;
    maxendLeft = maxstartLeft;
    for (int i = 1; i < max->halfTotal; i++)
    {
        maxendRight = maxendRight->next;
        maxendLeft = maxendLeft->next;
    }

    minendRight = minstartRight;
    minendLeft = minstartLeft;
    for (int i = 1; i < min->halfTotal; i++)
    {
        minendRight = minendRight->next;
        minendLeft = minendLeft->next;
    }
    min->mid->next = maxstartLeft;
    min->mid->prev = maxendRight;
    maxendRight->next = min->mid;
    maxstartLeft->prev = min->mid;
    maxstartRight->prev = maxendLeft;
    maxendLeft->next = maxstartRight;

    max->mid->next = minstartLeft;
    max->mid->prev = minendRight;
    minendRight->next = max->mid;
    minstartLeft->prev = max->mid;
    minstartRight->prev = minendLeft;
    minendLeft->next = minstartRight;
    long temp = max->halfTotal;
    max->halfTotal = min->halfTotal;
    min->halfTotal = temp;
}

void reverse(Node **head_ref)
{
    Node *temp = NULL;
    Node *current = *head_ref;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
        *head_ref = temp->prev;
}