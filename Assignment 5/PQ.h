#ifndef PQ_H
#define PQ_H
#define MAX 100
#include <iostream>

using namespace std;

class PQ
{
private:
	int key[MAX];
	//int key;
	char value[MAX];
	//int n;
	int lastposition;

public:
	PQ() {
		//n = 0;
		//value = new char[MAX];
		lastposition = -1;
	}

	void insert(int k, char c);
	void removeMin();
	int size() const;
	bool empty() const;
	void print() const;
	
};


#endif