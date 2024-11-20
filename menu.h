#include"food.h"
class vegmenu
{
    food *veg_starters;
    food *veg_mains;
    food *veg_soup;
    int num_vstarters;
    int num_vmains;
    int num_vsoup;
    void getvstarter();
    void getvmains();
    void getvsoups();
public:
    void createmenu();
    void readfile();
    void displaymenu();
    friend int order(vegmenu &);
};
class nonvegmenu
{
    food *nv_starters;
    food *nv_mains;
    food *nv_soup;
    int num_nvstarters;
    int num_nvmains;
    int num_nvsoup;
    void getnvstarter();
    void getnvmains();
    void getnvsoups();
public:
    void createmenu();
    void readfile();
    void displaymenu();
    friend int order(nonvegmenu &);
};
class dessertmenu
{
    food *icecream;
    food *cake;
    food *specials;
    food *drinks;
    int num_icecream;
    int num_cake;
    int num_specials;
    int num_drinks;
    void geticecream();
    void getcake();
    void getspecials();
    void getdrinks();
public:
    void createmenu();
    void readfile();
    void displaymenu();
    friend int order(dessertmenu &);
};





