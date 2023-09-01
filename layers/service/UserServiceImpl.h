#include<string>
#include "../repository/UserDAO.h"
#include "UserService.h"
class UserServiceImpl: public UserService{
    private:
    bool isAuthenticated;
    UserDAO *user_dao_obj;
    public:
    UserServiceImpl(UserDAO *user_dao_obj){
        this->isAuthenticated=false;
        this->user_dao_obj= user_dao_obj;
        this->user_dao_obj->readFromFile();
    }
    virtual bool userIsAdmin(User user){
        return user.getIsAdmin();
    }
    User createUser(long int user_id,string name, string passwd, bool is_admin){
        User user_obj = this->user_dao_obj->createUser(user_id, name, passwd, is_admin);
        return user_obj;
    }
    void deleteUser(User user){
        this->user_dao_obj->deleteUser(user);
    }
    virtual bool login(User &user){
        this->isAuthenticated = this->user_dao_obj->matchUser(user.getUser_id(), user.getPasswd());
        // std::cout << this->user_dao_obj->getUser(user.getUser_id()).;
        user = this->user_dao_obj->getUser(user.getUser_id());
        return this->isAuthenticated;
    }
    virtual bool logout(User user){
        this->isAuthenticated = false;
        return true;
    }
    virtual bool isAdmin(User user){
        return user.getIsAdmin();
    }
};