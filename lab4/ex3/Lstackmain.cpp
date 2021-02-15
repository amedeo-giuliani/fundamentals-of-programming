// From the software distribution accompanying the textbook
// "A Practical Introduction to Data Structures and Algorithm Analysis,
// Third Edition (C++)" by Clifford A. Shaffer.
// Source code Copyright (C) 2007-2011 by Clifford A. Shaffer.

// Test program for the linked stack class

#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "lstack.h"

#include "LStackTest.h"

// Funzione per la valutazione di espressioni in notazione polacca postfissa 
// Esempio: espressione  5*( ( ( 9 + 8) * (4 * 6) ) + 7 )             = 2075
// notazione postfissa:  5 9 8 + 4 6 * * 7 + *
// soluzione per espressioni che contengono esclusivamente operazioni di somma e moltiplicazione tra interi.
// Si procede valutando l'espressione da sinistra verso destra:
// •	Quando si incontra un operando si esegue una operazione di push nella pila
// •	Quando si incontra un operatore si eseguono due operazioni di pop per estrarre gli operandi, si esegue l’operazione tra i due operandi e poi si esegue una push del risultato intermedio sulla pila
int PostFixEvaluation(string s)
{
	LStack<int> Stemp;
	int eval = 0;
	for (int i=0; i<s.length();i++)
	{
		if (s[i] == '+')
			Stemp.push(Stemp.pop() + Stemp.pop());
		if (s[i] == '*')
			Stemp.push(Stemp.pop() * Stemp.pop());
		if ((s[i] >= '0') && (s[i] <= '9'))
			Stemp.push(0);
		while ((s[i] >= '0') && (s[i] <= '9'))
			Stemp.push(10*Stemp.pop() + (s[i++]-'0'));
	}
	eval = Stemp.pop();
	return eval;
}

// Driver class for list implementations

// Main routine for array-based list driver class
int main(int argc, char** argv) {
	
	int n;
	long int f=1;

	cout << "Inserisci numero: ";
	cin >> n;

	LStack<int> s;

	for(int i = 1; i <= n; i++)
		s.push(i);

	while(s.length()>0)
		f *= s.pop();

	cout << "Il fattoriale di " << n << " e': " << f << endl;
	
	return 0;
}