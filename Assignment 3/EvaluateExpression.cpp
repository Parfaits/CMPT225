#include <iostream>
#include <stack>
#include <string.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <typeinfo>
#include "ArrayStackMod.h"

using namespace std;


/*int EvalExp(char* valtok[], char* optok[], stack<int> valStack, stack<char> opStack){
	int i = 0;
	while(valtok[i] != NULL && optok != NULL){
		valStack.push(atoi(valtok[++i]));
	}
}*/

template <typename E>
int ArrayStackMod<E>::size() const{
	return t+1;
}

template <typename E>
bool ArrayStackMod<E>::empty() const{
	return t == -1;
}

template <typename E>
const E& ArrayStackMod<E>::top() const{
	return S[t];
}

template <typename E>
void ArrayStackMod<E>::push(const E& e){
	if (size() == cap) throw "Push to full stack";
	S[++ t] = e;
}

template <typename E>
const E& ArrayStackMod<E>::pop() { 
   if (empty()) throw "Pop from empty stack";
   const E& temp = top();
	t--;
	return temp;
}

// YEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
int prec(char* refOp){
	if (!(strcmp(refOp, "$") == 0 || strcmp(refOp, "<") == 0 || strcmp(refOp, ">") == 0 || strcmp(refOp, "<=") == 0
		 || strcmp(refOp, ">=") == 0 || strcmp(refOp, "+") == 0 || strcmp(refOp, "-") == 0
		 || strcmp(refOp, "*") == 0 || strcmp(refOp, "/") == 0))
	{
		throw "BadExpression";
	}
	//cout << "refOp is: " << *refOp << endl;
	if (strcmp(refOp, "$") == 0)
	{
		return 0;
	}
	else if(strcmp(refOp, "<") == 0 || strcmp(refOp, ">") == 0 || (strcmp(refOp, "<=") == 0)
	 || (strcmp(refOp, ">=") == 0)){
		return 1;
	}
	else if (strcmp(refOp, "+") == 0 || strcmp(refOp, "-") == 0)
	{
		//cout << "Enter in +-" << endl;
		return 2;
	}
	else if (strcmp(refOp, "*") == 0 || strcmp(refOp, "/") == 0)
	{
		return 3;
	}
	//throw "wot m8"; //error
	throw "BadExpression"; // saved me headache of debug!!! OMG
}

// template <typename E>
// void ArrayStackMod<E>::doOp(ArrayStackMod<int>& valStack,
// 		 ArrayStackMod<char*>& opStack){
void doOp(ArrayStackMod<float>& valStack,
		 ArrayStackMod<char*>& opStack){
	//cout << "valStack top is: " << valStack.top() << endl;
	//cout << "OpStack top is: " << opStack.top() << endl;
	const float& x = valStack.pop();
	const float& y = valStack.pop();
	const char* op = opStack.pop();
	//cout << "pop succsess! Op is: " << op << endl;
	//cout << "pop succsess! x is: " << x << endl;
	//cout << "pop succsess! y is: " << y << endl;
	if      (strcmp(op, "+") == 0)  valStack.push(y + x);
	else if (strcmp(op, "-") == 0)  valStack.push(y - x);
	else if (strcmp(op, "*") == 0)  valStack.push(y * x);
	else if (strcmp(op, "/") == 0)  valStack.push(y / x);
	else if (strcmp(op, "<=") == 0) valStack.push(y <= x);
	else if (strcmp(op, ">=") == 0) valStack.push(y >= x); //{cout << "Enter >= " << endl; valStack.push(y >= x);}
	else if (strcmp(op, "<") == 0)  valStack.push(y < x);
	else if (strcmp(op, ">") == 0)  valStack.push(y > x);//{cout << "Enter > " << endl;  valStack.push(y > x);}
	//else throw "BadExpression";

	//cout << "Done performing calculations valStack top: "<< valStack.top() << endl;
}


// template <typename E>
// void ArrayStackMod<E>::repeatOps(char* refOp, ArrayStackMod<int>& valStack,
// 		 ArrayStackMod<char*>& opStack){
void repeatOps(char* refOp, ArrayStackMod<float>& valStack,
		 ArrayStackMod<char*>& opStack){
	while(valStack.size() > 1 && prec(refOp) <= prec(opStack.top())){
		//cout << "performing doOp ..." << endl;
		doOp(valStack, opStack);
	}
}

