//============================================================================
// Name        : FileStreams.cpp
// Author      : Vishhal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : FileHandlingProject.cpp
// Author      : Vishhal
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>

using namespace std;
/*
 * 						volatile
 * 	reading/input	in the memory		writing / output
 * 	|					|				 |
 * 	keyboard	-->	int num=190;  --> monitor
 * 	|									|
 * 	cin>>num						  cout<<num
 * 	std									std
 *
 *
 * 			File				File
 * 			|					|
 * 			inputstream			outputstream
 * 			|					|
 * 			reading				writing
 * 				|				|
 * 				+--<--abc.txt-<-+
 * 					non-volatile
 *
 * 		keyboard								    monitor
 * 		|												|
 * 		data ---writingstream-->file-->readingstream--data
 *
 *
 *
 * 		ifstream -> read the data from a file
 * 		ofstream -> write the data to a file
 * 		fstream -> read/write data from/to a file
 *
 * 					ios
 * 					 |
 * 				-------------
 * 				|			|
 * 		  istream		     ostream
 * 		  |	|	|			|   |  |
 * 		cin |   |           |   |  cout
 * 	    	|	-------------   |
 * 		ifstream	   |		ofstream
 * 					ostream
 * 					   |
 * 					fstream
 *
 */


/*
void writeToAFile()
{
	ofstream fout;
	cout<<"\nOpening the file...";
	fout.open("/Users/apple/banking.txt",ios::app);
	fout.open("c:\\Users\\bismar\\banking.txt",ios::app);

	cout<<"\nFile is ready...";

	string line; // a blank line

	while(fout) {
		getline(cin,line); //read from the keyboard

		if(line=="-1")
			break;

		fout<<line<<endl; //store this line into the file referred by fout
	}
	cout<<"\nclosing the file...";
	fout.close();
	cout<<"\nFile is closed..";

}*/

void serializeTheObject()
{

}

class BankAccount
{
private:
	int bankAccountNumber;
	string bankAccountHolder;
	float bankAccountBalance;
public:

	BankAccount(int ba=0, string bah="", float bab=0.0) {
		bankAccountNumber=ba;
		bankAccountHolder = bah;
		bankAccountBalance=bab;
	}
	void printBankAccount() {
		cout<<"\nBank Account Number  : "<<bankAccountNumber;
		cout<<"\nBank Account Holder  : "<<bankAccountHolder;
		cout<<"\nBank Account Balance : "<<bankAccountBalance;
		cout<<"\n====================";
	}
	friend ostream& operator<<(ostream &out, BankAccount &ba);
	friend istream& operator>>(istream &in, BankAccount &ba);

};

 ostream& operator<<(ostream &out, BankAccount &ba)
 {
	 cout<<"\nserializing...";
	 out<<ba.bankAccountNumber<<"\n"<<ba.bankAccountHolder<<"\n"<<ba.bankAccountBalance<<endl;
	 return out;
 }

 istream& operator>>(istream &in, BankAccount &ba)
 {
	 cout<<"\nde-serializing...";
	 in>>ba.bankAccountNumber;
	 in>>ba.bankAccountHolder;
	 in>>ba.bankAccountBalance;
	 return in;
 }

 int main() {

 	BankAccount baObj1(102,"Jane",6000);
 	BankAccount baObj2(103,"Julie",7000);
 	BankAccount baObj3(104,"Julia",8000);

 	ofstream fout("banking.data");
 	fout<<baObj1;
 	fout<<baObj2;
 	fout<<baObj3;

 	cout<<"\n====================";

 	BankAccount baObj4;
	BankAccount baObj5;
	BankAccount baObj6;

 	ifstream fin("banking.data");
 	fin >> baObj4;
 	fin >> baObj5;
 	fin >> baObj6;

 	baObj4.printBankAccount();
 	baObj5.printBankAccount();
 	baObj6.printBankAccount();


 	return 0;
 }

/*void serializeIt(BankAccount baObj) {  //  <<
	cout << "!!! File Handling !!!"<< endl; // prints !!!Hello World!!!
		ofstream file("bankobjects.dat",ios::app);

		baObj.printBankAccount();

		cout<<"\ntrying to serialize the object...";
		file.write((char*)&baObj, sizeof(baObj));
		cout<<"\nObject is serialized....";


		file.close();
		cout<<"\nFile is closed...";
}

void deSerializeIt() { // >>  operator friend
	cout << "!!! File Handling !!!"<< endl; // prints !!!Hello World!!!
		ifstream file("bankobjects.dat",ios::in);
		//BankAccount baObj;
		BankAccount *baObj = new BankAccount;

		cout<<"\ntrying to de-serialize the object...";
		while(file.read((char*)baObj, sizeof(class BankAccount))) {

			baObj->printBankAccount();
			cout<<"\nbaObj "<<baObj;
			baObj = new BankAccount;
			cout<<"\n-----------";
		}
			cout<<"\nObject is de-serialized....";


		file.close();
		cout<<"\nFile is closed...";
}

int main() {

	BankAccount baObj1(102,"Jane",6000);
	BankAccount baObj2(103,"Julie",7000);
	BankAccount baObj3(104,"Julia",8000);

	//serializeIt(baObj1);
	//serializeIt(baObj2);
	//serializeIt(baObj3);

	deSerializeIt();
	//deSerializeIt();

	return 0;
}
*/



/*
 *
 *
 *
 * 	Serialization
 * 		chopping the object bytes
 * 		in series of bytes on a file
 *
 *
 * 	Persistence
 * 		storing the object
 * 		on the database table as
 * 		a row
 *
 * 		ODBC
 *
 * 		C++ <--Driver-> MSSQL Server
 *
 *
 *
 * 	BankAccount
 * 		private:
 * 			accountNumber
 * 			accountHolder;
 * 			accountBalance;
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */