#include <iostream>
#include <string>
#include <vector>
#include "CreditCard.h"

using namespace std;

CreditCard::CreditCard(const long& no, const string& nm, 
int lim, double bal = 0) {
    number = no;
    name = nm;
    limit = lim;
    balance = bal;
}

bool CreditCard::chargeIt(double price) {
    // my work goes here
    if(limit == 0)
    {
    	return false;
    }
    if(price < 0.0)
    {
      cout << "Error: the input argument must be positive!" << endl;
      return false;
    } else {
      if (price + balance > double(limit)) {
      	//cout << "Over limit; price not added to bal, card number: " << number << " Balance: " << balance << endl;
      	return false; 
      }
      balance += price;
      float RATIO = balance/((float) limit);
      if(RATIO > OVERHALF)
      {
        cout << "Warning: the current balance on credit card " << number << " is " << RATIO << "%" << " of your limit." << endl;
      }
      return true;       // the charge goes through
    }
}

void CreditCard::makePayment(double amount) {
  // my work goes here
  if(amount < 0.0)
  {
    cout << "Error: the input argument must be positive!" << endl;
  } else {

    balance -= (amount * INTEREST);
    cout << "The current remaining balance is " << balance << " dollars." << endl;
  }
}

ostream& operator<<(ostream& out, const CreditCard& c) {
  out << "Number = " << c.getNumber() << "\n"
      << "Name = " << c.getName() << "\n"
      << "Balance = " << c.getBalance() << "\n"
      << "Limit = " << c.getLimit() << "\n";
  return out;
}


void testCard() {
    vector <CreditCard*> wallet(10); // vector of CC pointers
    wallet[0] = new CreditCard(5391037593875309,"JoBlo",2500);
    wallet[1] = new CreditCard(3485039933951954,"JoBlo",3500);
    wallet[2] = new CreditCard(6011490232942994,"JoBlo",5000);
    

    for (int j = 1; j <= 16; j++) {
      wallet[0] -> chargeIt(double(j)); // explicit cast
      wallet[1] -> chargeIt(2 * j);     // implicit cast
      wallet[2] -> chargeIt(double(3 * j));
    }

    for (int i = 0; i < 3; i++) {
      cout << *wallet[i];
      while (wallet[i]->getBalance() > 100.0) {
        wallet[i]->makePayment(100.0);
        cout << "New balance = " << 
        wallet[i]->getBalance() << "\n";
      }
      delete wallet[i];
    }
}

int main() {
  testCard();
  return 0;
}