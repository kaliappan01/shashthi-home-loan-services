#pragma once
#include "ApplicationDAOImpl.h"
// #include "../bean/Application_bean.h"
using namespace std;
int main(){
    ApplicationDAO *app_dao_obj = new ApplicationDAOImpl("../db/applications.txt");
    unordered_map<long int , Application> data = app_dao_obj->retrieveApplications();
    // cout<<"hi";
    cout << data.size();
    // for(auto x: data){
    //     app_dao_obj->printDetails(x.second);
    // }
    
    Application test_app_obj = app_dao_obj->createApplication(101, "Penthouse", 15000000,1450000,"7899","213231231232");
    // app_dao_obj->getApplication(test_app_obj.getApplicationID());
    // app_dao_obj->printDetails(test_app_obj.getApplicationID());
    // app_dao_obj->getEMI(test_app_obj.getApplicationID(),12);
    // app_dao_obj->approveApplication(test_app_obj);
    // if (data[test_app_obj.getApplicationID()].getApplicationStatus()=="APPROVED"){
    //     cout << "approve working "<<endl;
    // }
    app_dao_obj->printAllApplications();
    // app_dao_ob/j->saveToFile();
    // app_dao_obj->rejectApplication(test_app_obj);
    // if (data[test_app_obj.getApplicationID()].getApplicationStatus()=="REJECTED"){
    //     cout << "reject working "<<endl;
    // }
    // cout << test_app_obj.getApplicationStatus()<<endl;
    // cout << app_dao_obj->isEligibleForLoan(test_app_obj);
    // app_dao_obj->saveToFile(data);

    // virtual void saveToFile(string directory, unordered_map<long int,Application> applicationMap)=0;
    // virtual unordered_map<long int, Application> retrieveApplications()=0;
    // virtual double getEMI(Application application,int months)=0;
    // virtual bool isEligibleForLoan(Application application)=0;


    return 1;


}