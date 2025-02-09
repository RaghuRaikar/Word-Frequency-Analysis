#ifndef LIST_H
#define LIST_H

#include <string>

using namespace std;

struct Node
{
  string word;
  int frequency;
  Node *next;
};

class LinkedList
{
  private:
    Node *head;
  public:
    LinkedList();
    Node* returnhead();
    void insert(string, int);
    string find(int);
    void sortcaller();
    Node* find(string);
    Node* deleteNode(string);
    void deleteAndFreeNode(string);
    void deleteList();
    string print();
    int length();
    void sort(Node**);
    void split_linked_list(Node*,Node**,Node**);
    Node* list_combine(Node*, Node*);
};

#endif