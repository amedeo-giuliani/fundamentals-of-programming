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
  int mi,mf,s;
public:
  Item(int mi=0, int mf=0, int s=0) { this->mi=mi; this->mf=mf; this->s=s; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  int meseI() const { return mi; }
  int meseF() const { return mf; }
  int spesa() const { return s; }
};

class Item2 {

private:
	int m;
	float c;

public:
	Item2(int m=0, float c=0.0) { this->m=m; this->c=c; }
	void setM(int m) {this->m=m;}
	void setC(int c) {this->c=c;}
	int C() const { return c; }
	int M() const {return m;}
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
  { return s << i.meseI() << " " << i.meseF() << " " << i.spesa(); }

ostream& operator<<(ostream& s, const Item2& i){
	return s << i.M() << " " << i.C();
}

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
void lprint(LList<E>& L) {
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

int found(LList<Item2>& L, int n){

	for(L.moveToStart(); L.currPos() < L.length(); L.next())
		if(L.getValue().M() == n)
			return L.currPos();
	return -1;
}

void bubblesort(LList<Item2>& L) {
	for (int i = 0; i< (L.length() - 1); i++) {
		for (int j = (L.length() - 1); j> i; j--) {
			L.moveToPos(j);
			Item2 it_j = L.getValue();
			L.moveToPos(j - 1);
			Item2 it_jj = L.getValue();
			if (it_jj.C()<it_j.C())
			{
				L.moveToPos(j);
				Item2 removed = L.remove();
				L.moveToPos(j - 1);
				L.insert(removed);
			}
		}
	}
}



#endif

