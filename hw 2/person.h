#pragma once
//kyle ear
//assignment 4 part 2
//cpsc 301-03
//begin person.h
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include <string>
using namespace std;
class Person
{
private:
	string lastName;
	string firstName;
	float  payRate;
	float  hoursWorked;
public:
	Person(string firstname, string lastname, float rate, float hours);
	void setLastName(string lName);
	string getLastName();
	void setFirstName(string fName);
	string getFirstName();
	void setPayRate(float rate);
	float getPayRate();
	void setHoursWorked(float hours);
	float getHoursWorked();
	float totalPay();
	string fullName();
};
#endif // end person.h
