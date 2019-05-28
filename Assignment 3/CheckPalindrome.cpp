#include <iostream>
#include <string.h>
#include <cmath>
#include <istream>
#include "ArrayStack.h"
#include "ArrayQueue.h"

using namespace std;

template <typename E>
int ArrayStack<E>::size() const{
	return t+1;
}

template <typename E>
bool ArrayStack<E>::empty() const{
	return t == -1;
}

template <typename E>
const E& ArrayStack<E>::top() const{
	return S[t];
}

template <typename E>
void ArrayStack<E>::push(const E& e){
	if (size() == cap) throw "Push to full stack";
	S[++ t] = e;
}

template <typename E>
const E& ArrayStack<E>::pop() { 
   if (empty()) throw "Pop from empty stack";
   const E& temp = top();
	t--;
	return temp;
}

// ===================QUEUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
template <typename E>
int ArrayQueue<E>::size() const{
	return n;
}

template <typename E>
bool ArrayQueue<E>::empty() const{
	return n == 0;
}

template <typename E>
const E& ArrayQueue<E>::front() const{
	return S[f];
}

template <typename E>
void ArrayQueue<E>::enqueue(const E& e){
	if(size() == n-1){
		throw "QueueFull";
	}
	S[r] = e;
	r = (r+1)%cap;
	n++;
}

template <typename E>
const E& ArrayQueue<E>::dequeue(){
	if(empty()){
		throw "QueueEmpty";
	}
	const E& temp = front();
	f = (f+1) % cap;
	n--;
	return temp;
}

int main(int argc, char const *argv[])
{
	try{
		//assume <= 256 characters in the input string
		char temp[256];
		int cap = 0;
		int i = 0;
		cin.getline(temp, 256);
		cap = cin.gcount()-1; // '\n' is counted what a bug
		ArrayStack<char> s(cap);
		ArrayQueue<char> q(cap);
		//cout << "cap " << cap << endl; 
		while(i < cap){
			s.push(temp[i]);
			q.enqueue(temp[i]);
			//cout << i << endl;	
			i++;

			//cout << temp[i] << endl;
		}
		while(!s.empty() && (s.pop() == q.dequeue())){
			/*if(s.pop() != q.dequeue()){
				break;
			}*/
			//cout << "swag" << endl;
		}
		//cout << "stackempty " << s.empty() << "Qempty " << q.empty() << endl;
		if(s.empty() && q.empty()){
			cout << "true." << endl;
		} else
		{
			cout << "false." << endl;
		}
	}
	catch(char const* c){
		cerr << c << endl;
	}
	return 0;
}