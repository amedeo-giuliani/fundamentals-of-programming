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
int find(List<Item>& L, string K, string H) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.gets1())
			if(H == it.gets2())
				return 0;  // Found K and H
			else
				return 2;	//Only K found
	}
	return 1;                // K and H not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.gets1() == it.gets1()) return L.currPos();  // Found K
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
		if (it.gets1() <= L.getValue().gets1())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

  LList<Item> l;

  int n;

  string s1,s2;

  cout << "List elements number: ";
  cin >> n;

  for(int i = 0; i < n; i++){
	  cout << "Insert first string: ";
	  cin >> s1;
	  cout << "Insert second string: ";
	  cin >> s2;
	  Item item(s1,s2);
	  insert_ordered(l,item);
  }

  l.moveToStart();

  cout << "List 1: ";  
  lprint(l);

  cout << "Insert s1 to search: ";
  cin >> s1;

  cout << "Insert s2 to search: ";
  cin >> s2;

  int f = find(l,s1,s2);

  Item pair(s1,s2);

  switch(f){
  case 0:
	  cout << "Pair found in list" << endl;
	  break;
  case 1:
	  cout << "Pair not found. Adding it..." << endl;
	  l.append(pair);
	  break;
  case 2:
	  cout << "s1 found, but not in pair with s2. Linking s2 to s1..." << endl;
	  l.substitute(pair);
	  break;

  default:
	  break;
  }

  l.moveToStart();

  lprint(l);

  return 0;
}