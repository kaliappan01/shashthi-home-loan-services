#include <bits/stdc++.h>
using namespace std;

template<typename T> class AnyPair{
    T i;
    T j;

    public :
    AnyPair(T i, T j){
        this->i = i;
        this->j = j;
    }
    void show(){
        cout << this->i <<endl;
        cout << this->j <<endl;

    }
    void swap(){
        int t = this->i;
        this->i = this.j;
        this->j = t;
    }
};

int main(){
    AnyPair<int> int_pair(2.3,4);
    int_pair.show();
    AnyPair<float> float_pair(4.566,6);
    float_pair.show();
}