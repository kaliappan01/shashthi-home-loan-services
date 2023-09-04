#include "../User.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    User user_obj = User();
    User user_obj_1 = User(101,"kp","passkali", true);
    cout << user_obj<<endl;
    cout << user_obj_1<<endl;
    ofstream writer("../../db/users.txt",ios::app);
    ifstream file("../../db/users.txt");
    // layers/db/users.txt
    if (file.is_open()){
        string line;
        // getline(file, line);
        // cout<<"line : "<<line<<endl;
        file>>user_obj;
        cout<<user_obj;
        writer<<user_obj_1;
    }
    return 1;
}