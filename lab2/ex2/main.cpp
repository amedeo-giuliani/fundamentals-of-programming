#include <iostream>

using namespace std;

template<typename t> t mostCommon(t *a, int size){
	int pos = 0;
	t max = 0;

	t *b = new int[size];

	for(int i = 0; i < size; i++)
		b[i] = 0;

	for (int i = 0; i < size; i++){
		for(int j = i+1; j < size; j++){
			if(a[i] == a[j])
				b[i]++;
		}
	}

	for(int i = 0; i < size; i++){
		if (max < b[i]){
			max = b[i];
			pos = i;
		}
	}

	return a[pos];
}

int main(){
	
	int n;

	cout << "Insert array length: ";
	cin >> n;

	int *v = new int [n];

	for(int i = 0; i < n; i++){
		cout << "Inserisci numero: ";
		cin >> v[i];
	}

	int item = mostCommon<int>(v,n);

	cout << "Most common element: " << item;

	return 0;
}