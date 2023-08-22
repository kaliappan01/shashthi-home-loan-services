#include <iostream>
#include <string>
#include <fstream>
#include "../headers/Application.h"
using namespace std;

int main(){
  /*
  Clears the file for development purpose
  */
  ofstream ofs;
  ofs.open("../data/applications.txt", ofstream::out | ofstream::trunc);
  ofs.close();

  Application application(
    2,
    "A big house",
    8000000,
    100000,
    "PANXXXX",
    "AAXXXX"
  );
  Application application2(
    3,
    "A smaller house",
    5000000,
    100000,
    "PANX",
    "AAX"
  );

  // Saving application object to file
  application.saveToFile();

  // Reading application vector from file
  vector<Application> applications = Application::retrieveApplications();

  // Looping over vector and printing details of applications
  for (auto& application : applications){
    application.printDetails();
  }
  return 0;
}