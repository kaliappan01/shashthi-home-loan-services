
// #ifndef APP_SERVICE_IMPL
#define APP_SERVICE_IMPL
#include "../repository/ApplicationDAOImpl.h"
#include "AppService.h"
#include <string>

class AppServiceImpl {
    private :
    ApplicationDAO *app_dao_obj;

    public:
    AppServiceImpl(ApplicationDAO *app_dao_obj){
        this->app_dao_obj=app_dao_obj;
    }
    Application createApplication( long int applicantID,string propertyName,long int propertyCost,long int salary,string PAN,string Aadhar){
        Application app_obj = this->app_dao_obj->createApplication( applicantID, propertyName, propertyCost, salary,PAN, Aadhar);
        return app_obj;
    }

  bool isEligibleForLoan(long int applicationId){
    Application application = this->app_dao_obj->getApplication(applicationId);
    long int salary = application.getSalary();
    float PART_OF_THE_SALARY=0.6;
    const int LOAN_ELIGIBILITY_CONSTANT =  60*PART_OF_THE_SALARY;
    bool isEligible = LOAN_ELIGIBILITY_CONSTANT*(application.getSalary())<=(application.getPropertyCost());
    return isEligible;
}
   
double getEMI(long int application_id,int tenure_in_months){
    Application targetApplication = this->app_dao_obj->getApplication(application_id);
    const int RATE_OF_INTEREST =  8.5;
    float compounded_rate = pow(1+RATE_OF_INTEREST, tenure_in_months);
    float denominator = (double)(compounded_rate-1);
    float numerator = targetApplication.getPropertyCost()*RATE_OF_INTEREST*compounded_rate;
    return (double)numerator/(double)denominator;
    }
    
    void printAllApplications(){
        this->app_dao_obj->printAllApplications();
    }
    void fetchUserApplications(long int user_id){
       unordered_map<long int, Application> applications = this->app_dao_obj->retrieveApplications();
        vector<long int> filtered_app_ids;
            for(auto application: applications){
                if (application.second.getApplicantID()==user_id){
                    filtered_app_ids.push_back(application.first);
                }
            }
            AppServiceImpl::printApplications(filtered_app_ids);
    } 
    void fetchAllApplications(string status="all"){
        unordered_map<long int, Application> applications = this->app_dao_obj->retrieveApplications();
        vector<long int> filtered_app_ids;
        if (status!="all"){
            for(auto application: applications){
                if (application.second.getApplicationStatus()!=status){
                    filtered_app_ids.push_back(application.first);
                }
            }
        }
        AppServiceImpl::printApplications(filtered_app_ids);
    }
    void printApplications(vector<long int> application_ids){
        for(auto application_id: application_ids){
            this->app_dao_obj->printDetails(application_id);
        }
    }

    void saveApplications(){
        this->app_dao_obj->saveToFile();
    }
void rejectApplication(long int application_id)
  {
    this->app_dao_obj->updateApplication(application_id, "REJECTED");
  }

  void approveApplication(long int application_id)
  {
    this->app_dao_obj->updateApplication(application_id, "APPROVED");
  }
   
};
// #endif