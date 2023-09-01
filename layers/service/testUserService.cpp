#include "UserServiceImpl.h"
#include "../repository/UserDAOImp.h"
using namespace std;

int main(){
    UserDAO *user_dao_obj = new UserDAOImpl("../db/users.txt");
    UserService *user_serv_obj = new UserServiceImpl(user_dao_obj);
    User test_user = user_serv_obj->createUser(1019168,"kp","pass123", true);
    cout << user_serv_obj->login(test_user);
    return 1;
}