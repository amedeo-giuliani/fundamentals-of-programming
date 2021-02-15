// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked queue class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lqueue.h"

#include "LQueueTest.h"

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {

	srand(time(NULL));

	LQueue<Item> q;

	job j;
	j.jobID=0;

	int tot_pages=0;
	bool printing = 0;
	int k;

	for(int i = 0; i < 28800; i++){
		int n = rand();

		if(n%180==0){
			j.userID = 1 + rand() % 10;
			j.pages_to_print = 1 + rand() % 20;
			j.jobID++;

			time_t(now);
			j.timestamp = ctime(&now);

			Item it = Item(j);
			q.enqueue(it);

			cout << "Job inserted: " << it << endl;
		}

		if(q.length()>0){
			if(!printing){
				printing = 1;
				Item it = q.frontValue();
				k = it.get().pages_to_print;
			}
			k--;
			tot_pages++;
			if(k==0){
				Item it = q.dequeue();
				cout << "Job finished: " << it << endl;;
				if(q.length()==0)
					printing = 0;
				else{
					Item it = q.frontValue();
					k = it.get().pages_to_print;
				}
			}
		}
	}

	cout << "Total pages printed: " << tot_pages << endl;

	return 0;
}
