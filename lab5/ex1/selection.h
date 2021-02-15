#ifndef SELECTION_H
#define SELECTION_H

void selection(List<Item>& L){
	int min_pos,min_value;
	Item it_curr, it_temp;

	for(int i = 0; i < L.length()-1; i++){
		L.moveToPos(i);
		it_curr = L.getValue();
		min_pos = i;
		min_value = it_curr.key();

		for(int j = i+1; j < L.length(); j++){
			L.moveToPos(j);
			it_temp = L.getValue();
			if(it_temp.key()<min_value){
				min_pos = L.currPos();
				min_value = it_temp.key();
			}
			L.next();
		}

		L.moveToPos(min_pos);
		it_temp = L.remove();
		L.moveToPos(i);
		L.insert(it_temp);
	}
}

#endif
