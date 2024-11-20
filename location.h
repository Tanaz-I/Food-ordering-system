#include<string>
using namespace std;
class location
{
    int id;
    string name;
    float  latitude;
    float longtitude;
    public:
        void setdetails(int i,string n,float l,float ln)
        {
            id=i;
            name=n;
            latitude=l;
            longtitude=ln;
        }
        void getdetail();
        void c_location();
        friend int locations(location &);
};



