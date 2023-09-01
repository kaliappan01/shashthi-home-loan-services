#ifndef UI_H
#define UI_H
class UI{
    public:
    virtual ~UI() = default;
    virtual void userAuthenticationMssg(bool authenticated)=0;
    virtual pair<long int,string> loginPrompt()=0;
    virtual int menuPrompt(bool is_admin)=0;
    virtual int userIdPrompt()=0;
};
#endif