#include "../bean/Application_bean.h"
#include<set>
#include <unordered_map>
class ApplicationDAO{
    public:
    // contains basic low-level operations to be performed on the beans
    virtual Application createApplication( long int applicantID,string propertyName,long int propertyCost,long int salary,string PAN,string Aadhar)=0;
    virtual void printDetails(long int application_id)=0;
    virtual void saveToFile()=0;
    virtual Application&  getApplication(long int application_id)=0;
    virtual void printAllApplications()=0;
    virtual unordered_map<long int, Application>& retrieveApplications()=0;
    virtual void updateApplication(long int application_id, string status)=0;
  };