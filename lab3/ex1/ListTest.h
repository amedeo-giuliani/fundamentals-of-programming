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


void mergeLists(List<Item>& l1, List<Item>& l2, List<Item>& l3){
	l3.moveToStart();
	l1.moveToStart();
	l2.moveToStart();

	do{

		if(l1.length()>0 && l2.length()>0){
			
			if(l1.getValue().key() >= l2.getValue().key()){
				l3.append(l1.getValue());
				l1.remove();
			}
			else{
				l3.append(l2.getValue());
				l2.remove();
			}
		}

		else{
			if(l1.length()>=0){
				l3.append(l1.getValue());
				l1.remove();
			}

			else{
				l3.append(l2.getValue());
				l2.remove();
			}
		}

	}while((l1.length()>0)||(l2.length()>0));
}


#endif

