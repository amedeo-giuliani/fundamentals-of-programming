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
#include "llist.h"

// Your basic int type as an object.
class Item {
private:
  int val;
public:
  Item(int input=0) { val = input; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int key() const { return val; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
  { return s << i.key(); }

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
    cout << L.getValue() << " ";
    L.next();
  }
  cout << "| ";
  while (L.currPos()<L.length()) {
    cout << L.getValue() << " ";
    L.next();
  }
  cout << ">\n";
  L.moveToPos(currpos); // Reset the fence to its original position
}

void merge(LList<Item>& Lm, LList<Item>& La, LList<Item>& Lb) {
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

void mergesort(LList<Item>& Lm)
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

