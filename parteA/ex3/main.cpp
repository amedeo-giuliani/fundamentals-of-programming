#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "ListTest.h"

using namespace std;

int main(){

	const int N = 100;

	LList<Item> l[N];

	for(int i = 0; i <= N; i++){
		Item t(i+1);
		l[i].insert(t);
	}

	for(int i = 0; i < N; i++){

		int cn = i+1;

		while(cn != 1){
			if(cn%2 != 0)
				cn = cn*3+1;
			else
				cn =  cn/2;

			Item t(cn);
			l[i].append(t);
		}

	}

	int maxlength = 0;
	int max;

	for(int i = 0; i < N; i++){
		cout << "Lista " << i+1 << " :"; lprint(l[i]);

		if(maxlength < l[i].length()){
			maxlength = l[i].length();
			max = i+1;
		}
	}

	ofstream out("maxsequence.txt");

	if(out.is_open()){

		for(l[max-1].moveToStart(); l[max-1].currPos() < l[max-1].length(); l[max-1].next()){
			Item t = l[max-1].getValue();
			out << t.key() << " ";
		}
	}

	out.close();

	for(int i = 0; i < N; i++){
		mergesort(l[i]);
		cout << "List " << i+1 << " :"; lprint(l[i]);
	}

	return 0;

}
