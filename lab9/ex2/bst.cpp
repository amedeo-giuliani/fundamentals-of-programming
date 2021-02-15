#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "symbol_table_item.h"
#include "bst.h"
#include <time.h>  // Used by timing functions

bool isNumber(string s){
	for(int i = 0; i < s.length(); i++)
		if(!isdigit(s[i]))
			return false;
	return true;
}

int main(int argc, char *argv[]){
	BST<Item1,string> bst1;
	BST<Item2,int> bst2;

	ifstream in("telefoni.txt");

	string u,nc,temp;
	int t;

	if(in.is_open()){
	
		while(!in.eof()){
			getline(in,u,',');
			getline(in,nc,',');
			getline(in,temp);
			istringstream ss(temp);
			ss >> t;

			Item1 it1(u,nc);
			Item2 it2(nc,t);

			bst1.insert(it1);
			bst2.insert(it2);
		}

	}

	in.close();

	bst1.balance();
	bst2.balance();

	cout << "BST1: " << endl;
	bst1.show(cout);

	cout << "BST2: " << endl;
	bst2.show(cout);

	cout << endl;
	cout << "Stampa informazioni: " << endl;
	for(int i = 0; i < bst2.tree_size(); i++){
		Item2 it2 = bst2.select(i);
		Item1 it1 = bst1.search(it2.getNomeCognome());

		cout << it1.getUfficio() << " " << it2.getNomeCognome() << " " << it2.key() << endl;
	}
	cout << endl;

	cout << "Inserisci stringa: ";
	string s;
	getline(cin,s);

	if(isNumber(s)){
		istringstream ss(s);
		int tel;
		ss >> tel;
		Item2 it2 = bst2.search(tel);
		if(!it2.null()){
			Item1 it1 = bst1.search(it2.getNomeCognome());
			cout << "Informazioni ricercate: " << it1.getUfficio() << " " << it2.getNomeCognome() << " " << it2.key() << endl;
		}
		else{
			cout << "Informazioni non trovate. " << endl;
		}
	}
	else{
		Item1 it1 = bst1.search(s);
		string u = it1.getUfficio();

		if(!it1.null()){
			cout << "Persone appartenenti allo stesso ufficio di: " << s << endl;
			
			for(int i = 0; i < bst1.tree_size(); i++){
				Item1 it = bst1.select(i);

				if((it.getUfficio() == it1.getUfficio()) && (it.key() != s))
					cout << it.key() << endl;
			}
		}
		else{
			cout << "Persona non trovata." << endl;
		}
	}
}