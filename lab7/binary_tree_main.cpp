#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>  // Used by timing functions

using namespace std;

#include "binary_tree.h"

int main(int argc, char** argv) {
  srand(time(NULL));

  BinaryTree<int> *myBT = new BinaryTree<int>;
  myBT->AddItem(1);
  myBT->AddItem(0);
  myBT->AddItem(5);
  myBT->AddItem(2);
  myBT->AddItem(14);
  myBT->AddItem(1);
  myBT->AddItem(10);
  myBT->AddItem(4);

  cout << "MyBT1: ";
  myBT->traverse();
  cout << endl;

  myBT->destroy_tree(myBT->Root());
  cout << "MyBT1: ";
  myBT->traverse();
  cout << endl;

  BinaryTree<int> *myBT2 = new BinaryTree<int>;

  /*myBT2->AddItem(7);
  myBT2->AddItem(1);
  myBT2->AddItem(4);
  myBT2->AddItem(2);
  myBT2->AddItem(10);
  myBT2->AddItem(8);
  myBT2->AddItem(1);*/

  myBT2->AddItem(1);
  myBT2->AddItem(0);
  myBT2->AddItem(5);
  myBT2->AddItem(2);
  myBT2->AddItem(14);
  myBT2->AddItem(1);
  myBT2->AddItem(9);
  myBT2->AddItem(4);

  cout << "MyBT2: ";
  myBT2->traverse();
  cout << endl;

  int e = myBT->equal_structure(myBT2->Root());

  if(e == 1)
	  cout << "I due alberi hanno struttura uguale." << endl;
  else
	  cout << "I due alberi hanno sruttura diversa." << endl;

  int t = myBT->equal(myBT2->Root());

  if(t == 1)
	  cout << "I due alberi sono uguali." << endl;
  else
	  cout << "I due alberi sono diversi." << endl;

 return 0;
}