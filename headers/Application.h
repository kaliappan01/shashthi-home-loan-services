#include <iostream>
#include <string>
#include <random>
using namespace std;

/*
Application Form
*/
class Application {
  private:
    struct PropertyDetails {
      string propertyName;
      int propertyCost;
    };
    struct IncomeDetails {
      int salary;
    };
    struct DocumentDetails {
      string PAN;
      string Aadhaar;
    };
    enum status { PENDING, REJECTED, APPROVED }; 

    int applicationID;
    enum status applicationStatus;
    PropertyDetails propertyDetails; 
    IncomeDetails incomeDetails;
    DocumentDetails documentDetails;

  public:
    inline static int applicationCount = 0;

    Application(string propertyName, int propertyCost, int salary, string PAN, string Aadhaar, status=PENDING){
      propertyDetails.propertyName = propertyName;
      propertyDetails.propertyCost = propertyCost;
      incomeDetails.salary = salary;
      documentDetails.PAN = PAN;
      documentDetails.Aadhaar = Aadhaar;
      srand((unsigned) time(NULL));
      applicationID = rand(); 
      ++applicationCount;
    }

    void approveApplication(){
      applicationStatus = APPROVED;
    }

    void rejectApplication(){
      applicationStatus = REJECTED;
    }
};