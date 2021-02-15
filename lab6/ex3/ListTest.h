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

struct partecipante {
	int anno;
	string cn;
	string naz;
};

struct vittorie {
	int nv;
	string cn;
	int max_anno;
	int min_anno;
};

// Your basic int type as an object.
class Item {
private:
	partecipante p;
public:
	Item() { }
	Item(int a, string n, string nn) { p.anno=a; p.cn=n; p.naz=nn; }
	partecipante get() const { return p; }
};

class Item2 {
private:
	vittorie v;
public:
	Item2() {}
	Item2 (string n) { v.nv=0; v.cn=n; v.max_anno=0; v.min_anno=0;}
	vittorie get() const { return v; }
	void setV(int vv) { v.nv = vv;}
	void setMax(int M) { v.max_anno = M;}
	void setMin(int m) {v.min_anno = m; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
{ return s << i.get().cn << " " << i.get().naz << " " << i.get().anno; }

ostream& operator<<(ostream& s, const Item2& i){
	return s << i.get().cn << " " << i.get().nv << " " << i.get().min_anno << " " << i.get().max_anno;
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



#endif

