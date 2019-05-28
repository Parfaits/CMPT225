#ifndef ArrayStack_H
#define ArrayStack_H
#include <iostream>
#include <string>

using namespace std;

template <typename E>
class ArrayStack
{
private:
	E* S; // ay holding the stack
	int cap; // capacity
	int t; // index of top element
public:
	ArrayStack( int c) :
		S(new E[c]), cap(c), t(-1) { }

	int size() const;
	bool empty() const;
	const E& top() const;
	void push(const E& e);
	const E& pop();
	
};




#endif