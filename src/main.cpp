#include <bits/stdc++.h>
#include "../headers/Application.h"
using namespace std;

int main()
{
  srand((unsigned)time(NULL));
  /*
  Clears the file for development purpose
  */
  // ofstream ofs;
  // ofs.open("../data/applications.txt", ofstream::out | ofstream::trunc);
  // ofs.close();

  Application application(
      4,
      "A_big_house",
      8000000,
      100000,
      "PANXXXX",
      "AAXXXX");
  Application application2(
      5,
      "A_smaller_house",
      5000000,
      100000,
      "PANX",
      "AAX");

  // Saving application object to file
  application.saveToFile();
  application2.saveToFile();

  // Reading application vector from file
  vector<Application> applications = Application::retrieveApplications();

  // Looping over vector and printing details of applications
  for (auto &application_ : applications)
  {
    application_.printDetails();
  }
  return 0;
}