#include <iostream>
#include<fstream>
#include<conio.h>
#include<Windows.h>
#include<iomanip>
#include<unistd.h>
#include"admin.h"
#include"bill.h"
using namespace std;
void admin_work()
{
    admin a;
    vegmenu v,w;
    nonvegmenu n,nw;
    dessertmenu d,dw;
    location l;
    v.readfile();
    n.readfile();
    d.readfile();
    a.readrestaurantfile();
    int ch1;
    string type;
    char ch2;
    a.getinfo();
    if(a.checkinfo())
    {
        do
        {
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n";
            cout<<"\t\t\t\t\t\t\t                    ADMIN OPERATIONS                  \n";
            cout<<"\t\t\t\t\t\t\t  _______________________________________________________\n";
            cout<<"\t\t\t\t\t\t\t |                                                       |\n";
            cout<<"\t\t\t\t\t\t\t |               1      ADD NEW MENU                     |\n";
            cout<<"\t\t\t\t\t\t\t |               2      ADD NEW LOCATION                 |\n";
            cout<<"\t\t\t\t\t\t\t |               3      ADD NEW RESTAURANT               |\n";
            cout<<"\t\t\t\t\t\t\t |               4      MODIFY  RESTAURANT               |\n";
            cout<<"\t\t\t\t\t\t\t |               5      DISPLAY RESTAURANTS              |\n";
            cout<<"\t\t\t\t\t\t\t |_______________________________________________________|\n";
            cout<<"enter choice: ";
            cin>>ch1;
            system("cls");
            switch(ch1)
            {
                case 1:
                    cout<<"veg menu\n";
                    w.createmenu();
                    cout<<"nonveg menu\n";
                    nw.createmenu();
                    cout<<"dessert menu\n";
                    dw.createmenu();
                    break;
                case 2:
                    l.getdetail();
                    l.c_location();
                    break;
                case 3:
                    cout<<"What type of restaurant you want to add? ";
                    cin>>type;
                    if(type=="veg")
                    {
                        a.addvegrestaurant(v);
                    }
                    else if(type=="nonveg")
                    {
                        a.addnonvegrestaurant(n);
                    }
                    else
                    {
                        a.adddessertrestaurant(d);
                    }
                    break;
                case 4:
                    a.modifyrestaurant();
                    break;
                case 5:
                    a.restaurants();
                    break;
                default:
                    cout<<"invalid choice\n";
            }
            cout<<"do you want to continue(y-yes)? ";
            cin>>ch2;
        }while(ch2=='y');
    }
}

int search_food(int type)
{
    fstream f;
    int c;
    if(type==1)
    {
        vegmenu v;
        v.readfile();
        v.displaymenu();
        c=order(v);
    }
    else if (type==2)
    {
        nonvegmenu nv;
        nv.readfile();
        nv.displaymenu();
        c=order(nv);
    }
    else if (type==3)
    {
        dessertmenu d;
        d.readfile();
        d.displaymenu();
        c=order(d);
    }
    return c;
}
void restaurants1(int type)
{
    admin a;
    a.readrestaurantfile();
    cout<<"B"<<endl;
    a.d_restaurants(type);
}
void restaurants(int id)
{
    int r_id;
    int l_id;
    location l;
    string name1;
    float offer;
    ifstream f;
    f.open("Veg_Restaurants.txt",ios::in);
    while(f>>r_id)
    {
        getline(f,name1);
        f>>offer;
        f>>l_id;
        if(id==l_id)
        {
            cout<<name1<<endl;
        }
    }
    f.close();
    f.open("Nonveg_Restaurants.txt",ios::in);
    while(f>>r_id)
    {
        getline(f,name1);
        f>>offer;
        f>>l_id;
        if(id==l_id)
        {
            cout<<name1<<endl;
        }
    }
    f.close();
    f.open("Desserts.txt",ios::in);
    while(f>>r_id)
    {
        getline(f,name1);
        f>>offer;
        f>>l_id;
        if(id==l_id)
        {
            cout<<name1<<endl;
        }
    }
    f.close();
}

int search_cat()
{
    int c,type,c1;
    do{cout<<"Enter your choice: \n1.SEARCH BY FOOD \n2.RESTAURANTS\n: ";
    cin>>c;}while(c!=1&&c!=2);
    if(c==1)
    {
        do{cout<<"Enter your type \n1.VEG \n2.NON-VEG \n3.DESSERTS\n: ";
        cin>>type;}while(type!=1&&type!=2&&type!=3);
        c1=search_food(type);
        restaurants1(type);
    }
    else if(c==2)
    {
        do{
        cout<<"Enter your type \n1.VEG \n2.NON-VEG \n3.DESSERTS\n: ";
        cin>>type;}while(type!=1&&type!=2&&type!=3);
        restaurants1(type);
        c1=search_food(type);
    }
    return c1;

}

int main()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    sleep(3);
    cout<<"\n\n\n\n\n\n\n";
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t\t\t";
    SetConsoleTextAttribute(hConsole, savedAttributes);
    sleep(1);
    cout<<"WELCOME";
    sleep(1);
    cout<<" TO";
    sleep(1);
    cout<<" ONLINE FOOD ";
    sleep(1);
    cout<<"ORDERING SYSTEM\n";
    sleep(1);
    cout<<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tDONE BY\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tNIVITHASRI A\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTANAZ I\n";
    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
    while(getchar()!='\n');
    system("cls");
    SetConsoleTextAttribute(hConsole, savedAttributes);
    int reg;
    int c;
    location l;
    int loc;
    bill b;
    do{
    system("cls");
    cout<<"\n\n\n\n\n\n\n";
    cout << "\t\t\t\t|_______________________________________________________________________|" << endl;
    cout << "\t\t\t\t|-----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                             PRESS [1] ADMIN                           |" << endl;
    cout << "\t\t\t\t|-----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t\t|                             PRESS [2] USER                            |" << endl;
    cout << "\t\t\t\t|-----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t\t|_______________________________________________________________________|" << endl;
    cin>>c;}while(c!=1&&c!=2);
    system("cls");
    if(c==1)
    {
            admin_work();
    }
    else
    {
        customer cl;
        reg=cl.registrations();

        loc=locations(l);
        c=search_cat();
        b.food_ordered(c);
        b.restaurant_choosed(loc,reg);
        cout<<"\n YOUR ORDER IS PLACED"<<endl;

    }
}


