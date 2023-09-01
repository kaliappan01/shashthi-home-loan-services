#ifndef USER_H
#define USER_H
#include<vector>
#include<string>
#include<set>
#include<string>
#include<iostream>
using namespace std;
class User{
    private:
    bool isAdmin;
    string name;
    long int user_id;
    string passwd;
    // set<long int> applications;
    public:
friend  ostream &operator<<(ostream &out,User &user);
   friend istream &operator>>(istream &in, User &user);
    User(long int user_id=-1, string passwd=""){
        this->user_id = user_id;
        this->passwd  = passwd;
    }
    User(string name,string passwd, bool isAdmin=false){
        this->isAdmin= isAdmin;
        this->name = name;
        this->passwd = passwd;
        this->user_id = rand();
    }
    
    public :
    // void setApplications(set<long int> applications){
    //     this->applications= applications;
    // }
   
    // set<long int> getApplications(){
    //     return this->applications;
    // }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return this->name;
    }
    bool getIsAdmin(){
        return isAdmin;
    }
    long int getUser_id(){
        return this->user_id;
    }
    string getPasswd(){
        return this->passwd;
    }
};
// string setToString(set<long int> ids){
//     string line = "";
//     std::istringstream ss(line);
//     for(auto id: ids){
//         ss << id <<",";
//     }
//     return ss.str();
// }
// set<long int> stringToSet(string s){
// set<long int> csv_set;
// std::stringstream ss(s);
// std::string csv;
// while(getline(ss, csv,',')){
//     csv_set.insert(stold(csv));
// }
// return csv_set;
// }

istream &operator>> (istream &in, User &user){
    string user_id_str;
    in>>user.user_id;
    in>>user.name;
    in>>user.passwd;
    in>>user.isAdmin;
    return in;
}
    ostream &operator<< (ostream &out,User &user){
        out << user.user_id << " " <<user.name << " "<<user.passwd << " "<<user.isAdmin<<"\n"; 
        return out;
     } 

#endif