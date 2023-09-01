#include<fstream>
#include<iostream>
#include<string>
using namespace std::filesystem;

class Admin{

    private:
    char *name;
    char *password;
    fstream APPLICATION_APPROVAL_RECORD;
    fstream APPLICATION_REJECTION_RECORD;
    string APPLICATION_DIRECTORY;
    private:
    void readApplications(){
        for(auto f = directory_iterator(APPLICATION_DIRECTORY)){
            if (!is_directory(i->path())) //we eliminate directories
        {
            cout << i->path().filename().string() << endl;
        }
        }
    }
	 cout<<"\nserializing...";
	 out<<ba.bankAccountNumber<<"\n"<<ba.bankAccountHolder<<"\n"<<ba.bankAccountBalance<<endl;
	 return out;
 }
   ostream& operator<<(ostream &out, BankAccount &ba)
 {

 istream& operator>>(istream &in, BankAccount &ba)
 {
	 cout<<"\nde-serializing...";
	 in>>ba.bankAccountNumber;
	 in>>ba.bankAccountHolder;
	 in>>ba.bankAccountBalance;
	 return in;
 } 
    void acceptApplication(int applicationId, )
}