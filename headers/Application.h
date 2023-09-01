#include <bits/stdc++.h>
// #include "calculators.h"
#include<iostream>
#include<fstream>
using namespace std;

/*
Application Form
*/
class Application
{

private:
  long int applicationID = rand();
  long int applicantID;
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
  string applicationStatus;
  public:
  inline static long int applicationCount = 0;
friend istream& operator>>(istream &in, Application &a);
 Application(long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
  {
    this->applicantID = applicantID;
    this->propertyName = propertyName;
    this->propertyCost = propertyCost;
    this->salary = salary;
    this->PAN = PAN;
    this->Aadhaar = Aadhaar;
    this->applicationStatus = applicationStatus;
    ++applicationCount;
  }
  Application(long int applicationID, long int applicantID = 0, string propertyName = "", int propertyCost = 0, int salary = 0, string PAN = "", string Aadhaar = "", string applicationStatus = "PENDING")
  {
    this->applicationID = applicationID;
    this->applicantID = applicantID;
    this->propertyName = propertyName;
    this->propertyCost = propertyCost;
    this->salary = salary;
    this->PAN = PAN;
    this->Aadhaar = Aadhaar;
    this->applicationStatus = applicationStatus;
  }
  
  void printDetails()
  {
    cout << "Application ID: " << this->applicationID << endl;
    cout << "applicantID: " << this->applicantID << endl;
    cout << "propertyName: " << this->propertyName << endl;
    cout << "propertyCost: " << this->propertyCost << endl;
    cout << "salary: " << this->salary << endl;
    cout << "PAN: " << this->PAN << endl;
    cout << "Aadhaar: " << this->Aadhaar << endl;
    cout << "applicationStatus: " << this->applicationStatus << endl;
    cout << "-----------------" << endl;
  }

  long int getApplicationID()
  {
    return applicationID;
  }

  void approveApplication()
  {
    applicationStatus = "APPROVED";
  }

  void rejectApplication()
  {
    applicationStatus = "REJECTED";
  }

  void saveToFile()
  {
    ofstream file("../data/applications.txt", ios::app);
    if (file.is_open())
    {
      file << applicationID << " " << applicantID << " " << applicationStatus << " " << propertyName << " " << propertyCost << " " << salary << " " << PAN << " " << Aadhaar << "\n";
    }
    else
    {
      cerr << "Unable to open file for writing" << endl;
    }
    file.close();
  }

  static vector<Application> retrieveApplications()
  {
    vector<Application> result;

    ifstream input("../data/applications.txt");
    if (input)
    {

      string line;
      while (getline(input, line))
      {

        istringstream iss(line);
        long int applicationID;
        long int applicantID;
        string applicationStatus;
        string propertyName;
        long int propertyCost;
        long int salary;
        string PAN;
        string Aadhaar;

        iss >> applicationID;
        iss >> applicantID;
        iss >> applicationStatus;
        iss >> propertyName;
        iss >> propertyCost;
        iss >> salary;
        iss >> PAN;
        iss >> Aadhaar;
        Application tempApp(applicationID, applicantID, propertyName, propertyCost, salary, PAN, Aadhaar, applicationStatus);
        result.push_back(tempApp);
      }
    }
    return result;
  }
  friend void getEMI(Application *applicant,int tenure_in_months);
  friend void isEligibleForLoan(Application *applicant);
};

  void isEligibleForLoan(Application *applicant){
    long int salary = applicant->salary;
    float PART_OF_THE_SALARY=0.6;
    const int LOAN_ELIGIBILITY_CONSTANT =  60*PART_OF_THE_SALARY;
    bool isEligible = LOAN_ELIGIBILITY_CONSTANT*(applicant->salary)<=(applicant->propertyCost);
    cout << (isEligible?"YES":"NO")<<endl;
}


void getEMI(Application *application,int tenure_in_months){
    const int RATE_OF_INTEREST =  8.5;
    float compounded_rate = pow(1+RATE_OF_INTEREST, tenure_in_months);
    float denominator = (double)(compounded_rate-1);
    float numerator = application->propertyCost*RATE_OF_INTEREST*compounded_rate;
    cout <<"Rs." << fixed <<setprecision(2) << (numerator/denominator)<<endl;
}
 istream& operator>>(istream &in, Application &a)
{

  string line;
  getline(in, line);
  // cout  << line;
  // while(in!=)
  std::stringstream ss(line);
  // cout << in.getline();
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
 