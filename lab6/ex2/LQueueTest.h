// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

#ifndef LQUEUETEST_H
#define LQUEUETEST_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions
#include <ctime>

using namespace std;

#include "lqueue.h"

struct job{
	char* timestamp;
	int pages_to_print;
	int userID;
	int jobID;
};

// Your basic int type as an object.
class Item {
private:
	job j;
public:
	Item () {}
    Item(job j) { this->j = j; }
    // The following is for those times when we actually
    //   need to get a value, rather than compare objects.
    job get() const { return j; }
};

// Let us print out Items easily
ostream& operator<<(ostream& s, const Item& i)
  { return s << i.get().jobID << " " << i.get().userID << " " << i.get().pages_to_print << " " << i.get().timestamp; }



// Assert: If "val" is false, print a message and terminate
// the program
void Assert(bool val, string s) {
  if (!val) { // Assertion failed -- close the program
    cout << "Assertion Failed: " << s << endl;
    exit(-1);
  }
}

// Print the queue
template <typename E>
void Lqueueprint(LQueue<E>& Q) {
	for (int i=0; i<Q.length(); i++)
	{
		E dequeued = Q.dequeue();
		cout << dequeued << " ";
		Q.enqueue(dequeued);
	}
}

#endif

