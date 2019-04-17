//kyle ear Assignment 1
//cpsc 301-03
#include <iostream>
#include <fstream>
#include <string>
#include<cstring>
using namespace std;


struct  PERSON {
	char  Name[20];
	float Balance;
};

void Display(PERSON s[], int sizearray){
	cout << "Name        Balance" << endl;
	for(int i=0;i<sizearray;i++)
	cout << s[i].Name << " " << s[i].Balance << endl;
}//displaying names and balances

void FindRichest(PERSON s[], int sizearray) {
	float richest = 0;
	string richestname;

	for (int i = 0; i < sizearray; i++) {

		if (richest < s[i].Balance) {
			richest = s[i].Balance;
			richestname = s[i].Name;
		}//finding richest. if first balance is less than second
		//then richest=second value and increment and check again through the loop
	}
	cout << "The richest is " << richestname << endl;
}
void Deposit(string CustName, PERSON *s,int sizearray) {
	float enterbalance=0.0;
	int index;
	for (int i = 0; i < sizearray; i++) {
		strcmp(CustName.c_str(), s[i].Name); //converting and comparing string name
		//to the names in the array
		if (CustName == s[i].Name) {
			index = i;//making index = i to use outside loop
			//for whichever input is equal to the customer name
			cout << "Enter the amount you want to deposit " << endl;
			cin >> enterbalance;
			s[index].Balance += enterbalance;
			cout << s[index].Name <<"'s new balance is "<< s[index].Balance << endl;
			/*making index bc i will increment and we dont want it to increment
			and check names if the customer names match.*/
		}
	}
}

void NewCopy(string filename, Person s[], int sizearray) {
	ofstream outfile;
	outfile.open(filename);
	for (int i = 0; i < sizearray; i++) {
		outfile << s[i].Name << " " << s[i].Balance << endl;
	}
	outfile.close();
}



int main() {

	string line;
	PERSON p[5]; //like making 5 structs later well fill the name and blance of those structs with arrays

	ifstream infile;
	infile.open("Data.txt");

	if (!infile) {
		cout << "couldnt open file" << endl;
	}

	string first;
	string last;
	string fullname;
	char name[20];
	float currentbalance;
	string line1;
	int sizearray=0;

	while (getline(infile, line1)) {//to get the size of the array
		sizearray++;//after every line count 1 to sizearray
	}
	infile.close();

	infile.open("Data.txt");
	for (int i = 0; i < sizearray; i++) {

		infile >> first;//infiling all variables of the txt gile
		infile >> last;
		infile >> currentbalance;

		//converting to cstring
		//converts fullname to c string then puts it in array p[i].name
		fullname = first + " " + last;
		strcpy(p[i].Name, fullname.c_str());

		p[i].Balance = currentbalance;
		//settng all balances in struct to txt balance values
	}
	infile.close();

	Display(p, sizearray);
	FindRichest(p, sizearray);

	string custname;
	cout << "please enter name " << endl;
	getline(cin, custname);
	Deposit(custname, p, sizearray);
	Newcopy("Data.txt", p, sizearray);

	system("pause");
	return 0;
}
