// #include "../headers/calculators.h"
#include "../headers/Application.h"
#include<fstream>

int main(){
    
  // Reading application vector from file
  vector<Application> applications = Application::retrieveApplications();

  // Looping over vector and printing details of applications
  for (auto &application_ : applications)
  {
    getEMI(application_,10);
    isEligibleForLoan(application_);
  }
}