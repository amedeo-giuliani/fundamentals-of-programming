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

#include "selection.h"


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
		if (it.key() <= L.getValue().key())
		{
			L.insert(it);
			return;
		}
	}
	L.append(it);
}


// Main routine for linked list driver class
int main(int argc, char** argv) {

	srand(time(NULL));

	LList<Item> l1;
	LList<Item> l2;

	int MINVAL,MAXVAL,n;

	cout << "Inserisci primo estremo: ";
	cin >> MINVAL;

	cout << "Inserisci secondo estremo: ";
	cin >> MAXVAL;

	cout << "Inserisci numero di elementi: ";
	cin >> n;

	l1.moveToStart();
	l2.moveToStart();

	for(int i = 0; i < n; i++){
		Item r(rand()%(MAXVAL-MINVAL+1)+MINVAL);
		l2.insert(r);
		l2.next();
		lprint(l2);
	}

	l2.moveToStart();

	while(l2.length()>0){
		Item t(l2.remove());
		l1.insert(t);
		l1.next();
		lprint(l1);
	}

	l1.moveToStart();

	cout << "L1: ";
	lprint(l1);

	selection(l1);

	cout << "L1: ";
	lprint(l1);

	cout << endl;

	return 0;
}
