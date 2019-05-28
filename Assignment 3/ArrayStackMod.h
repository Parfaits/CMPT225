#ifndef ArrayStackMod_H
#define ArrayStackMod_H
#include <iostream>
#include <string>

using namespace std;

template <typename E>
class ArrayStackMod
{
private:
	E* S; // ay holding the stack
	int cap; // capacity
	int t; // index of top element

	//char stopOp;
	//char* optok;
	//char* valtok;
	//char* refOp;
public:
	ArrayStackMod( int c) :
		S(new E[c]), cap(c), t(-1) { }

	int size() const;
	bool empty() const;
	const E& top() const;
	void push(const E& e);
	const E& pop();
	
	// void doOp(ArrayStackMod<int>& valStack,
	// 	 ArrayStackMod<char*>& opStack);
	// void repeatOps(char* refOp, ArrayStackMod<int>& valStack,
	// 	 ArrayStackMod<char*>& opStack);
	// int EvalExp(char A[], int cap, ArrayStackMod<int>& valStack,
	// 	 ArrayStackMod<char*>& opStack);
	// void parseVal(char A[], int cap, ArrayStackMod<int>& valStack);
	// void parseOp(char A[], int cap, ArrayStackMod<char*>& opStack);
};




#endif