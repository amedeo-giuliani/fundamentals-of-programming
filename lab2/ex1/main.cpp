#include <iostream>
#include <fstream>
#include <string>
#include "money.h"
#include "creditcard.h"

using namespace std;

int main(){

	string p;
	int n;

	cout << "Inserisci proprietario: ";
	cin >> p;

	cout << "Inserisci numero carta: ";
	cin >> n;

	CreditCard CC(p,n);

	ifstream in("input.txt");

	if(in.is_open()){
		string item;
		int euros,cents;
		while(!in.eof()){
			in >> item >> euros >> cents;
			CC.charge(item,euros,cents);
		}
	}


	return 0;
}