#include "../service/UserService.h"
#include "../service/AppServiceImpl.h"
#include "../service/UserServiceImpl.h"
#include "../repository/UserDAOImp.h"
#include "../ui/UI.h"
#include "../repository/UserDAO.h"
#include "../ui/UIImpl.h"
#include "../ui/Form.h"
User user;
static UI *ui_obj;
static UserDAO *user_dao_obj;
static UserService *user_service_obj;
static AppServiceImpl *loan_app_service_obj;
static ApplicationDAO *app_dao_obj;
bool handleAuthentication()
{
    pair<long int, string> user_id_passwd = ui_obj->loginPrompt();
    user = User(user_id_passwd.first, user_id_passwd.second);
    cout << "\ninside handle auth " << user.getPasswd()<<endl;
    bool user_authenticated = user_service_obj->login(user);
    ui_obj->userAuthenticationMssg(user_authenticated);
    return user_authenticated;
}
bool handleAdminChoices(int choice)
{
    switch (choice)
    {
    case 1:
        loan_app_service_obj->printAllApplications();
        break;
    case 2:
        loan_app_service_obj->rejectApplication(ui_obj->userIdPrompt());
        break;
    case 3:
        loan_app_service_obj->approveApplication(ui_obj->userIdPrompt());
        break;
    default:
        cout<<"Exiting application"<<endl;
        loan_app_service_obj->saveApplications();
        return true;
    }
    return false;
}
void handleApplicationSubmission(){
    ApplicationForm submittedForm = Form::applicationSubmission();
    loan_app_service_obj->createApplication(user.getUser_id(),submittedForm.propertyName, submittedForm.propertyCost, submittedForm.salary, submittedForm.PAN, submittedForm.Aadhaar);
}


bool handleUserChoices(int choice)
{
    switch (choice)
    {
    case 1:
        loan_app_service_obj->fetchUserApplications(user.getUser_id());
        break;
    case 2:
        handleApplicationSubmission();
        break;
    default:
        cout << "Exiting application"<<endl;
        loan_app_service_obj->saveApplications();
        return true;
    }
    return false;
}
int main()
{
    ui_obj = new UIImpl();
    app_dao_obj = new ApplicationDAOImpl("../db/applications.txt");
    app_dao_obj->retrieveApplications();
    user_dao_obj = new UserDAOImpl("../db/users2.txt");
    user_dao_obj->readFromFile();
    user_service_obj = new UserServiceImpl(user_dao_obj);
   
    loan_app_service_obj = new AppServiceImpl(app_dao_obj);
    while (!handleAuthentication())
        ;
    int choice = 0;
    bool exit = false;
    while (!exit)
    {choice = ui_obj->menuPrompt(user.getIsAdmin());
        if (user.getIsAdmin())
        {
            exit = handleAdminChoices(choice);
        }
        else
        {
            exit = handleUserChoices(choice);
        }
    }
    return 0;
}