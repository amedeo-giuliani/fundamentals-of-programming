#include "money.h"
#include <iostream>


Money::Money(int e, int c){	
	euros = e;
	cents = c;}

int Money::getEuros(){
	return euros;
}

int Money::getCents(){
	return cents;
}

void Money::setEuros(int e){
	euros = e;
}

void Money::setCents(int c){
	cents = c;
}

Money operator+(Money m1, Money m2){
	Money sum;

	int se,sc;

	se = m1.getEuros() + m2.getEuros();
	sc = m1.getCents() + m2.getCents();

	if (sc >= 100){
		se += sc/100;
		sc -= sc%100;
	}

	sum.setEuros(se);
	sum.setCents(sc);

	return sum;
}

std::ostream& operator<< (std::ostream& os, Money m){
	os << m.getEuros();
	os << m.getCents();

	return os;
}
