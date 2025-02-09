#include "linkedlist.h"
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Default constructor - sets both head and tail to null.
LinkedList :: LinkedList()
{
  head = NULL;
}

// Returns head of linked list.
Node* LinkedList :: returnhead()
{
  return head;
}

/* Insert function - inserts a new node at head of list with
  specified word and frequency. */
void LinkedList :: insert(string w, int freq)
{
  Node *to_add = new Node;
  to_add->word = w;
  to_add->frequency = freq;
  to_add->next = head;
  head = to_add;
}

/* Find function - used to find the nth occurance of a word 
  of specified length. Returns "-" if not found. */
string LinkedList :: find(int occurance)
{
  Node *h1 = head;
  int counter = 0;
  while(h1!=NULL)
  {
    if(occurance == 0)
    {
      return h1->word;
    }
    if(counter == occurance)
    {
      return h1->word;
    }
    h1 = h1->next;
    counter++;
  }
  return "-";
}

/* Find function - checks if given word exists and returns
  node if found, otherwise, returns NULL. */
Node* LinkedList :: find(string word)
{
  Node *curr = head;
  while(curr!=NULL)
  {
    if(curr->word == word)
    {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

/* Helper function - calls sort function with head of linked
  linked list as arguement. */
void LinkedList :: sortcaller()
{
  this->sort(&head);
}

//sorting algorithm: MERGE SORT

/* sort function - This function sorts the linked list */
void LinkedList :: sort(Node** beginning)
{
  Node *h = *beginning; // head pointer for linked list.
  Node *first_half = NULL; // Pointer to represent first half of linked list.
  Node *second_half = NULL; // Pointer to represent second half of linked list.

  if(h == NULL || h->next == NULL) /* This is our exit case for our function. 
                                      If length is 0 or 1 we have nothing to sort. */
  {
    return;
  }

  split_linked_list(h, &first_half, &second_half); /* call to our split_linked_list function
                                                      which splits the list into two. */
  sort(&first_half); // Here we use recursion to sort each half of the linked list.
  sort(&second_half);
  *beginning = list_combine(first_half, second_half); /* We call out list_combine function to combine both halfs and
                                                        return sorted list. */
}


void LinkedList :: split_linked_list(Node* s1, Node **start, Node **end)
{
  Node *p1 = s1->next; // This node moves 2 nodes each time.
  Node *p2 = s1; // This node moves 1 node each time.

  while(p1 != NULL) //Iterates through linked list.
  {
    p1 = p1->next;
    if(p1 != NULL)
    {
      p2 = p2->next;
      p1 = p1->next;
    }
  }

  *start = s1; /* Here we split list into two based on p2
                  location since it is before the middle of
                  list */
  *end = p2->next;
  p2->next = NULL;
}


Node* LinkedList :: list_combine(Node *first_half, Node *second_half)
{
  Node* final_list = NULL; // this is node we return in end.
  if(first_half == NULL)/*If first half is NULL, only second
                        half of linked list exists and we return this. */
  {
    return second_half;
  }
  else if(second_half == NULL) /* Same here, if second half is NULL, only
                                  need to return first half. */
  {
    return first_half;
  }

  if(first_half->frequency > second_half->frequency) //checks frequency and whichever is greater is at start of linked list.
  {
    final_list = first_half;
    final_list->next = list_combine(first_half->next, second_half); // recursive call for rest of nodes.
  }
  else if(first_half->frequency == second_half->frequency) // if frequencies are equals, compares words and sorts them alpabetically.
  {
    if(first_half->word <= second_half->word)
    {
      final_list = first_half;
      final_list->next = list_combine(first_half->next, second_half);
    }
    else
    {
      final_list = second_half;
      final_list->next = list_combine(first_half, second_half->next);
    }
  }
  // If we reach here, then the frequency is less than, because we have already checked greater than, and equal to.
  else {
    final_list = second_half;
    final_list->next = list_combine(first_half, second_half->next);
  }
  return final_list;
}

/* deleteNode function - deletes node that contains word 
  given in function arguement if it exists, otherwise does
  not do anything */
Node* LinkedList :: deleteNode(string word)
{
  Node* prev = NULL;
  Node* curr = head;

  while(curr != NULL)
  {
    if(curr->word == word)
    {
      break;
    }
    prev = curr;
    curr = curr->next;
  }

  if(curr == NULL)
  {
    return NULL;
  }

  if(prev == NULL)
  {
    head = head->next;
  }
  else
    prev->next = curr->next;
  curr->next = NULL;
  return curr;
}

/* length function - iterates through linked list and 
  calculates length and returns this value */
int LinkedList :: length()
{
  int length = 0;
  Node *curr = head;

  while(curr != NULL)
  {
    length++;
    curr = curr->next;
  }
  return length;
}

/* print function - iterates through linked list and creates
   a string with each node's word and frequency and
   returns this string */
string LinkedList :: print()
{
  string list_str = "";
  Node *h = head;
  while(h != NULL)
  {
    list_str += " - " + h->word + ": " + to_string(h->frequency) + "\n";
    h = h->next;
  }
  return list_str;
}

/* deleteList function - this function deletes every node
  to prevent memory leaks */
void LinkedList :: deleteList()
{
  Node *curr = head;
  Node *temp = NULL;

  while(curr != NULL)
  {
    temp = curr->next;
    delete(curr);
    curr = temp;
  }
  head = NULL;
}

/* deleteAndFreeNode function - similar to delete function 
  in the sense that it deletes Node that contains word given
  in function arguement but also frees the memory as well. */
void LinkedList :: deleteAndFreeNode(string word)
{
  Node* ptr = deleteNode(word);
  if(ptr != NULL)
  {
    ptr->next = NULL;
    delete(ptr);
  }
  return;
}