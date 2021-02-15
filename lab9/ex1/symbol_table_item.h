#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <time.h>  // Used by timing functions

#include <iostream>
using namespace std;

static int maxKey = 1000;

// la classe ST è predisposta per funzionare esclusivamente con elementi con chiavi di tipo int
typedef int Key;

class Item 
  { 
    private:
      Key ID;
	  string str;
    public:
      Item() 
        { ID = maxKey; }
	  Item(Key id, string s) { ID = id; str = s; }
      Key key() const
        { return ID; }
	  string getSTR() const { return str; }
	  void modSTR(string s) {str = s;}
      int null() const
        { return ID == maxKey; }
	  
      void show(ostream& os = cout)
        { os << ID << " " << str << endl; }
   }; 
ostream& operator<<(ostream& os, Item& x)
  { x.show(os); return os; }

  
#endif