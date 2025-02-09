#include <iostream>
#include "linkedlist.h"
#include <stack>
#include <stdexcept>
#include <fstream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
  ifstream input1;
  input1.open("shakespeare-cleaned5.txt");
  string each_line; // content of each line is stored in this variable

  LinkedList myList[40]; // initialized array of linked list with size 40 since longest length word in more-input.txt is 39
  for(int i = 0; i < 40; i++)
  {
    myList[i] = LinkedList(); // this loop initializes every linked list in the array using the default constructor
  }

  while(getline(input1,each_line)) // using getline to get every line from file and store it in variable each_line.
  {

    if(each_line.length()==0) // skips line if it is empty
    {
      continue;
    }

    if(each_line.length() > 0) // double check to make sure each_line is not empty
    {
      Node *word = myList[each_line.length()-1].find(each_line); /* uses find function to check if word already exists and stores result in
                                                                  node word */
      
      if(word == NULL) // if word is NULL then it means it does not already exist and we need to add word to appropriate linked list.
      {
        myList[each_line.length()-1].insert(each_line,1); /* We subtract 1 from each_line since index starts from 0. Then call insert function
                                                            and set word frequency to 1. */
      }

      else // If we reach here, the word already exists and we update its frequency by 1. 
      {
        word->frequency += 1; //Testing if comments save
      }

    }
  }
  input1.close();
  
  for(int i = 0; i < 40; i++) // This loop sorts all of the linked lists.
  {
    myList[i].sortcaller();
  }
  
  ifstream input2;
  ofstream output;
  input2.open(argv[1]);
  output.open(argv[2]);
  string each_line2; // Input of each line in file is stored in this variable.
  int length = 0; // Stores first number in each line which represents length.
  int occurance = 0; // Stores second number in each line which represents occurance.
  int counter = 0; // Counter is used to be able to store appropriate number in correct variable.

  while(input2 >> each_line2) // Loops and each line in file is stored in this variable.
  {
    counter++; // Needs 2 iterations in while loop to set length and occurance variables to corresponding input.

    if(counter % 2 == 0) // During second iteration, counter is divisible by 2 so second number in each line is stored in occurance variable.
    {
      occurance = stoi(each_line2); // Uses stoi function to convert string to int.
    }

    else // During first iteration, counter is not divisible by 2 so first number in each line is stored in length variable.
    {
      length = stoi(each_line2); // Uses stoi function to convert string to int.
    }

    if(each_line2.length()==0) // Checks is line is empty and continues to next line.
    {
      continue;
    }

    if(counter % 2 == 0) // Makes sure to only execute every 2 iterations since this is when length and occurance is properly set up.
    {
      output << myList[length-1].find(occurance) << endl; /* Uses second overloaded find function to find the nth occurance of a word with 
                                                                specified length */
    }
    
  }
  input2.close();
}
