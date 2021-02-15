#ifndef CREDITCARD_H
#define CREDITCARD_H

#include <string>
#include "money.h"

using namespace std;

class CreditCard{
private:
	string prop;
	string cnum;
	Money tot;

public:
	CreditCard(string p, int n) {	prop = p;
	cnum = n;};

	void print();
	Money getTotalCharges();
	void charge(string item, int e, int c);
};

#endif