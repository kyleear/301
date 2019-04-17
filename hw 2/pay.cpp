//kyle ear
//assignment 4 part 2
//cpsc 301-03
#include <iostream>
#include <string>
#include <fstream>
#include "person.cpp"
#include <vector>
using namespace std;

void readData(vector <Person> &p){

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
while(infile>>fname>>lname>>pay>>hours){

  p.emplace_back(fname, lname, pay, hours); //dont need to se if emplace

}
infile.close();
}

void writeData(vector <Person> &p){
  ofstream outfile;
  outfile.open("output.txt");

  for(int i=0;i<p.size();i++){
    outfile<<p.at(i).fullName()<<" "<<p.at(i).totalPay()<<endl;
  }
  outfile.close();
}

int main() {

vector <Person> person;

readData(person);
writeData(person);


	return 0;
}
