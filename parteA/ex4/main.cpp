#include <iostream>
#include <fstream>
#include <cstdlib>

#include "ListTest.h"
#include "llist.h"
#include "link.h"

using namespace std;

int main(){

	ifstream in("spese.txt");

	LList<Item> l1;

	if(in.is_open()){

		int mi,mf,s;

		while(!in.eof()){
			in >> mi;
			in >> mf;
			in >> s;

			l1.append(Item(mi,mf,s));
		}
	}

	in.close();

	cout << "Lista spese: "; lprint(l1);

	LList<Item2> l2;

	l2.moveToStart();

	for(l1.moveToStart(); l1.currPos() < l1.length(); l1.next()){

		float contrib = (float)l1.getValue().spesa()/(l1.getValue().meseF()-l1.getValue().meseI()+1);

		for(int i = l1.getValue().meseI(); i <= l1.getValue().meseF(); i++){
			int r = found(l2,i);
			if(r == -1)
				l2.append(Item2(i,contrib));
			else{
				l2.moveToPos(r);
				Item2 rm = l2.getValue();
				rm.setC(rm.C()+contrib);
				l2.remove();
				l2.insert(rm);
			}
		}

	}

	bubblesort(l2);

	cout << "Spese mensili: "; lprint(l2);

	return 0;

}
