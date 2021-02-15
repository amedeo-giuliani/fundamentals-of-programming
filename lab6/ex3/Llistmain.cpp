// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Linked list class test program

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <time.h>  // Used by timing functions

using namespace std;

// Include the linked list template class
#include "llist.h"

// Generic list test commands
#include "ListTest.h"


// find function for Items.
// Return true if "K" is in list "L", false otherwise
int find(List<Item>& L, string K) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.get().cn) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

// find function for Items.
// Return true if "item" is in list "L", false otherwise
int find(List<Item>& L, const Item& item_to_search) {
	Item it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.get().cn == it.get().cn) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

int find(List<Item2>& L, const Item& item_to_search) {
	Item2 it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (item_to_search.get().cn == it.get().cn) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

int find(List<Item2>& L, string K) {
	Item2 it;
	for (L.moveToStart(); L.currPos()<L.length(); L.next()) {
		it = L.getValue();
		if (K == it.get().cn) return L.currPos();  // Found K
	}
	return -1;                // K not found
}

void merge(LList<Item2>& Lm, LList<Item2>& La, LList<Item2>& Lb) {
	La.moveToStart();
	Lb.moveToStart();
	Item2 removed;
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
		if (La.getValue().get().nv>Lb.getValue().get().nv)
			removed = La.remove();
		else
			removed = Lb.remove();
		Lm.append(removed);
	}
}

void mergesort(LList<Item2>& Lm)
{
	Lm.moveToStart();
	if (Lm.length() < 2) return;
	LList<Item2> La, Lb;
	Item2 removed;
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


int main(int argc, char** argv) {
	
	fstream in("giro_italia.txt");

	LList<Item> L;
	LList<Item2> L2;

	if(in.is_open()){
		partecipante p;
		string l;

		while(!in.eof()){
			getline(in,l,';');
			istringstream ss1(l);
			ss1 >> p.anno;
			getline(in,p.cn,';');
			getline(in,p.naz);

			L.append(Item(p.anno,p.cn,p.naz));
		}
	}

	in.close();

	lprint(L);

	for(L.moveToStart(); L.currPos() < L.length(); L.next()){
		Item it = L.getValue();
		int c = find(L2,it.get().cn);

		if(c==-1){
			Item2 it2(it.get().cn);
			it2.setV(1);
			it2.setMax(it.get().anno);
			it2.setMin(it.get().anno);
			L2.append(it2);
		}
		else{
			cout << "12" << endl;
			L2.moveToPos(c);
			Item2 it2 = L2.getValue();
			it2.setV(it2.get().nv + 1);
			if(it.get().anno<it2.get().min_anno)
				it2.setMin(it.get().anno);
			if(it.get().anno>it2.get().max_anno)
				it2.setMax(it.get().anno);
			L2.remove();
			L2.insert(it2);
		}
	}

	lprint(L2);
	mergesort(L2);
	lprint(L2);

	return 0;
}