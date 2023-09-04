#include<bits/stdc++.h>
using namespace std;

struct ApplicationForm{
  string propertyName;
  long int propertyCost;
  long int salary;
  string PAN;
  string Aadhaar;
};
class Form{
    public:
    static struct ApplicationForm applicationSubmission(){
        ApplicationForm form;
        cout <<"Fill the Application Form : "<<endl;
      cout<<"Enter property name: ";
      inputValidation(form.propertyName);
      cout<<"Enter property cost: ";
      inputValidation(form.propertyCost);
      cout<<"Enter salary: ";
      inputValidation(form.salary);
      cout<<"Enter PAN: ";
      inputValidation(form.PAN);
      cout<<"Enter Aadhaar: ";
      inputValidation(form.Aadhaar);
      return form;
    }
    static void inputValidation(string &value){
        cin>>value;
        while(1)
    {
        if(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You have entered wrong input.\nEnter again : ";
        cin>>value;
        }
        if(!cin.fail())
        break;
        }
    }
    static void inputValidation(long int &value){
        cin >>value;
       while(1)
{
      if(cin.fail())
        {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"You have entered wrong input"<<endl;
        cin>>value;
        }
        if(!cin.fail())
        break;
        }

    }

};