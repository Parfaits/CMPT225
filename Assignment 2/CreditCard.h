#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H
#include <iostream>
#include <string>


class CreditCard {
public:
    CreditCard(const long& no, const std::string& nm, 
    int lim, double bal);
    long          getNumber() const    { return number; }
    std::string   getName() const      { return name; }
    double        getBalance() const   { return balance; }
    int           getLimit() const     { return limit; }
    bool chargeIt(double price);      // make a charge
    void makePayment(double amount); // make a payment
    
private:
    long           number;          // credit card number
    std::string    name;            // card owner's name
    double         balance;         // the current balance
    int            limit;           // the credit limit
    const float INTEREST = 0.05;    // my stuff question 1.2
    const float OVERHALF = 0.5;     // my stuff 1.3
};

std::ostream& operator<<(std::ostream& out, const CreditCard& c);


#endif