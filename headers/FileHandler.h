#include <iostream>
#include <string>
#include <random>
#include <Application.h>
using namespace std;

class FileHandler {
  public:
  ostream& operator<<(ostream &out, Application &application)
  {
    out<<application.applicationID<<"\n"<<application.documentDetails.PAN<<"\n"<<application.propertyDetails.propertyName<<endl;
    return out;
  }

  istream& operator>>(istream &in, Application &application)
  {
      in>>application.applicationID;
      in>>application.documentDetails.PAN;
      in>>application.propertyDetails.propertyName;
      return in;
  }
};