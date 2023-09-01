#include "UI.h"
#include <string>
using namespace std;

class UIImpl:public UI{
    public:
    void userAuthenticationMssg(bool authenticated){
        if (authenticated){
            cout << "You have logged in";
        }
        else{
            cout <<"Invalid Credentials, Please Try again!!";
        }
    }
    

    int menuPrompt(bool is_admin){
        if (is_admin){
            return menuPromptAdmin();
        }
        else{
            return menuPromptUser();
        }
    }
    int menuPromptAdmin(){
        cout << "[1] Print All Applications\n";
        cout << "[2] Reject Application\n";
        cout << "[3] Accept Application\n";
        cout << "[0] Exit";
        int choice = -1;
        cout << "Enter your choice : ";
        cin >> choice;
        return choice;
    }
    pair<long int, string> loginPrompt(){
        string passwd;
        string user_id_str;
        long int user_id;
        cout << "Enter user name : ";
        cin >> user_id;
        cout << "Enter password : ";
        cin >> passwd;
        cout << "(user_id, pass): "<<user_id<<","<<passwd;
        // user_id = strtold(user_id);
        return make_pair(user_id, passwd);
    }
    int userIdPrompt(){
             int user_id;
            cout << "Enter User id to be rejected : ";
            cin >> user_id;
            return user_id;
    }
    int menuPromptUser(){
        cout << "[1] Print My Applications\n";
        cout << "[2] Check Status of My applications"<<endl;
        cout << "[0] Exit "<<endl;
        int choice = -1;
        cout << "Enter your choice : ";
        cin >> choice;

        return choice;
    }

};