//Min-heap

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "esercitazione8-es3-heap.h"

template <class Item> 
  void exch(Item &A, Item &B) 
    { Item t = A; A = B; B = t; } 

int main(int argc, char** argv) {
	
	const int k = 3, n = 4;

	int a[k][n] = { 
	{1,3,5,7},
	{2,4,6,8},
	{0,9,10,11}};

	MinHeapPQ<item> mh(k);

	for(int i = 0; i < k; i++){
		item it(a[i][0],i,1);
		mh.insert(it);
	}

	int o[k][n];

	for(int i = 0; i < k; i++){
		for(int j = 0; j < n; j++){
			item min = mh.getmin();
			cout << "MIN: " << min.getVal() << endl;
			o[i][j] = min.getVal();
			if(min.getJ()<n){
				item it(a[min.getI()][min.getJ()],min.getI(),min.getJ()+1);
				mh.insert(it);
			}
		}
	}

	cout << "Output array: " << endl;
	for(int i = 0; i < k; i++)
		for(int j = 0; j < n; j++)
			cout << o[i][j] << " ";

	cout << endl;

	return 0;
}