#pragma once
#ifndef USER_DAO
#define USER_DAO
#include "../bean/User.h"
#include<string>
#include<set>

class UserDAO{
    public:
    virtual User createUser(long int user_id,string name, string passwd, bool isAdmin)=0;
    virtual bool matchUser(long int user_id, string passwd)=0;
    virtual User getUser(long int user_id)=0;
    virtual void saveToFile()=0;
    virtual void readFromFile()=0;
    virtual void deleteUser(User user)=0;
    // virtual void addApplication(User user, long int application)=0;
    // virtual bool deleteApplication(User user, long int application)=0;
    // virtual set<long int> getApplications(User user)=0;
    // virtual bool isAdmin(User user)=0;
};
#endif