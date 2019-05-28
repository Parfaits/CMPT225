#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

Person::Person(const string& na, const int& id){
	name = na;
	idNumber = id;
}


void Person::print() {
    cout << "Name: " << name << endl;
    cout << "ID: " << idNumber << endl;
}

void Student::print() {
    cout << "Major: " << major << endl;
    cout << "Graduation year: " << gradYear << endl;
}

void UndergraduateStudent::print() {
	cout << "Residence hall: " << res << endl;
}

void GraduateStudent::print(){
	cout << "Thesis title: " << thesis << endl;
}

void Faculty::print(){
	cout << "Department: " << department << endl;
	cout << "Starting year: " << startYear << endl;
}

void Professor::print(){
	cout << "Research topic: " << researchTopic << endl;
}

void Instructor::print(){
	cout << "Course number: " << courseNumber << endl;
}

void testPerson(){
	Person* pp[7];
	pp[0] = new Person("Lilpump", 3);
	pp[1] = new Student("Lilpump", 3, "Sickbeats", 420420);
	pp[2] = new UndergraduateStudent("Lilpump", 3, "Gucci Gang");
	pp[3] = new GraduateStudent("Lilpump", 3, "Gucci gang gucci");
	pp[4] = new Faculty("Lilpump", 3, "Applied Gucci", 420);
	pp[5] = new Professor("Lilpump", 3, "Gucci Relativity");
	pp[6] = new Instructor("Lilpump", 3, "420BLAZEIT");
	pp[0]->print();
	pp[1]->print();
	pp[2]->print();
	pp[3]->print();
	pp[4]->print();
	pp[5]->print();
	pp[6]->print();
}

int main(int argc, char const *argv[])
{
	testPerson();
	return 0;
}