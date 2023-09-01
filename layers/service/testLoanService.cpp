#include "Loan_Application_service.h"
#include<fstream>
#include<vector>
#include<string>
int main(){
    ApplicationDAO *app_dao_obj = new ApplicationDAOImpl("../db/applications.txt"); 
    Loan_Application_service loan_app_service_obj =Loan_Application_service(app_dao_obj);
    // std::cout << loan_app_service_obj.;
    std::cout<<"back to test "<<endl;
    // loan_app_service_obj.fetchAllApplications(1,true);
    // loan_app_service_obj.printAllApplications();
    Application test_app_obj = loan_app_service_obj.createApplication(1019168,1, "Penthouse, Nerul", 15000000,1450000,"7899","213231231232","PENDING");
    cout << "user id"<<test_app_obj.getApplicantID()<<endl;
    cout << loan_app_service_obj.checkEMI(test_app_obj, 12)<<endl;
    cout << "approval "<< loan_app_service_obj.approveApplication(test_app_obj.getApplicationID())<<endl;
    cout << "eligiblity "<< loan_app_service_obj.isEligibleForLoan(test_app_obj.getApplicationID())<<endl;
    loan_app_service_obj.getStatusOfApplication(1);
    
    return 1;
}