#include <iostream>
#include <string>
#include "../headers/Application.h"
using namespace std;

int main(){
  Application application(
    "A big house",
    8000000,
    100000,
    "PANXXXX",
    "AAXXXX"
  );
  Application application2(
    "A smaller house",
    8000000,
    100000,
    "PANXXXX",
    "AAXXXX"
  );
  cout<<Application::applicationCount<<endl;
  return 0;
}