#include "AppServiceImpl.h"

using namespace std;

int main(){
    ApplicationDAO *app_dao = new ApplicationDAOImpl("../db/applications.txt");
    AppServiceImpl app_service_obj = AppServiceImpl(app_dao);
    // unordered_map<long int , Application> applications = app_service_obj.fetchAllApplications();
    // app_service_obj.printAllApplications(applicaitons);
    app_service_obj.fetchAllApplications();
    // app_service_obj.printAllApplications();
    Application test_app = app_service_obj.createApplication(101,1019168,"Penthourse, Nerul", 15000000, 1450000,"adkfald","1345 543 5432");
    app_service_obj.approveApplication(test_app.getApplicationID());
    app_service_obj.printAllApplications();
    std::cout << "after approval";
    app_service_obj.rejectApplication(test_app.getApplicationID());
    app_service_obj.printAllApplications();

}