// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.
// Return true if "K" is in list "L", false otherwise
int find(List<Item>& L, int K) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.key() == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// Insert "it" at current position
void insert_ordered(List<Item>& L, const Item& it) {
	if (L.length() == 0)
	{
		L.insert(it);
		return;
	}
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		if (it.key() >= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> l1;
  LList<Item> l2;
  LList<Item> l3;

  int n,it;

  cout << "List 1 elements number: ";
  cin >> n;

  for(int i = 0; i < n; i++){
	  cout << "Insert item: ";
	  cin >> it;
	  Item item(it);
	  insert_ordered(l1,item);
  }

  cout << "List 1: ";  
  lprint(l1);

  cout << "List 2 elements number: ";
  cin >> n;

  for(int i = 0; i < n; i++){
	  cout << "Insert item: ";
	  cin >> it;
	  Item item(it);
	  insert_ordered(l2,item);
  }

  cout << "List 2: ";
  lprint(l2);

  mergeLists(l1,l2,l3);

  cout << "List 1 + List 2: ";
  lprint(l3);

  return 0;
}