#include<cmath>
#include "ApplicationDAO.h"
#include <filesystem>
#include <iostream>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <string>
using namespace std;
class ApplicationDAOImpl : public ApplicationDAO
{
  private:
  string application_file;
  string FILE_EXTENSION = ".txt";
  int dirty_bit = 0;
  unordered_map<long int, Application> applications;
  public:
  ApplicationDAOImpl(string application_file){
    this->application_file= application_file;
    // ApplicationDAOImpl::retrieveApplications();
  }
  ~ApplicationDAOImpl(){
    if (this->dirty_bit){
      ApplicationDAOImpl::saveToFile();
    }
  }
  void updateApplication(long int application_id, string status){
    applications[application_id].setApplicationStatus(status);
    dirty_bit=1;
  }
  Application createApplication( long int applicantID,string propertyName,long int propertyCost,long int salary,string PAN,string Aadhar){
    Application application = Application(applicantID,propertyName,propertyCost,salary,PAN,Aadhar,"PENDING");
    dirty_bit = 1;
    applications[application.getApplicationID()] = application;
    saveToFile();
    return application;
  }
  Application& getApplication(long int application_id){
    return applications[application_id];
  }
  void printDetails(long int application_id)
 { 
  Application application  = applications[application_id];
    cout << "Application ID: " << application.getApplicationID() << endl;
    cout << "applicantID: " << application.getApplicantID() << endl;
    cout << "propertyName: " << application.getPropertyName() << endl;
    cout << "propertyCost: " << application.getPropertyCost() << endl;
    cout << "salary: " << application.getSalary() << endl;
    cout << "PAN: " << application.getPAN() << endl;
    cout << "Aadhaar: " << application.getAadhaar() << endl;
    cout << "applicationStatus: " << application.getApplicationStatus() << endl;
    cout << "-----------------" << endl;
  }
    void saveToFile(){
      dirty_bit = 0;
      std:: cout<<"Commit in progress "<<endl;
    ofstream file(this->application_file, ios::in);
    for(auto application: this->applications){
      file << application.second;
    }
  }
  void printAllApplications(){
    for(auto app: applications){

      ApplicationDAOImpl::printDetails(app.first);
    }
  }
    unordered_map<long int, Application>& retrieveApplications(){
    // unordered_map<long int, Application> result;
    if (!applications.size())
    applications.clear();
        ifstream input(this->application_file);
        while (input)
        {
          Application temp_app_obj = Application();
          input>>temp_app_obj;
          // string line;
          // while (getline(input, line))
            applications.insert(make_pair(temp_app_obj.getApplicationID(), temp_app_obj));
          }
          return applications;
      }
    
    };
