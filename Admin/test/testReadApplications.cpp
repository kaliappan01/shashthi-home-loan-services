#include<bits/stdc++.h>
// #include <iostream>
// #include <filesystem>
// #include <iostream>
// #include <string>
using namespace std;
void readApplications(string APPLICATION_DIRECTORY){
        for(auto f : std::filesystem::directory_iterator(APPLICATION_DIRECTORY)){
            // cout << typeid(f) <<endl;
            cout << f << endl;
            if (!std::filesystem::is_directory(f->path())) //we eliminate directories
        {
            cout << f->path().filename().string() << endl;
        }
        }
    }

int main(){
    readApplications("C:\\Users\\kaliappan.yadav\\Documents\\workspace\\Training\\c++");
}

