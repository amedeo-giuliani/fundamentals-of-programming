#include <iostream>
#include <cstdlib>
#include <string>

#include "LStackTest.h"

using namespace std;

int main(){

	string infix = "3+(4-3*(2/5))";

	LStack<Item> S;
	LQueue<Item> Q;
	Item temp;

	for(int i = 0; i < infix.length(); i++){
		if(isdigit(infix[i])){
			Item e(infix[i]);
			Q.enqueue(e);
		}
		else if((infix[i]=='+') || (infix[i]=='-') || (infix[i]=='*') || (infix[i]=='/') || (infix[i]=='(')){
			Item e(infix[i]);
			S.push(e);
		}
		else if(infix[i] == ')'){
			do{
				temp = S.pop();
				if(temp.key()!='(')
					Q.enqueue(temp);
			}while(temp.key()!='(');
		}

		cout << "Stack: "; Lstackprint(S);
		cout << "Queue: "; Lqueueprint(Q);
	}

	while(S.length()>0){
		temp = S.pop();
		Q.enqueue(temp);
	}

	Lqueueprint(Q);
}
