// Include the linked list template class
#include "alist.h"

// Generic list test commands
#include "ListTest.h"

void selectionsort(List<Item>& L) {
	int min_pos;
	Item it_min;
	Item it_temp;
	// se lunghezza <2 non fai nulla
	for (int i = 0; i<L.length() - 1; i++) {
		L.moveToPos(i);
		it_min = L.getValue();
		min_pos = i;
		for (int j = i + 1; j<L.length(); j++) {
			L.moveToPos(j);
			it_temp = L.getValue();
			if (it_temp < it_min)
			{
				min_pos = L.currPos();
				it_min = it_temp;
			}
			L.next();
		}
		L.moveToPos(min_pos);
		it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}

}