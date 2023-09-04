#pragma once
#ifdef APP_SERVICE
#define APP_SERVICE
#include "../bean/Application_bean.h"
#include <unordered_map>

class AppService{
    public:
    virtual Application createApplication( long int applicantID,string propertyName,long int propertyCost,long int salary,string PAN,string Aadhar,string applicationStatus)=0;
    virtual void printAllApplications() = 0;
    virtual void approveApplication(long int application_id)=0;
    virtual double getEMI(long int application_id,int months)=0;
    virtual bool isEligibleForLoan(long int application_id)=0;
    virtual void rejectApplication(long int application_id)=0;
    // virtual unordered_map<long int, Application> fetchApplications(string applicationStatus)=0;
    virtual void saveApplications()=0;
};
#endif