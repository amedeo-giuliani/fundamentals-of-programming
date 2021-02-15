#ifndef MONEY_H
#define MONEY_H

class Money{
private:
	int euros;
	int cents;
public:
	Money(int e=0, int c=0);
	int getEuros();
	int getCents();
	void setEuros(int e);
	void setCents(int c);
};

#endif