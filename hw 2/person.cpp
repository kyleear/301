//kyle ear
//assignment 4 part 2
//cpsc 301-03
#include "person.h"
#include <iostream>
#include <string>
Person::Person(string firstname, string lastname, float rate, float hours) {
	lastName = lastname;
	firstName = firstname;
	payRate = rate;
	hoursWorked = hours;

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
