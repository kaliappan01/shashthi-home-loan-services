#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
Application Form
*/
class Application {
  private:
    enum status { PENDING, REJECTED, APPROVED }; 

    string propertyName;
    int propertyCost;
    int salary;
    string PAN;
    string Aadhaar;
    int applicationID;
    enum status applicationStatus;

  public:
    inline static int applicationCount = 0;

    Application(string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, status=PENDING){
      propertyName = propertyName;
      propertyCost = propertyCost;
      salary = salary;
      PAN = PAN;
      Aadhaar = Aadhaar;
      srand((unsigned) time(NULL));
      applicationID = rand(); 
      ++applicationCount;
      /*
        Serialization and file write functionality
      */
    }

    void approveApplication(){
      applicationStatus = APPROVED;
    }

    void rejectApplication(){
      applicationStatus = REJECTED;
    }
};