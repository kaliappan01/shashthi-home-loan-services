#pragma once
#include "../bean/User.h"
#include "UserDAO.h"
#include<fstream>
#include<sstream>
#include<iostream>
#include<unordered_map>
class UserDAOImpl: public UserDAO{
    private:
    int dirty_bit = 0;
    string user_file; 
    unordered_map<long int, User> userIdToUser;
    public:
    UserDAOImpl(string user_file){
        this->user_file= user_file;
    }
    User createUser(long int user_id,string name, string passwd, bool is_admin){
        User user_obj = User(name,passwd, is_admin);
        dirty_bit=1;
        userIdToUser.insert(make_pair(user_id, user_obj));
        return user_obj;
    }

    bool matchUser(long int user_id, string passwd){
        if (userIdToUser.find(user_id)!=userIdToUser.end()){
        return userIdToUser[user_id].getPasswd()==passwd;
        }
        return false;
    }
    ~UserDAOImpl(){
        if (dirty_bit){
            saveToFile();
        }
    }
    // void addApplication(User user, long int application_id){
    //     user.getApplications().insert(application_id);
    // }
    // set<long int> getApplications(User user){
    //     return user.getApplications();
    // }
    // bool deleteApplication(User user, long int application_id){
    //     return user.getApplications().erase(application_id);
    // }
    User getUser(long int user_id){
        return this->userIdToUser[user_id];
    }
    void deleteUser(User user){
        dirty_bit = 1;
        if (userIdToUser.find(user.getUser_id())!=userIdToUser.end())
        userIdToUser.erase(user.getUser_id());
    }
    void saveToFile(){
        dirty_bit =0;
        ofstream fstream(user_file, ofstream::app);
        string line;
        if (fstream.is_open()){
            for(auto user: userIdToUser)
            fstream << user.second;
        }
        else{
            cerr <<"Unable to open user file for writing";
        }
    }
     void readFromFile(){
        userIdToUser.clear();
        ifstream istream(user_file);
        while(istream){
            User tempUser(-1,"");
            istream >> tempUser;
            userIdToUser.insert(make_pair(tempUser.getUser_id(), tempUser));
        }
    }
    
};