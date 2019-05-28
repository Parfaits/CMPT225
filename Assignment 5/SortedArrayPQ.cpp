#include <iostream>
#include "PQ.h"

using namespace std;

bool PQ::empty() const{
	return lastposition > 0;
}

int PQ::size() const{
	return lastposition + 1;
}

void PQ::insert(int k, char c){
	int newkeylist[MAX];
	char newvaluelist[MAX];
	int i = 0;
	int w = 0;
	for (; i < size(); i++)
	{
		if (k < key[i])
		{
			newvaluelist[i] = value[i];
			newkeylist[i] = key[i];
		} else {
			break;
		}
		//key[i] = 0;
		//value[i] = 0;
	}
	newvaluelist[i] = c;
	newkeylist[i] = k;
	i++;
	lastposition++;
	for (; i < size(); i++)
	{
		newvaluelist[i] = value[i-1]; 
		newkeylist[i] = key[i-1]; 
	}
	for (int j = 0; j < size(); j++)
	{
		value[j] = newvaluelist[j];
		key[j] = newkeylist[j];
		//cout << "newvaluelist[j] = " << newvaluelist[j] << endl;
		//cout << "newkeylist[j] = " << newkeylist[j] << endl;
	}
	print();
}

void PQ::removeMin(){
	int newkeylist[MAX];
	char newvaluelist[MAX];
	int i = 1;
	for (; i < size(); i++)
	{
		newvaluelist[i-1] = value[i];
		newkeylist[i-1] = key[i];
	}
	lastposition--;
	for (int j = 0; j < size(); j++)
	{
		value[j] = newvaluelist[j];
		key[j] = newkeylist[j];
	}
	print();
}

void PQ::print() const{
	cout << '[';
	for (int i = 0; i < size(); i++)
	{
		cout << key[i] << ',' << value[i] << ',';
	}
	cout << "] lastposition=" << lastposition << endl;
}

int main(int argc, char const *argv[])
{
	PQ pq;

	pq.insert(5,'a');
	pq.insert(4,'b');
	pq.insert(7,'i');
	pq.insert(1,'d');
	pq.removeMin();
	pq.insert(3,'j');
	pq.insert(6,'c');
	pq.removeMin();
	pq.removeMin();
	pq.insert(8,'g');
	pq.removeMin();
	pq.insert(2,'h');
	pq.removeMin();
	pq.removeMin();
	//pq.print();
	return 0;
}