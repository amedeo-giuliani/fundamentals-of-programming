#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <string>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKeyInt = 1000;
static string maxKeyString = "";

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef string Key1;
typedef int Key2;

class Item1 {
private:
  string ufficio;
  Key1 nomecognome;
public:
	Item1(string u="", Key1 nc=maxKeyString) { ufficio = u; nomecognome = nc; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
	Key1 key() const { return nomecognome; }
	string getUfficio() const { return ufficio; }
	int null() { return nomecognome == maxKeyString; }

    void show(ostream& os = cout)
	{ os << ufficio << " " << nomecognome << endl; }
};

class Item2 {
private:
  string nomecognome;
  Key2 telefono;
public:
	Item2(string nc="", Key2 t=maxKeyInt) { nomecognome = nc; telefono = t; }
  // The following is for those times when we actually
  //   need to get a value, rather than compare objects.
	Key2 key() const { return telefono; }
	string getNomeCognome() const { return nomecognome; }
	int null() { return telefono == maxKeyInt; }
      
	void show(ostream& os = cout)
	{ os << nomecognome << " " << telefono << endl; }
};

ostream& operator<<(ostream& os, Item1& x)
  { x.show(os); return os; }

ostream& operator<<(ostream& os, Item2& x)
  { x.show(os); return os; }

  
#endif