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

//Si vuole simulare un sistema in cui sono presenti M code a cui devono essere assegnati N clienti 
//che attendono di essere serviti. Ad ogni iterazione viene selezionata una coda in modo casuale 
//in cui inserire il nuovo cliente e una seconda coda, sempre in modo casuale, da cui prelevare 
//il cliente in testa (se esiste) da servire.
void QueueServiceSimulation()
{
	srand(time(NULL));
	const int M = 5;
	const int N = 10;
	LQueue<Item> queues[M];

	for (int i = 0; i <= N; i++)
	{
		int in = rand() % M;
		int out = rand() % M;
		Item item(rand() % 100);

		cout << "enqueue " << item << " in queue " << in << endl;
		queues[in].enqueue(item);
		if (queues[out].length() > 0)
		{
			cout << "dequeue from " << out << endl;
			queues[out].dequeue();
		}

		for (int j = 0; j < M; j++)
		{
			cout << "queue[" << j << "] : ";
			if (queues[j].length()>0)
			 Lqueueprint(queues[j]);
			cout << endl;
		}
		cout << endl;
	}
}

// Test di uguaglianza tra due code (il test distrugge le due code)
int equal_queues(LQueue<Item>& Q1, LQueue<Item>& Q2)
{
	if (Q1.length() != Q2.length())
		return 0;
	while (Q1.length()>0)
	{
		Item q1 = Q1.dequeue();
		Item q2 = Q2.dequeue();
		if (q1.key() != q2.key())
			return 0;
	}
	return 1;
}

// Driver class for queue implementations

// Main routine for array-based queue driver class
int main(int argc, char** argv) {
	int n;
	float e;

	cout << "Inserisci lunghezza coda: ";
	cin >> n;

	LQueue<float> q;

	for(int i = 0; i < n; i++){
		cout << "Inserisci elemento: ";
		cin >> e;
		q.enqueue(e);
	}

	Lqueueprint(q);
	cout << endl;

	int j=0;
	float t1,t2,v;

	while(q.length()>1){
		
		n = q.length();

		for(int i = 1; i <= n/2; i++){

			t1 = q.dequeue();
			t2 = q.dequeue();

			switch(j%4){
			case 0:
				v = t1+t2;
				break;
			case 1:
				v = t1-t2;
				break;
			case 2:
				v = t1*t2;
				break;
			case 3:
				v = t1/t2;
				break;
			}

			q.enqueue(v);
		}
		
		if(n%2==1){
			t1 = q.dequeue();
			q.enqueue(t1);
		}

		Lqueueprint(q);
			cout << endl;

		j++;
	}
}