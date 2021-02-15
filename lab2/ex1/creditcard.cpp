#include "creditcard.h"
#include <iostream>

void CreditCard::print(){
	std::cout << "Proprietario: " << prop << std::endl;
	std::cout << "Numero carta: " << cnum << std::endl;
}

Money CreditCard::getTotalCharges(){
	return tot;
}

void CreditCard::charge(string item, int e, int c){
	int ce = tot.getEuros();
	int cc = tot.getCents();

	ce += e;
	cc += c;

	tot.setEuros(ce);
	tot.setCents(cc);
}