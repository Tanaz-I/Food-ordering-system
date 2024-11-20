
#include"menu.h"
#include"location.h"
class restaurant
{
    protected:
    int r_id;
    string name1;
    float offer;
    int l_id;
    location l;
public:
    int getid(){return r_id;}
    string getname(){return name1;}
    float getoffer(){return offer;}
    void getdetails();
    int getl_id(){return l_id;}
    void modifydetails();
    void c_vegrestaurant();
    void c_nvegrestaurant();
    void c_desserts();
    void setid(int id){r_id=id;}
    void setname(string n){name1=n;}
    void setoffer(float f){offer=f;}
    void setlid(int li){l_id=li;}
    void setlocation(location l1)
    {
        l=l1;
    }

};
class veg:public restaurant
{
    vegmenu v;
public:
    void setmenu(vegmenu &vm)
    {
        v=vm;
    }
};
class nonveg:public restaurant
{
    nonvegmenu n;
public:
    void setmenu(nonvegmenu &nv)
    {
        n=nv;
    }
};
class dessert:public restaurant
{
    dessertmenu d;
public:
    void setmenu(dessertmenu &des)
    {
        d=des;
    }
};