// template <typename E>
// int ArrayStackMod<E>::EvalExp(char A[], int cap, ArrayStackMod<int>& valStack,
// 		 ArrayStackMod<char*>& opStack){
float EvalExp(int A[], char* B[], int cap, ArrayStackMod<float>& valStack,
		 ArrayStackMod<char*>& opStack){
	int i = 0;
	int inequality = 0;
	//cout << "B elemet 0: " << *B[0] << endl;
	//cout << "B[cap]= " << B[cap-1] << endl;
	//*B[cap] = '$';
	//cap++;
	//cout << "performing EvalExp ..." << endl;
	// valtok = strtok(A, " +-*/<>=");
	// optok = strtok(A, " 1234567890$");
	// while(optok != NULL){
	while(i < cap){

		valStack.push(A[i]);
		
		//cout << "val push succsess valStack: " << valStack.top() << endl;
		repeatOps(B[i], valStack, opStack);
		if (*B[i] == '<' || *B[i] == '>' || (strcmp(B[i], "<=") == 0)
	 || (strcmp(B[i], ">=") == 0))
		{
			inequality++;
		}
		opStack.push(B[i]);
		//cout << "Op push succsess opStack: " << opStack.top() << endl;
		//cout << "i=" << i << endl;
		i++;
		// valStack.push(atoi(valtok));
		// valtok = strtok(NULL, " +-*/<>=");
		// opStack.push(optok);
		// repeatOps(optok, valStack, opStack);
		// optok = strtok(NULL, " 1234567890$");
	}
	valStack.push(A[i]);
	char dollabill = '$';
	char* dolla = &dollabill;
	repeatOps(dolla, valStack, opStack);
	// *optok = '$';
	// valStack.push(atoi(valtok));
	// repeatOps(optok, valStack, opStack);
	//cout << "typeid of valStack top: " << typeid(valStack.top()).name() << endl;
	if (inequality == 1)
	{
		if (valStack.top())
		{
			throw "true.";
		} else
		{
			throw "false.";
		}
	} else if(inequality>1) throw "BadExpression";
	//if (!opStack.empty()) throw "BadExpression";
	return valStack.top();
}

/*template <typename E>
void ArrayStackMod<E>::parseVal(char A[], int cap, ArrayStackMod<int>& valStack){

}

template <typename E>
void ArrayStackMod<E>::parseOp(char A[], int cap, ArrayStackMod<char*>& opStack){

}*/

int main(int argc, char const *argv[])
{
	try
	{char temp[256];
		//char tempt[256];
		int cap = 0;
		int i = 0;
		int j = 0;
		int valtok[256];
		char* optok[256];
		//char* tokens[256];
	
		// stack<int> valStack;
		// stack<char> opStack;
		cin.getline(temp, 256);
		cap = cin.gcount() - 1;
		//memcpy(tempt, temp, 256*sizeof(char));
		ArrayStackMod<float> valStack(cap+256);
		ArrayStackMod<char*> opStack(cap+256);
		// tokens[i] = strtok(temp, " 1234567890");
		// int swag = EvalExp()
		//valtok[i] = strtok(temp, " +-*/<>="); // noting strtok:
		optok[j] = strtok(temp, " 1234567890"); // all the delimeters you have will be replaced by NUL character
		//parsing ...
		// cout << "parsing ..." << endl;
		// while(valtok[i] != NULL){
		// 	valtok[++i] = strtok(NULL, " +-*/<>=");
		// }
		 //cout << "parsing op ..." << endl;
	
		while(optok[j] != NULL){
			optok[++j] = strtok(NULL, " 1234567890");
			//j++;
		}
		//cout << *optok << endl;
		char digitemp[256];
		i = 0;
		int w = 0;
		int l = 0;
		while(i < cap){
			//cout << "temp: " << temp[i] << endl;
			while(isdigit(temp[i])){
				digitemp[w] = temp[i];
				//cout << "digitemp val: " << digitemp[w] << endl;
				i++;
				w++;
			} //else
			if(w!=0){
				valtok[l] = atoi(digitemp);
				//cout << "valtok: " << valtok[l] << " l: " << l << endl;
				l++;
				memset(digitemp, 0, 256);
			}
			i++;
			w = 0;
			// {
			// 	//cout << "digitemp val: " << digitemp[i] << endl;
			// 	valtok[w] = atoi(digitemp);
			// 	cout << "valtok: " << valtok[w] << endl;
			// 	memset(digitemp, 0, 256*sizeof(int));
			// 	i++;
			// 	w++;
			// }
		}
		if (j >= l) throw "BadExpression"; //case: more than op than ints
		//cout << "parse succsess " << i << " swagh " <<  j << endl;
		//cout << "B elemet 0: " << *optok[0] << endl;
		//cout << "A elemet 0: " << valtok[0] << endl;
		float swag = EvalExp(valtok, optok, j, valStack, opStack);
		// valStack.parseVal(temp, cap, valStack);
		// opStack.parseOp(temp, cap, opStack);
		//cout << "result: " << swag << endl;}
		cout << swag << endl;
	}
		catch(char const* c){
		cerr << c << endl;
	}
	return 0;
}