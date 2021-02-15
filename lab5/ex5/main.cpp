#include <string>
#include <iostream>

using namespace std;

string reverse(string s){
	string ss = "";

	if(s.length()==1)
		return s;

	ss += s[s.length()-1] + reverse(s.substr(0,s.length()-1));
	return ss;
}

int main(){
	
	string s;

	cout << "Inserisci stringa: ";
	cin >> s;

	string ss = reverse(s);

	cout << ss << endl;

}