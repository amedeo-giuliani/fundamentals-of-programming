// From the software distribution accompanying the textbook
// "A Practical Itemroduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Array-based list class test program

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
#include <fstream>
#include <sstream>

using namespace std;

// Include the array-based list template code
#include "alist.h"

// Generic list test commands
#include "ListTest.h"

#include "sorting.h"

// Main routine for array-based list driver class
int main(int argc, char** argv) {  
	
	string n,c,l;
	int g,m,a;

	AList<Item> L;

	ifstream in("agenda.txt");

	if(in.is_open()){
		while(!in.eof()){
			in >> n;
			in >> c;
			getline(in,l,'/');
			istringstream ss(l);
			ss >> g;
			getline(in,l,'/');
			istringstream ss1(l);
			ss1 >> m;
			getline(in,l);
			istringstream ss2(l);
			ss2 >> a;

			Item i(n,c,g,m,a);
			L.append(i);
		} 
	}

	in.close();

	lprint(L);

	selectionsort(L);

	lprint(L);

	return 0;
}