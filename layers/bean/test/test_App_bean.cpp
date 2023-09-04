#include "../Application_bean.h"
#include<bits/stdc++.h>

using namespace std;

int main(){
    Application app_obj = Application();
    app_obj.setApplicationStatus("PENDING");
    cout << app_obj<<endl;
    ofstream writer("../../db/applications.txt",ios::app);
    ifstream file("../../db/applications.txt");
    // layers/db/users.txt
    if (file.is_open()){
        string line;
        // getline(file, line);
        // cout<<"line : "<<line<<endl;
        file>>app_obj;
        cout<<app_obj;
        app_obj.setApplicationStatus("ACCEPTED");
        writer<<app_obj;
        cout<<app_obj;
    }
    return 1;
}