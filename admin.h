#include"person.h"
#include"restaurant.h"
class admin:public person
{
    veg v[10];
    nonveg n[10];
    dessert d[10];
    int num_vegrestaurant;
    int num_nvrestaurant;
    int num_dessertrestaurant;
public:
    admin()
    {
        num_vegrestaurant=0;
        num_nvrestaurant=0;
        num_dessertrestaurant=0;
    }
    bool checkinfo();
    void addvegrestaurant(vegmenu&);
    void addnonvegrestaurant(nonvegmenu&);
    void adddessertrestaurant(dessertmenu&);
    void modifyrestaurant();
    void restaurants();
    void readrestaurantfile();
    void d_restaurants(int);
};




