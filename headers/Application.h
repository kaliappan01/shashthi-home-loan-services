#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <vector>
using namespace std;

/*
Application Form
*/
class Application {
  private:
    long int applicationID;
    long int applicantID;
    string propertyName;
    long int propertyCost;
    long int salary;
    string PAN;
    string Aadhaar;
    string applicationStatus;

  public:
    inline static long int applicationCount = 0;

    Application(long int applicantID=0, string propertyName="", int propertyCost=0, int salary=0, string PAN="", string Aadhaar="", string applicationStatus="PENDING"){
      srand((unsigned) time(NULL));
      applicationID = rand(); 
      this->applicantID = applicantID;
      this->propertyName = propertyName;
      this->propertyCost = propertyCost;
      this->salary = salary;
      this->PAN = PAN;
      this->Aadhaar = Aadhaar;
      this->applicationStatus = applicationStatus;
      ++applicationCount;
    }
    
    void printDetails(){
      cout<<"Application ID: "<<applicationID<<endl;
    }

    long int getApplicationID(){
      return applicationID;
    }

    void approveApplication(){
      applicationStatus = "APPROVED";
    }

    void rejectApplication(){
      applicationStatus = "REJECTED";
    }

    void saveToFile() {
      ofstream file("../data/applications.txt", ios::app);
      if (file.is_open()){
        file<<"Application ID: "<<applicationID<<"\n";
        file<<"Applicant ID: "<<applicantID<<"\n";
        file<<"Application Status: "<<applicationStatus<<"\n";
        file<<"Property Name: "<<propertyName<<"\n";
        file<<"Property Cost: "<<propertyCost<<"\n";
        file<<"Salary: "<<salary<<"\n";
        file<<"PAN: "<<PAN<<"\n";
        file<<"Aadhaar: "<<Aadhaar<<"\n";
        file<<"\n";
      } else {
        cerr<<"Unable to open file for writing"<<endl;
      }
    }

    static vector<Application> retrieveApplications(){
      vector<Application> applications;
      ifstream file("../data/applications.txt");
      if(file.is_open()){
        string line;
        Application tempApp;
        while(getline(file, line)){
          if (line.empty()){
            applications.push_back(tempApp);
            tempApp = Application();
          }
          if(line.find("Applicant ID: ") != string::npos){
            tempApp.applicantID = stoi(line.substr(14));
          } else if (line.find("Application Status: ") != string::npos){
            tempApp.applicationStatus = line.substr(20);
          } else if (line.find("Property Name: ") != string::npos){
            tempApp.propertyName = line.substr(15);
          } else if (line.find("Property Cost: ") != string::npos){
            tempApp.propertyCost = stoi(line.substr(15));
          } else if (line.find("Salary: ") != string::npos){
            tempApp.salary = stoi(line.substr(8));
          } else if (line.find("PAN: ") != string::npos){
            tempApp.PAN = line.substr(5);
          } else if (line.find("Aadhaar: ") != string::npos){
            tempApp.Aadhaar = line.substr(9);
          }
        }
        file.close();
      } else {
        cerr << "Unable to open file for reading" << endl;
      }
      return applications;
    }    
};