#ifndef ArrayQueue_H
#define ArrayQueue_H
#include <iostream>
#include <string>

using namespace std;

template <typename E>
class ArrayQueue
{
private:
	E* S;
	int cap;

	int f;
	int r;
	int n;
public:
	ArrayQueue( int c) :
		S(new E[c]), cap(c) { }
	int size() const;
	bool empty() const;
	const E& front() const;
	void enqueue (const E& e);
	const E& dequeue();
};

#endif