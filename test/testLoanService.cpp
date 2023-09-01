#include "../../layers/service/Loan_Application_service.h"
#include<fstream>
int main(){
    
    Loan_Application_service loan_app_service_obj =Loan_Application_service();
    loan_app_service_obj.fetchAllApplications(1,true);
    return 1;
}