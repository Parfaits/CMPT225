#include <iostream>
#include <string.h>
#include <exception>
#include "Progression.h"

using namespace std;

HarmProgression::HarmProgression(double i, double d)
    : Progression(i), mult(d) {}

double HarmProgression::nextValue(const int i) { // advance by adding
    //cout << "first " << first << endl;
    //cout << "cur " << cur << endl;
    //cout << "n=" << n << endl;
    //cout << "mult " << mult << endl;
    double denom = ((1.0/first)+(((double) i)*mult));
    if(denom == 0){
    	throw "Divide by zero in Module HarmProgression.";
    } else {
    	cur = 1.0/denom;
    	return cur;
    }
}

int main(int argc, char const *argv[])
{
	Progression* prog;
	try{
		prog = new HarmProgression();
		prog->printProgression(5);
	}
	catch(char const* c){
		cerr << c << endl;
	}
	return 0;
}