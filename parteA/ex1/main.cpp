
#include "ListTest.h"
#include "llist.h"
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <sstream>

using namespace std;

int main(){

	LList<Prodotto> p;

	ifstream in1("dispensa.txt");

	if(in1.is_open()){
		string l;
		ingredienti i;

		while(!in1.eof()){
			getline(in1,i.codice,';');
			getline(in1,i.descr,';');
			getline(in1,l);

			istringstream ss(l);
			ss >> i.qnt;

			Prodotto prod(i);
			int r = found(p,i.codice);

			if(r == -1)
				p.append(prod);
			else{
				Prodotto tormv;
				p.moveToPos(r);
				tormv = p.remove();
				tormv.setqnt(tormv.qnt()+prod.qnt());
				p.insert(tormv);
			}
		}
	}

	in1.close();

	LList<Item> s;

	ifstream in2("ricette.txt");

	if(in2.is_open()){
		string l;
		ricetta ric;

		while(!in2.eof()){
			getline(in2,l,';');
			istringstream ss(l);
			ss >> ric.num;

			getline(in2,ric.descr,';');
			getline(in2,ric.cod1,';');

			getline(in2,l,';');
			istringstream ss1(l);
			ss1 >> ric.qnt1;

			getline(in2,ric.cod2,';');

			getline(in2,l);
			istringstream ss2(l);
			ss2 >> ric.qnt2;

			s.append(Item(ric));
		}
	}

	in2.close();

	mergesort(s);
	lprint(s);

	while(true){
		int n;
		cout << "Inserisci numero piatto: ";
		cin >> n;

		int f = found(s,n);

		if(f == -1)
			cout << "Piatto non trovato." << endl;
		else{
			s.moveToPos(f);
			Item i = s.getValue();

			int r1 = found(p,i.get().cod1);
			p.moveToPos(r1);
			Prodotto tp1 = p.getValue();

			int r2 = found(p,i.get().cod2);
			p.moveToPos(r2);
			Prodotto tp2 = p.getValue();

			if(tp1.qnt() >= i.get().qnt1 && tp2.qnt() >= i.get().qnt2){
				cout << "Ordine accettato." << endl;

				p.moveToPos(r1);
				p.remove();
				tp1.setqnt(tp1.qnt()-i.get().qnt1);
				p.insert(tp1);

				p.moveToPos(r2);
				p.remove();
				tp2.setqnt(tp2.qnt()-i.get().qnt2);
				p.insert(tp2);

				lprint(p);
			}
			else{
				if(tp1.qnt() < i.get().qnt1)
					cout << "Quantita' prodotto 1 non sufficiente." << endl;
				else
					cout << "Quantita' prodotto 2 non sufficiente." << endl;
			}
		}

	}

}



