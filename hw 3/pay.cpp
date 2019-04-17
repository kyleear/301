//kyle ear assignment 3
//cpsc 301-03
#include "person.cpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


void readData(vector<Person>*employees){
string fname;
string lname;
int id;
string compname;
float hours;
float pay;

ifstream infile;
infile.open("input.txt");

if(!infile){
  cout<<"couldnt open "<<endl;
}
Person p;
while(infile>>fname>>lname>>id>>compname>>hours>>pay){
/*while we can still infile all of these variables, set them all using set functions in
class p*/
p.setFirstName(fname);
p.setLastName(lname);
p.setEmployeeId(id);
p.setCompanyName(compname);
p.setHoursWorked(hours);
p.setPayRate(pay);

employees->push_back(p);//kinda like . opperator
/*after we use setters for our variables push them back in the vector
then keep setting and pushing back after*/
  }
infile.close();
}

void getCompanies(vector<string>*companynames, vector<Person>*employees){
string companyname;

for(int i=0;i<employees->size();i++){
  companyname = employees->at(i).getCompanyName();
  companynames->push_back(companyname);
}/*set company name to companynames in the employee class then push companyname
to the companynames vector*/
}

void printHighestPaid(vector<Person>*employees){
  float highestpaid=0.0;
  string highestname;
  int employeeid;
  string employer;
  float totalpay=0.0;
  int index = 0;
  for(int i=0;i<employees->size();i++){
    if(highestpaid<employees->at(i).getPayRate()){
      highestpaid=employees->at(i).getPayRate();
      highestname=employees->at(i).fullName();
      employeeid=employees->at(i).getEmployeeId();
      totalpay=employees->at(i).totalPay();
      employer=employees->at(i).getCompanyName();
/*setting highestpaid to the first value then incraments to see if the second
value is higher, if so then set highestpaid to second value and continue.
At the end of the loop whatever is the highest, get the attributes of all of that
then print them out.*/
    }
  }
  cout<<"Hishes Paid: "<<highestname<<endl;
  cout<<"Employee ID: "<<employeeid<<endl;
  cout<<"Employer: "<<employer<<endl;
  cout<<"total pay: "<<totalpay<<endl;

}

void serparateAndSave(vector<Person>*employees){
ofstream outfile;
string boeing = "Boeing";
outfile.open("Boeing.txt");
float boeingtotal=0.00;
for(int i=0; i<employees->size();i++){
  if (boeing == employees -> at(i).getCompanyName()){
     outfile << fixed << setprecision(2);
    outfile<<employees->at(i).fullName()<<" ";
    outfile<<employees->at(i).getEmployeeId()<<" ";
    outfile<<employees->at(i).getCompanyName()<<" ";
    outfile<<employees->at(i).totalPay()<<endl;
    boeingtotal+=employees->at(i).totalPay();
  }
/*comparing company names and outfiling them together based on the company name*/
}
cout << fixed << setprecision(2);
  outfile<<"Total: $"<<boeingtotal<<endl;
outfile.close();

outfile.open("Intel.txt");
string intel = "Intel";
float inteltotal=0.00;
for(int i=0; i<employees->size();i++){
  if (intel == employees -> at(i).getCompanyName()){
    outfile<<setw(5)<<employees->at(i).fullName()<<" ";
    outfile<<setw(5)<<employees->at(i).getEmployeeId()<<" ";
    outfile<<setw(5)<<employees->at(i).getCompanyName()<<" ";
    outfile<<setw(5)<<employees->at(i).totalPay()<<endl;
      inteltotal+=employees->at(i).totalPay();
  }
}
outfile<<"Total: $"<<inteltotal<<endl;
outfile.close();

outfile.open("Douglas.txt");
string douglas = "Douglas";
float douglastotal=0.00;
for(int i=0; i<employees->size();i++){
  if (douglas == employees -> at(i).getCompanyName()){
    outfile<<employees->at(i).fullName()<<" ";
    outfile<<employees->at(i).getEmployeeId()<<" ";
    outfile<<employees->at(i).getCompanyName()<<" ";
    outfile<<employees->at(i).totalPay()<<endl;
    douglastotal+=employees->at(i).totalPay();
  }
}
outfile<<"Total: $"<<douglastotal<<endl;
outfile.close();

outfile.open("Raytheon.txt");
string raytheon = "Raytheon";
float raytheontotal=0.00;
for(int i=0; i<employees->size();i++){
  if (raytheon == employees -> at(i).getCompanyName()){
    outfile<<employees->at(i).fullName()<<" ";
    outfile<<employees->at(i).getEmployeeId()<<" ";
    outfile<<employees->at(i).getCompanyName()<<" ";
    outfile<<employees->at(i).totalPay()<<endl;
    raytheontotal+=employees->at(i).totalPay();
  }
}
outfile<<"Total: $"<<raytheontotal<<endl;
outfile.close();

outfile.open("HealthTech.txt");
string healthtech = "HealthTech";
float healthtechtotal=0.00;
for(int i=0; i<employees->size();i++){
  if (healthtech == employees -> at(i).getCompanyName()){
    outfile<<employees->at(i).fullName()<<" ";
    outfile<<setw(3)<<employees->at(i).getEmployeeId()<<" ";
    outfile<<setw(10)<<employees->at(i).getCompanyName()<<" ";
    outfile<<setw(2)<<employees->at(i).totalPay()<<endl;
    healthtechtotal+=employees->at(i).totalPay();
  }
}
outfile<<"Total: $"<<healthtechtotal<<endl;
outfile.close();
}

int main(){
vector<Person> employees;
vector<string> companynames;
readData(&employees);
getCompanies(&companynames, &employees);
printHighestPaid(&employees);
serparateAndSave(&employees);
  return 0;

}
