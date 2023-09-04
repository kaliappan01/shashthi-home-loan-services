#include<sstream>
#include<cstring>
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
// enum Status{
//   PENDING=0,
//   APPROVED=1,
//   REJECTED=-1
// };
class Application
{

private:
  long int applicationID; 
  long int applicantID;
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
  string applicationStatus;
  friend istream& operator>>(istream &in, Application &a);
  friend ostream& operator<<(ostream &out, Application &a);
public :
Application(long int applicantID,string propertyName,long int propertyCost,long int salary,string PAN,string Aadhar,string applicationStatus){
  this->applicantID = applicantID; 
  this->applicationID = rand();
  this->propertyName=propertyName;;
  this->propertyCost = propertyCost;
  this->salary = salary;
  this->PAN = PAN;
  this->Aadhaar = Aadhaar;
  this->applicationStatus = applicationStatus;
}
Application(){
  // this->applicationID = rand();
}
  long int getApplicationID(){
    return this->applicationID;
  } 

  long int getApplicantID(){
    return this->applicantID;
  };


  string getPropertyName(){
return this->propertyName;
  }


  long int getPropertyCost(){
return this->propertyCost;
  }

  long int getSalary(){
return this->salary;
  }

  string getAadhaar(){
return this->Aadhaar;
  }

  string getPAN(){
return this->PAN;
  }

  string getApplicationStatus(){
return this->applicationStatus;
  }
  void setApplicationStatus(string status){
    this->applicationStatus = status;
  }



};
ostream& operator<<(ostream &out, Application &a)

{


  out<<a.getApplicationID()<<" "<<a.getApplicantID()<<" "<<a.getApplicationStatus()<<" "<<a.getPropertyName()<<" "<<a.getPropertyCost()<<" "<<a.getSalary()<<" "<<a.getPAN()<<" "<<a.getAadhaar()<<"\n";

  return out;
}
 istream& operator>>(istream &in, Application &a)
{

  string line;
  getline(in, line);
  std::stringstream ss(line);
  ss>>a.applicationID;
  ss>>a.applicantID;
  ss>>a.applicationStatus;
  ss>>a.propertyName;
  ss>>a.propertyCost;
  ss>>a.salary;
  ss>>a.PAN;
  ss>>a.Aadhaar;
  return in;
}