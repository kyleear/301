//kyle ear Assignment 2
//cpsc 301-03
#include <iostream>
#include <string>
#include <fstream>
#include "person.cpp"

using namespace std;

int readData(int arraysize, Person p[]){
  string fname;
  string lname;
  float pay;
  float hours;
  int newsize;

  ifstream infile;
  infile.open("input.txt");
  if(!infile){
    cout<<"could not open file"<<endl;
  }
for(int i=0;i<arraysize;i++){
  infile>>fname;
  infile>>lname;
  infile>>pay;
  infile>>hours;

  p[i].setFirstName(fname);
  p[i].setLastName(lname);
  p[i].setPayRate(pay);
  p[i].setHoursWorked(hours);

if(infile.eof()){
  newsize=i;
  i=20;
}

}
infile.close();
return newsize;
}

void writeData(int newsize, int arraysize, Person p[]){
  ofstream outfile;
  outfile.open("output.txt");

  for(int i=0;i<newsize+1;i++){
    outfile<<p[i].fullName()<<" "<<p[i].totalPay()<<endl;
  }
  outfile.close();
}

int main() {

int arraysize=20;
Person people[arraysize];
int newsize;

readData(arraysize, people);
writeData(newsize, arraysize, people);


	return 0;
}
