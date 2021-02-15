//Min-heap

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione8-es1-heap.h"

template <class Item> 
  void exch(Item &A, Item &B) 
    { Item t = A; A = B; B = t; } 

int main(int argc, char** argv) {

	int L;

	cout << "Inserisci numero funi: ";
	cin >> L;
	MinHeapPQ<int> minheap(L);

	for(int i = 0; i < L; i++){
		int n;
		cout << "Inserisci lunghezza corda " << i+1 << ": ";
		cin >> n;
		minheap.insert(n);
	}

	minheap.stampa();

	int costo = 0;

	do{
		int m1 = minheap.getmin();
		int m2 = minheap.getmin();

		cout << "m1 m2: " << m1 << " " << m2 << endl;

		costo = costo+m1+m2;
		cout << "costo: " << costo << endl;
		minheap.insert(m1+m2);
	}while(!minheap.empty());

	cout << "Costo totale: " << costo << endl;

	return 0;
}