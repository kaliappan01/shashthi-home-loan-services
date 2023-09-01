#ifndef USER_SERVICE
#define USER_SERVICE
#include "../bean/User.h"
#include<cstring>

class UserService{
    public:
    virtual bool login(User &user)=0;
    virtual User createUser(long int user_id,string name, string passwd, bool is_admin)=0;
    virtual void deleteUser(User user)=0;
    virtual bool userIsAdmin(User user)=0;
    virtual bool logout(User user)=0;
    virtual bool isAdmin(User user)=0;
};
#endif