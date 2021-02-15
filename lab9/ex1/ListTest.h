// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LISTTEST_H
#define LISTTEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
using namespace std;

#include "list.h"

// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}

// Print out the list (including showing position for the fence)
// Print list contents
template <typename E>
void lprint(List<E>& L) {
  int currpos = L.currPos();

  L.moveToStart();

  cout << "< ";
  int i;
  for (i=0; i<currpos; i++) {
	  Item it = L.getValue();
	  cout << "( " << it.key() << " " << it.getSTR() << " )" << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    Item it = L.getValue();
	cout << "( " << it.key() << " " << it.getSTR() << " )" << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}

int find(List<Item>& L, int K) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.key()) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

void merge(List<Item>& Lm, List<Item>& La, List<Item>& Lb) {
	La.moveToStart();
	Lb.moveToStart();
	Item removed;
	int N = La.length();
	int M = Lb.length();
	for (int k = 0; k < N + M; k++)
	{
		if (La.length() == 0)
		{
			removed = Lb.remove();
			Lm.append(removed);
			continue;
		}
		if (Lb.length() == 0)
		{
			removed = La.remove();
			Lm.append(removed);
			continue;
		}
		if (La.getValue().key()<Lb.getValue().key())
			removed = La.remove();
		else
			removed = Lb.remove();
		Lm.append(removed);
	}
}

void mergesort(List<Item>& Lm)
{
	Lm.moveToStart();
	if (Lm.length() < 2) return;
	LList<Item> La, Lb;
	Item removed;
	int N = Lm.length();
	for (int k = 0; k<N; k++) {
		removed = Lm.remove();
		if (k % 2) La.append(removed);
		else Lb.append(removed);
	}
	mergesort(La);
	mergesort(Lb);
	merge(Lm, La, Lb);
}

#endif

