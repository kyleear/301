//kyle ear assignment 3
//cpsc 301-03
#include "person.h"
#include <iostream>
#include <string>

Person::Person(){
   firstName= " ";
   lastName= " ";
  employeeID= 0;
  companyName= " ";
  hoursWorked=0.0;
  payRate=0.0;
}

void Person::setFirstName(string fname){
  firstName=fname;
}
string Person::getFirstName() {
    return firstName;
}
void Person::setLastName(string lname){
  lastName=lname;
}
string Person::getLastName(){
  return lastName;
}
void Person::setEmployeeId(int id){
  employeeID=id;
}
int Person::getEmployeeId(){
  return employeeID;
}
void Person::setCompanyName(string compname){
  companyName=compname;
}
string Person::getCompanyName(){
  return companyName;
}
void Person::setHoursWorked(float hoursworked){
  hoursWorked=hoursworked;
}
float Person::getHoursWorked(){
  return hoursWorked;
}
void Person::setPayRate(float pay){
  payRate=pay;
}
float Person::getPayRate(){
  return payRate;
}
string Person::fullName(){
  return firstName+" "+lastName;
}
float Person::totalPay(){
  return hoursWorked*payRate;
}
