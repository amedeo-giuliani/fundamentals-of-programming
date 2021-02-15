#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst.h"
#include <time.h>  // Used by timing functions
#include "dlist.h"
#include "ListTest.h"

int main(int argc, char *argv[]){
	
	BST<Item,int> bst1;
	int id;
	string s;

	ifstream in("info.dat");

	if(in.is_open()){
		while(!in.eof()){
			getline(in,s,' ');
			istringstream ss(s);
			ss >> id;

			getline(in,s);

			Item it(id,s);
			bst1.insert(it);
		}
	}

	in.close();

	BST<Item,int> bst2;

	do{
		cout << "Inserisci ID e stringa: ";
		cin >> id >> s;
		if(id>=0){
			Item it(id,s);
			bst2.insert(it);
		}

	}while(id >= 0);

	bst1.balance();
	bst2.balance();

	cout << "BST1" << endl;
	bst1.show(cout);
	cout << endl;

	cout << "BST2" << endl;
	bst2.show(cout);
	cout << endl;

	LList<Item> dl;

	for(int i = 0; i < bst1.tree_size(bst1.getHead()); i++){
		Item it1 = bst1.select(i);
		dl.append(it1);
	}

	dl.moveToStart();

	for(int j = 0; j < bst2.tree_size(bst2.getHead()); j++){

		if(dl.currPos() >= dl.length())
			break;

		Item it2 = bst2.select(j);
		int f = find(dl,it2.key());

		if(f==-1)
			dl.append(it2);
		else{
			Item to_mod = dl.getValue();
			dl.remove();
			string s = to_mod.getSTR() + it2.getSTR();
			to_mod.modSTR(s);
			dl.insert(to_mod);
		}

		dl.next();
	}

	mergesort(dl);

	cout << "DL: "; lprint(dl); cout << endl;

	return 0;
}