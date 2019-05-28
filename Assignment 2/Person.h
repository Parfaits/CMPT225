#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person {                  // this is the base class
    private:
        string name;
        int idNumber;
    public:
        Person(const string& na, const int& id);
        virtual void print();
        //string getName();
};

class Student : public Person {  
// this class inherits from the base class Person
    private:
        string major;
        int gradYear;
    public:
        Student(const string& na, const int& id, const string& maj,const int& grad)
            : Person(na, id), major(maj), gradYear(grad) {}
        void print();
        //void changeMajor(const string& newMajor);
};

class UndergraduateStudent : public Person
{
private:
    string res;
public:
    UndergraduateStudent(const string& na, const int& id, const string& res = "None")
        : Person(na, id), res(res) {}
    void print();
};

class GraduateStudent : public Person
{
private:
    string thesis;
public:
    GraduateStudent(const string& na, const int& id, const string& title = "None")
        : Person(na, id), thesis(title) {}
    void print();
};

class Faculty : public Person
{
private:
    string department;
    int startYear;
public:
    Faculty(const string& na, const int& id, const string& dep, const int& start)
        : Person(na, id), department(dep), startYear(start) {}
    void print();
    
};

class Professor : public Person
{
private:
    string researchTopic;
public:
    Professor(const string& na, const int& id, const string& research = "None")
        : Person(na, id), researchTopic(research) {}
    void print();
};

class Instructor : public Person
{
private:
    string courseNumber;
public:
    Instructor(const string& na, const int& id, const string& num = "None")
        : Person(na, id), courseNumber(num) {}
    void print();
};


#endif