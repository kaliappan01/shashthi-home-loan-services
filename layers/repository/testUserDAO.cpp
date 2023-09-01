#include"UserDAOImp.h"

using namespace std;
int main(){
    UserDAO *user_dao = new UserDAOImpl("../db/users.txt");
    User test_user = user_dao->createUser(1019168,"kp","pass123",true);
    user_dao->readFromFile();
    cout << test_user<<endl;
    cout<< "is admin : "<<user_dao->isAdmin(test_user)<<endl;
    user_dao->saveToFile();
    cout<<"user login "<<user_dao->matchUser(test_user.getUser_id(), test_user.getPasswd())<<endl;
    return 1;
}