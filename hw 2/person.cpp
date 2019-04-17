//kyle ear Assignment 2
//cpsc 301-03
#include "person.h"
#include <iostream>
#include <string>
Person::Person() {
	lastName = " ";
	firstName = " ";
	payRate = 0.0;
	hoursWorked = 0.0;

}
void Person::setFirstName(string fname) {
	firstName = fname;
}
string Person::getFirstName() {
	return firstName;
}
void Person::setLastName(string lname) {
	lastName = lname;
}
string Person::getLastName() {
	return lastName;
}
void Person::setPayRate(float rate) {
	payRate = rate;
}
float Person::getPayRate() {
	return payRate;
}
void Person::setHoursWorked(float hours) {
	hoursWorked = hours;
}
float Person::getHoursWorked() {
	return hoursWorked;
}
string Person::fullName() {
	return firstName + " " + lastName;
}
float Person::totalPay() {
	return payRate * hoursWorked;
}
