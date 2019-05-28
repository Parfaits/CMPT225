#ifndef PROGRESSION_H
#define PROGRESSION_H
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Progression {
    public:
        Progression(double f = 1.0)      // constructor
            : first(f), cur(f) {}
        void printProgression(int n) {
          cout << firstValue() << endl;
          for (int i = 1; i < n; i++) cout << floor(nextValue(i) * 100000)/100000 << endl;
        }
    protected:
        virtual double firstValue() {  // reset
           cur = first;
           return cur;
        }
        virtual double nextValue(const int n) = 0;// makes it pure virtual
        double first;                  // first value
        double cur;                    // current value
};

class HarmProgression : public Progression
{
public:
  HarmProgression(double i = 1.0, double d = 1.0);
protected:
  virtual double nextValue(const int i);
  double mult;
};

#endif