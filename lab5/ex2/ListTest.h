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
  string nome,cognome;
  int g,m,a;
public:
  Item(string n="",string c="", int gg=0, int mm=0, int aa=0) { nome = n; cognome = c; g = gg; m = mm; a = aa; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
  string getNome() const { return nome; }
  string getCognome() const { return cognome; }
  int getGiorno() const { return g; }
  int getMese() const { return m; }
  int getAnno() const { return a; }
  bool operator<(Item other){ 
	  if (cognome < other.getCognome())
		  return true;
	  else if(cognome == other.getCognome())
			if(nome < other.getNome())
				return true;
			else if(nome == other.getNome())
				if(a < other.getAnno())
					return true;
				else if(a == other.getAnno())
					if(m < other.getMese())
						return true;
					else if( m == other.getMese())
						if(g < other.getGiorno())
							return true;
	  return false;
  }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i){
	s << i.getNome() << " "; 
	s << i.getCognome() << " ";
	s << i.getGiorno() << "/" << i.getMese() << "/" << i.getAnno();
	return s;
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

