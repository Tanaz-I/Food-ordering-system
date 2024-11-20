
#include<string>
using namespace std;
class person
{
protected:
    string name;
    string password;
public:
    void getinfo();
};
class customer:public person
{
public:
    int registrations();
};




