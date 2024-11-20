
#include<string>
using namespace std;
class food
{
    protected:
    string name;
    float price;
public:
    string getname(){return name;}
    float getprice(){return price;}
    void setname(string name1){name=name1;}
    void setprice(float p){price=p;}

    void addfood();
    void displayfood();

};



