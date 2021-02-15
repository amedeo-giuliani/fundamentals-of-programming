// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"

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
		if (La.getValue().get().tot_time<Lb.getValue().get().tot_time)
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


// Main routine for linked list driver class
int main(int argc, char** argv) {

	LList<Item> L;

	fstream in("50rn.txt");

	if(in.is_open()){
		partecipante p;
		string l;
		int cs;

		while(!in.eof()){
			getline(in,l,';');
			istringstream ss(l);
			ss >> p.cn;

			in >> p.min;
			in >> p.sec;
			in >> cs;

			p.tot_time = (float) (((p.min*60*100) + (p.sec*100) + cs)/100);

			L.append(Item(p));
		}
	}

	in.close();

	mergesort(L);

	L.moveToStart();

	lprint(L);

	ofstream out("top_ten.txt");

	if(out.is_open()){
		int currpos = L.currPos();

		  L.moveToStart();

		  int i;
		  for (i=0; i<currpos; i++) {
		    out << L.getValue() << endl;
		    L.next();
		  }
		  while (L.currPos()<10) {
		    out << L.getValue() << endl;
		    L.next();
		  }
		  L.moveToPos(currpos); // Reset the fence to its original position
	}

	out.close();

	L.clear();

	return 0;
}
