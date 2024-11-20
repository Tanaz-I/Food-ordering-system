#include <iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include <cmath>
#include<conio.h>
#include<Windows.h>
#define pi 3.14159265358979323846
#include"admin.h"
#include<unistd.h>
#include"bill.h"
using namespace std;

int isname(string name)
{
    int n,k=0,i;
    n=name.length();
    for(i=0;i<n;i++)
    {
        if(isalpha(name[i]))
        {
            k=1;
        }
        else
        {
            k=0;
            break;
        }
    }
    return k;
}
void person::getinfo()
{
    do
    {
     system("cls");
    cout<<"\n\n\n\\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t         ENTER NAME: ";
    cin>>name;
    }while(!isname(name));
    cout<<"\n";
    cout<<"\t\t\t\t\t\t         ENTER PASSWORD: ";
    password="";
    char ch;
    ch=getch();
    while((ch>='a'&&ch>='z')||(ch>='0'&&ch<='9'))
    {
        password+=ch;
        cout<<"*";
        ch=getch();
    }
    cout<<"\n";
    sleep(1);
    system("cls");
}
bool admin::checkinfo()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
WORD savedAttributes;
GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
savedAttributes = consoleInfo.wAttributes;
    if((name=="nivitha"&& password=="26032005")||(name=="tanaz"&&password=="13122004"))
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\tLOGIN VERIFIED\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\tLOGIN VERIFIED\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
        SetConsoleTextAttribute(hConsole, savedAttributes);
        cin.ignore();
        while(getchar()!='\n');
        system("cls");
        return true;
    }
    else
    {
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\tINVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\tINVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        SetConsoleTextAttribute(hConsole, savedAttributes);
        cin.ignore();
        while(getchar()!='\n');
        system("cls");
        return false;
    }
}
void restaurant::getdetails()
{
    cout<<"enter restaurant id: ";
    cin>>r_id;
    do{cout<<"enter restaurant name: ";
    cin.ignore();
    getline(cin,name1);}while(!isname(name1));
    cout<<"enter offer given by the restaurant: ";
    cin>>offer;
    cout<<"Enter location id: ";
    cin>>l_id;
    ifstream f;
    f.open("LOCATIONS.txt",ios::in);
    int id;
    string name;
    float  latitude;
    float longtitude;
    while(f>>id)
    {
        getline(f,name);
        f>>latitude;
        f>>longtitude;
        if(id==l_id)
        {
            l.setdetails(id,name,latitude,longtitude);
        }

    }
}
void food::addfood()
{
    cout<<"enter food name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"enter food price: ";
    cin>>price;
}
void vegmenu::getvstarter()
{
    cout<<"enter how many starters in menu: ";
    cin>>num_vstarters;
    veg_starters=new food[num_vstarters];
    for(int i=0;i<num_vstarters;i++)
    {
        veg_starters[i].addfood();
    }
}
void vegmenu::getvmains()
{
    cout<<"enter how many mains in menu: ";
    cin>>num_vmains;
    veg_mains=new food[num_vmains];
    for(int i=0;i<num_vmains;i++)
    {
        veg_mains[i].addfood();
    }
}
void vegmenu::getvsoups()
{
    cout<<"enter how many soups in menu: ";
    cin>>num_vsoup;
    veg_soup=new food[num_vsoup];
    for(int i=0;i<num_vsoup;i++)
    {
        veg_soup[i].addfood();
    }
}
void nonvegmenu::getnvstarter()
{
    cout<<"enter how many starters in menu: ";
    cin>>num_nvstarters;
    nv_starters=new food[num_nvstarters];
    for(int i=0;i<num_nvstarters;i++)
    {
        nv_starters[i].addfood();
    }
}
void nonvegmenu::getnvmains()
{
    cout<<"enter how many mains in menu: ";
    cin>>num_nvmains;
    nv_mains=new food[num_nvmains];
    for(int i=0;i<num_nvmains;i++)
    {
        nv_mains[i].addfood();
    }
}
void nonvegmenu::getnvsoups()
{
    cout<<"enter how many soups in menu: ";
    cin>>num_nvsoup;
    nv_soup=new food[num_nvsoup];
    for(int i=0;i<num_nvsoup;i++)
    {
        nv_soup[i].addfood();
    }
}
void dessertmenu::getcake()
{
    cout<<"enter how many cake types in menu: ";
    cin>>num_cake;
    cake=new food[num_cake];
    for(int i=0;i<num_cake;i++)
    {
        cake[i].addfood();
    }
}
void dessertmenu::geticecream()
{
    cout<<"enter how many icecream types in menu: ";
    cin>>num_icecream;
    icecream=new food[num_icecream];
    for(int i=0;i<num_icecream;i++)
    {
        icecream[i].addfood();
    }
}
void dessertmenu::getspecials()
{
    cout<<"enter how many specials in menu: ";
    cin>>num_specials;
    specials=new food[num_specials];
    for(int i=0;i<num_specials;i++)
    {
        specials[i].addfood();
    }
}
void dessertmenu::getdrinks()
{
    cout<<"enter how many drink types in menu: ";
    cin>>num_drinks;
    drinks=new food[num_drinks];
    for(int i=0;i<num_drinks;i++)
    {
        drinks[i].addfood();
    }
}
void vegmenu::createmenu()
{
    ofstream f1;
    f1.open("vegmenu2",ios::app);
    cout<<"ENTER VEG MENU DETAILS: \n";
    getvstarter();
    getvmains();
    getvsoups();
    int i;
    f1<<num_vstarters;
    f1<<' ';
    f1<<num_vmains;
    f1<<' ';
    f1<<num_vsoup;
    f1<<' ';
    for(i=0;i<num_vstarters;i++)
    {
        f1<<veg_starters[i].getname();
        f1<<'\n';
        f1<<veg_starters[i].getprice();
        f1<<' ';
    }
    for(i=0;i<num_vmains;i++)
    {
        f1<<veg_mains[i].getname();
        f1<<'\n';
        f1<<veg_mains[i].getprice();
        f1<<' ';
    }
    for(i=0;i<num_vsoup;i++)
    {
        f1<<veg_soup[i].getname();
        f1<<'\n';
        f1<<veg_soup[i].getprice();
        f1<<' ';
    }
    f1.close();
}
void vegmenu::readfile()
{
    ifstream f;
    string n1;
    float p1;
    f.open("vegmenu2",ios::in);
    f.seekg(0,ios::beg);
    int i;
    f>>num_vstarters;
    f>>num_vmains;
    f>>num_vsoup;
    veg_starters=new food[num_vstarters];
    veg_mains=new food[num_vmains];
    veg_soup=new food[num_vsoup];
    for(i=0;i<num_vstarters;i++)
    {
        getline(f,n1);
        f>>p1;
        veg_starters[i].setname(n1);
        veg_starters[i].setprice(p1);
    }
    for(i=0;i<num_vmains;i++)
    {
        getline(f,n1);
        f>>p1;
        veg_mains[i].setname(n1);
        veg_mains[i].setprice(p1);
    }
    for(i=0;i<num_vsoup;i++)
    {
        getline(f,n1);
        f>>p1;
        veg_soup[i].setname(n1);
        veg_soup[i].setprice(p1);
    }
    f.close();

}
void nonvegmenu::createmenu()
{
    cout<<"ENTER NONVEG MENU DETAILS: \n";
    getnvstarter();
    getnvmains();
    getnvsoups();
    ofstream f2;
    f2.open("nonvegmenu2",ios::app);
    int i;
    f2<<num_nvstarters;
    f2<<' ';
    f2<<num_nvmains;
    f2<<' ';
    f2<<num_nvsoup;
    f2<<' ';
    for(i=0;i<num_nvstarters;i++)
    {
        f2<<nv_starters[i].getname();
        f2<<'\n';
        f2<<nv_starters[i].getprice();
        f2<<' ';
    }
    for(i=0;i<num_nvmains;i++)
    {
        f2<<nv_mains[i].getname();
        f2<<'\n';
        f2<<nv_mains[i].getprice();
        f2<<' ';
    }
    for(i=0;i<num_nvsoup;i++)
    {
        f2<<nv_soup[i].getname();
        f2<<'\n';
        f2<<nv_soup[i].getprice();
        f2<<' ';
    }
    f2.close();
}

void nonvegmenu::readfile()
{
    ifstream f0;
    string n1;
    float p1;
    f0.open("nonvegmenu2",ios::in);
    f0.seekg(0,ios::beg);
    int i;
    f0>>num_nvstarters;
    f0>>num_nvmains;
    f0>>num_nvsoup;
    nv_starters=new food[num_nvstarters];
    nv_mains=new food[num_nvmains];
    nv_soup=new food[num_nvsoup];
    for(i=0;i<num_nvstarters;i++)
    {
        getline(f0,n1);
        f0>>p1;
        nv_starters[i].setname(n1);
        nv_starters[i].setprice(p1);
    }
    for(i=0;i<num_nvmains;i++)
    {
        getline(f0,n1);
        f0>>p1;
        nv_mains[i].setname(n1);
        nv_mains[i].setprice(p1);
    }
    for(i=0;i<num_nvsoup;i++)
    {
        getline(f0,n1);
        f0>>p1;
        nv_soup[i].setname(n1);
        nv_soup[i].setprice(p1);
    }
    f0.close();

}
void dessertmenu::createmenu()
{
    cout<<"ENTER DESSERT MENU DETAILS: \n";
    geticecream();
    getspecials();
    getdrinks();
    getcake();
    ofstream f3;
    f3.open("dessertmenu2",ios::app);
    int i;
    f3<<num_icecream;
    f3<<' ';
    f3<<num_specials;
    f3<<' ';
    f3<<num_drinks;
    f3<<' ';
    f3<<num_cake;
    f3<<' ';
    for(i=0;i<num_icecream;i++)
    {
        f3<<icecream[i].getname();
        f3<<'\n';
        f3<<icecream[i].getprice();
        f3<<' ';
    }
    for(i=0;i<num_specials;i++)
    {
        f3<<specials[i].getname();
        f3<<'\n';
        f3<<specials[i].getprice();
        f3<<' ';
    }
    for(i=0;i<num_drinks;i++)
    {
        f3<<drinks[i].getname();
        f3<<'\n';
        f3<<drinks[i].getprice();
        f3<<' ';
    }
    for(i=0;i<num_cake;i++)
    {
        f3<<cake[i].getname();
        f3<<'\n';
        f3<<cake[i].getprice();
        f3<<' ';
    }
    f3.close();
}
void dessertmenu::readfile()
{
    ifstream ff;
    string n1;
    float p1;
    ff.open("dessertmenu2",ios::in);
    ff.seekg(0,ios::beg);
    int i;
    ff>>num_icecream;
    ff>>num_specials;
    ff>>num_drinks;
    ff>>num_cake;
    icecream=new food[num_icecream];
    specials=new food[num_specials];
    drinks=new food[num_drinks];
    cake=new food[num_cake];
    for(i=0;i<num_icecream;i++)
    {
        getline(ff,n1);
        ff>>p1;
        icecream[i].setname(n1);
        icecream[i].setprice(p1);
    }
    for(i=0;i<num_specials;i++)
    {
        getline(ff,n1);
        ff>>p1;
        specials[i].setname(n1);
        specials[i].setprice(p1);
    }
    for(i=0;i<num_drinks;i++)
    {
        getline(ff,n1);
        ff>>p1;
        drinks[i].setname(n1);
        drinks[i].setprice(p1);
    }
    for(i=0;i<num_cake;i++)
    {
        getline(ff,n1);
        ff>>p1;
        cake[i].setname(n1);
        cake[i].setprice(p1);
    }
    ff.close();

}
void restaurant::c_vegrestaurant()
{
    fstream f;
    f.open("Veg_Restaurants.txt",ios::app);
    f<<r_id;
    f<<" ";
    f<<name1;
    f<<"\n";
    f<<offer;
    f<<" ";
    f<<l_id;
    f<<"\n";
    f.close();
}
void restaurant::c_nvegrestaurant()
{
    fstream f;
    f.open("Nonveg_Restaurants.txt",ios::app);
    f<<r_id;
    f<<" ";
    f<<name1;
    f<<"\n";
    f<<offer;
    f<<" ";
    f<<l_id;
    f<<"\n";
    f.close();
}
void restaurant::c_desserts()
{
    fstream f;
    f.open("Desserts.txt",ios::app);
    f<<r_id;
    f<<" ";
    f<<name1;
    f<<"\n";
    f<<offer;
    f<<" ";
    f<<l_id;
    f<<"\n";
    f.close();
}
void admin::addvegrestaurant(vegmenu &vm)
{
    v[num_vegrestaurant].getdetails();
    v[num_vegrestaurant].setmenu(vm);
    v[num_vegrestaurant].c_vegrestaurant();
    num_vegrestaurant++;
}
void admin::addnonvegrestaurant(nonvegmenu &nv)
{
    n[num_nvrestaurant].getdetails();
    n[num_nvrestaurant].setmenu(nv);
    v[num_vegrestaurant].c_nvegrestaurant();
    num_nvrestaurant++;
}
void admin::adddessertrestaurant(dessertmenu &des)
{
    d[num_dessertrestaurant].getdetails();
    d[num_dessertrestaurant].setmenu(des);
    v[num_vegrestaurant].c_desserts();
    num_dessertrestaurant++;
}
void admin::readrestaurantfile()
{
    ifstream f1;
    ifstream f;
    f.open("Veg_Restaurants.txt",ios::in);
    int r_id;
    location l;
    string name;
    float offer;
    int id;
    int l_id;
    string name1;
    float  latitude;
    float longtitude;
    while(f>>r_id)
    {
        getline(f,name);
        f>>offer;
        f>>l_id;
        f1.open("LOCATIONS.txt",ios::in);
        while(f1>>id)
        {
            getline(f1,name1);
            f1>>latitude;
            f1>>longtitude;
            if(id==l_id)
            {
                l.setdetails(id,name1,latitude,longtitude);

            }
        }
        v[num_vegrestaurant].setlocation(l);
        v[num_vegrestaurant].setid(r_id);
        v[num_vegrestaurant].setname(name);
        v[num_vegrestaurant].setoffer(offer);
        v[num_vegrestaurant].setlid(l_id);
        num_vegrestaurant++;
        f1.close();
    }
    f.close();
    f.open("Desserts.txt",ios::in);
    while(f>>r_id)
    {
        getline(f,name);
        f>>offer;
        f>>l_id;
        f1.open("LOCATIONS.txt",ios::in);
        while(f1>>id)
        {
            getline(f1,name1);
            f1>>latitude;
            f1>>longtitude;
            if(id==l_id)
            {
                l.setdetails(id,name1,latitude,longtitude);

            }

        }
        d[num_dessertrestaurant].setlocation(l);
        d[num_dessertrestaurant].setid(r_id);
        d[num_dessertrestaurant].setname(name);
        d[num_dessertrestaurant].setoffer(offer);
        d[num_dessertrestaurant].setlid(l_id);
        num_dessertrestaurant++;
        f1.close();
    }
    f.close();
    f.open("Nonveg_Restaurants.txt",ios::in);
    while(f>>r_id)
    {
        getline(f,name);
        f>>offer;
        f>>l_id;
        f1.open("LOCATIONS.txt",ios::in);
        while(f1>>id)
        {
            getline(f1,name1);
            f1>>latitude;
            f1>>longtitude;
            if(id==l_id)
            {
                l.setdetails(id,name1,latitude,longtitude);

            }

        }
        n[num_nvrestaurant].setlocation(l);
        n[num_nvrestaurant].setid(r_id);
        n[num_nvrestaurant].setname(name);
        n[num_nvrestaurant].setoffer(offer);
        n[num_nvrestaurant].setlid(l_id);
        num_nvrestaurant++;
        f1.close();
    }
    f.close();
}
void restaurant::modifydetails()
{
    int choice;
    do{
    cout<<"1-name\n2-location\nwhich detail you want to modify? ";
    cin>>choice;}while(choice!=1&&choice!=2);
    if(choice==1)
    {
        string name;
        cout<<"enter restaurant name: ";
        cin>>name;
        this->name1=name;
    }
    else if(choice==2)
    {
        int l_id;
        cout<<"enter offer given by the restaurant: ";
        cin>>l_id;
        this->l_id=l_id;
    }
}
void admin::modifyrestaurant()
{
    int i;
    string type;
    int id;
    string ch;
    do{cout<<"What type of restaurant you want to modify?\nveg\nnonveg\ndessert\n: ";
    cin>>type;}while(type!="veg"&&type!="nonveg"&&type!="dessert");
    if(type=="veg")
    {
        cout<<"enter restaurant id to modify: ";
        cin>>id;
        ofstream f;
        f.open("Veg_Restaurants.txt",ios::out);
        f.close();
        for(i=0;i<num_vegrestaurant;i++)
        {
            if(id==v[i].getid())
                v[i].modifydetails();
            v[i].c_vegrestaurant();
        }

    }
    else if(type=="nonveg")
    {
        cout<<"enter restaurant id to modify: ";
        cin>>id;
        ofstream f;
        f.open("Nonveg_Restaurants.txt",ios::out);
        f.close();
        for(i=0;i<num_nvrestaurant;i++)
        {
            if(id==n[i].getid())
                n[i].modifydetails();
            n[i].c_nvegrestaurant();
        }
    }
    else
    {
        cout<<"enter restaurant id to modify: ";
        cin>>id;
        ofstream f;
        f.open("Desserts.txt",ios::out);
        f.close();
        for(i=0;i<num_dessertrestaurant;i++)
        {
            if(id==d[i].getid())
                d[i].modifydetails();
            d[i].c_desserts();
        }
    }
}
void admin::restaurants()
{
    cout<<"VEG RESTAURANTS: \n";
    for(int i=0;i<num_vegrestaurant;i++)
    {
        cout<<i+1<<" "<<v[i].getname()<<endl;
    }
    cout<<"NONVEG RESTAURANTS: \n";
    for(int i=0;i<num_nvrestaurant;i++)
    {
        cout<<i+1<<" "<<n[i].getname()<<endl;
    }
    cout<<"DESSERT RESTAURANTS: \n";
    for(int i=0;i<num_dessertrestaurant;i++)
    {
        cout<<i+1<<" "<<d[i].getname()<<endl;
    }
}
void admin::d_restaurants(int t)
{
    fstream f;
    system("cls");
    int ch;
    f.open("Restaurant_Choice.txt",ios::out);
    cout<<t<<endl;
    if(t==1)
    {
        cout<<"VEG RESTAURANTS: \n";
        for(int i=0;i<num_vegrestaurant;i++)
        {
            cout<<i+1<<" "<<v[i].getname()<<endl;
        }
        do
        {
            cout<<"Enter your choice: ";
            cin>>ch;
            if(ch>=1 && ch<=num_vegrestaurant)
            {
                    f<<v[ch-1].getid();
                    f<<" ";
                    f<<v[ch-1].getname();
                    f<<"\n";
                    f<<v[ch-1].getoffer();
                    f<<" ";
                    f<<v[ch-1].getl_id();
                    f<<"\n";
                    f.close();
                    break;
            }
            else
                cout<<"Invalid input"<<endl;
        }while(true);

    }
    else if(t==2)
    {
        cout<<"NONVEG RESTAURANTS: \n";
        for(int i=0;i<num_nvrestaurant;i++)
        {
            cout<<i+1<<" "<<n[i].getname()<<endl;
        }
        do
        {
            cout<<"Enter your choice: ";
            cin>>ch;
            if(ch>=1 && ch<=num_nvrestaurant)
            {
                    f<<n[ch-1].getid();
                    f<<" ";
                    f<<n[ch-1].getname();
                    f<<"\n";
                    f<<n[ch-1].getoffer();
                    f<<" ";
                    f<<n[ch-1].getl_id();
                    f<<"\n";
                    f.close();
                    break;
            }
            else
                cout<<"Invalid input"<<endl;
        }while(true);
    }
    else if(t==3)
    {    cout<<"DESSERT RESTAURANTS: \n";
        for(int i=0;i<num_dessertrestaurant;i++)
        {
            cout<<i+1<<" "<<d[i].getname()<<endl;
        }
        do
        {
            cout<<"Enter your choice: ";
            cin>>ch;
            if(ch>=1 && ch<=num_dessertrestaurant)
            {
                    f<<d[ch-1].getid();
                    f<<" ";
                    f<<d[ch-1].getname();
                    f<<"\n";
                    f<<d[ch-1].getoffer();
                    f<<" ";
                    f<<d[ch-1].getl_id();
                    f<<"\n";
                    f.close();
                    break;
            }
            else
                cout<<"Invalid input"<<endl;
        }while(true);
    }
    f.close();
}

void food::displayfood()
{
    cout<<left<<setw(30)<<name;
    cout<<left<<setw(5)<<price<<endl;

}
void vegmenu::displaymenu()
{
    int i,j,k;
    cout<<"STARTERS: \n";
    cout<<"ID   NAME \t\t\t   PRICE"<<endl;
    for(i=0;i<num_vstarters;i++)
    {
        cout<<left<<setw(4)<<i+1;
        veg_starters[i].displayfood();
    }
    j=i;
    cout<<"MAINS: \n";
    for(i=0;i<num_vmains;i++)
    {
        cout<<left<<setw(4)<<j+1<<" ";
        veg_mains[i].displayfood();
        j++;
    }
    cout<<"SOUPS: \n";
    k=j;
    for(i=0;i<num_vsoup;i++)
    {
        cout<<left<<setw(4)<<k+1<<" ";
        veg_soup[i].displayfood();
        k++;
    }
}
int order(vegmenu &v)
{
    fstream f;
    f.open("order.txt",ios::out);
    int n,c;
    char ch;
    c=0;
    do
    {

        cout<<"Enter the id of the food to be ordered: ";
        cin>>n;
        if(n<=v.num_vstarters)
        {
            f<<v.veg_starters[n-1].getname();
            f<<'#';
            f<<v.veg_starters[n-1].getprice();
            f<<'\n';
            c++;
        }
        else if((v.num_vstarters<n) && (n<=(v.num_vmains+v.num_vstarters)))
        {
            f<<v.veg_mains[n-v.num_vstarters-1].getname();
            f<<'#';
            f<<v.veg_mains[n-v.num_vstarters-1].getprice();
            f<<'\n';
            c++;
        }

        else if(((v.num_vmains+v.num_vstarters)<n) && (n<=(v.num_vmains+v.num_vsoup+v.num_vstarters)))
        {

            f<<v.veg_soup[n-v.num_vstarters-v.num_vmains-1].getname();
            f<<'#';
            f<<v.veg_soup[n-v.num_vstarters-v.num_vmains-1].getprice();
            f<<'\n';
            c++;
        }
        else
        {
           cout<<"Enter invalid input: ";

        }


        cout<<"Do you want to continue(y/n) : ";
        cin>>ch;


    }
    while(ch=='y');
    f.close();
    return c;
}
int order(nonvegmenu &nv)
{
    fstream f;
    f.open("order.txt",ios::out);
    int n,c;
    char ch;
    c=0;
    do
    {

        cout<<"Enter the id of the food to be ordered: ";
        cin>>n;
        if(n<=nv.num_nvstarters)
        {
            f<<nv.nv_starters[n-1].getname();
            f<<'#';
            f<<nv.nv_starters[n-1].getprice();
            f<<'\n';
            c++;
        }
        else if((nv.num_nvstarters<n) && (n<=(nv.num_nvmains+nv.num_nvstarters)))
        {
            f<<nv.nv_mains[n-nv.num_nvstarters-1].getname();
            f<<'#';
            f<<nv.nv_mains[n-nv.num_nvstarters-1].getprice();
            f<<'\n';
            c++;
        }

        else if(((nv.num_nvmains+nv.num_nvstarters)<n) && (n<=(nv.num_nvmains+nv.num_nvsoup+nv.num_nvstarters)))
        {

            f<<nv.nv_soup[n-nv.num_nvstarters-nv.num_nvmains-1].getname();
            f<<'#';
            f<<nv.nv_soup[n-nv.num_nvstarters-nv.num_nvmains-1].getprice();
            f<<'\n';
            c++;
        }
        else
        {
           cout<<"Enter invalid input: ";

        }


        cout<<"Do you want to continue(y/n) : ";
        cin>>ch;

    }
    while(ch=='y');
    f.close();
    return c;
}
int order(dessertmenu &d)
{
    fstream f;
    f.open("order.txt",ios::out);
    int n,c;
    char ch;
    c=0;
    do
    {
        cout<<"Enter the id of the food to be ordered: ";
        cin>>n;
        if(n<=d.num_icecream)
        {
            f<<d.icecream[n-1].getname();
            f<<'#';
            f<<d.icecream[n-1].getprice();
            f<<'\n';
            c++;
        }
        else if((d.num_icecream<n) && (n<=(d.num_icecream+d.num_specials)))
        {
            f<<d.specials[n-d.num_icecream-1].getname();
            f<<'#';
            f<<d.specials[n-d.num_icecream-1].getprice();
            f<<'\n';
            c++;

        }

        else if(((d.num_icecream+d.num_specials)<n) && (n<=(d.num_icecream+d.num_specials+d.num_drinks)))
        {

            f<<d.drinks[n-d.num_icecream-d.num_specials-1].getname();
            f<<'#';
            f<<d.drinks[n-d.num_icecream-d.num_specials-1].getprice();
            f<<'\n';
            c++;
        }
        else if(((d.num_icecream+d.num_specials+d.num_drinks)<n)&&(n<=d.num_icecream+d.num_specials+d.num_drinks+d.num_cake))
        {
            f<<d.drinks[n-d.num_icecream-d.num_specials-d.num_cake-1].getname();
            f<<'#';
            f<<d.drinks[n-d.num_icecream-d.num_specials-d.num_cake-1].getprice();
            f<<'\n';
            c++;

        }
        else
        {
            cout<<"Invalid input"<<endl;
        }


        cout<<"Do you want to continue(y/n) : ";
        cin>>ch;

    }
    while(ch=='y');
    f.close();
    return c;
}
void nonvegmenu::displaymenu()
{
    int i,j,k;
    cout<<"STARTERS: \n";
    cout<<"ID   NAME \t\t\t  PRICE"<<endl;
    for(i=0;i<num_nvstarters;i++)
    {
        cout<<left<<setw(4)<<i+1;
        nv_starters[i].displayfood();
    }
    j=i;
    cout<<"MAINS: \n";
    cout<<"ID   NAME \t\t\t  PRICE"<<endl;
    for(i=0;i<num_nvmains;i++)
    {
        cout<<left<<setw(4)<<j+1<<" ";
        nv_mains[i].displayfood();
        j++;
    }
    cout<<"SOUPS: \n";
    cout<<"ID   NAME \t\t\t  PRICE"<<endl;
    k=j;
    for(i=0;i<num_nvsoup;i++)
    {
        cout<<left<<setw(4)<<k+1<<" ";
        nv_soup[i].displayfood();
        k++;
    }
}
void dessertmenu::displaymenu()
{
    int i,j,k,q;
    cout<<"ICECREAM: \n";
    cout<<"ID   NAME \t\t\t   PRICE"<<endl;
    for(i=0;i<num_icecream;i++)
    {
        cout<<left<<setw(4)<<i+1;
        icecream[i].displayfood();
    }
    j=i;
    cout<<"SPECIALS: \n";
    cout<<"ID   NAME \t\t\t   PRICE"<<endl;
    for(i=0;i<num_specials;i++)
    {
        cout<<left<<setw(4)<<j+1;
        specials[i].displayfood();
        j++;
    }
    k=j;
    cout<<"DRINKS: \n";
    cout<<"ID   NAME \t\t\t   PRICE"<<endl;
    for(i=0;i<num_drinks;i++)
    {
        cout<<left<<setw(4)<<k+1;
        drinks[i].displayfood();
        k++;
    }
    q=k;
    cout<<"CAKE: \n";
    cout<<"ID   NAME \t\t\t   PRICE"<<endl;
    for(i=0;i<num_cake;i++)
    {
        cout<<left<<setw(4)<<q+1;
        cake[i].displayfood();
        q++;
    }

}
void location::getdetail()
{
    cout<<"Enter location id: ";
    cin>>id;
    cout<<"Enter the area name: ";
    cin.ignore();
    getline(cin,name);
    cout<<"Enter the latitude: ";
    cin>>latitude;
    cout<<"Enter the longtitude: ";
    cin>>longtitude;
}
void location::c_location()
{
    fstream f;
    f.open("LOCATIONS.txt",ios::app);
    f<<id;
    f<<' ';
    f<<name;
    f<<'\n';
    f<<latitude;
    f<<' ';
    f<<longtitude;
    f<<' ';
    f.close();
}
int customer::registrations()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD savedAttributes;
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    savedAttributes = consoleInfo.wAttributes;
    fstream f;
    string name,password,name1,password1;
    int c;
    do{
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t  _______________________________________________________\n";
    cout<<"\t\t\t\t\t\t\t |                                                       |\n";
    cout<<"\t\t\t\t\t\t\t |               1     LOGIN                             |\n";
    cout<<"\t\t\t\t\t\t\t |               2     New user? SIGN UP                 |\n";
    cout<<"\t\t\t\t\t\t\t |_______________________________________________________|\n";
    cout<<"choice: ";
    cin>>c;
    system("cls");}while(c!=1&&c!=2);
    if(c==2)
    {
        f.open("REGISTRATIONS.txt",ios::app);
        getinfo();
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
        cout<<"\t\t\t\t\t\t\t SIGNIN SUCCESSFULL\n";
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\tSIGNIN SUCCESSFULL\n";
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t SIGNIN SUCCESSFULL\n";
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\tSIGNIN SUCCESSFULL\n";
        system("cls");
        cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t SIGNIN SUCCESSFULL\n";
        SetConsoleTextAttribute(hConsole, savedAttributes);
        cin.ignore();
        while(getchar()!='\n');
        system("cls");
        f<<name;
        f<<'#';
        f<<password;
        f<<"\n";
        f.close();
        return c;
    }
    else
    {
       do
       {
           f.open("REGISTRATIONS.txt",ios::in);
           getinfo();
           while(getline(f,name1,'#'))
            {
               getline(f,password1,'\n');
               if((name==name1)||(password==password1))
                {

                    cout<<"\n\n\n\n\n\n\n\n\n\n";
                    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN);
                    cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n";
                    cout<<"\t\t\t\t\t\t\tLOGIN VERIFIED\n";
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n";
                    cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n";
                    cout<<"\t\t\t\t\t\t\tLOGIN VERIFIED\n";
                    system("cls");
                    cout<<"\n\n\n\n\n\n\n\n\n\n";
                    cout<<"\t\t\t\t\t\t\t LOGIN VERIFIED\n";
                    SetConsoleTextAttribute(hConsole, savedAttributes);
                    cin.ignore();
                    while(getchar()!='\n');
                    system("cls");
                      f.close();
                    return c;
                  }
            }
            cout<<"\n\n\n\n\n\n\n\n\n\n";
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\tINVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\t\t\n\n";
        cout<<"\t\t\t\t\t\t\tINVALID LOGIN\n";
        system("cls");
         cout<<"\n\n\n\n\n\n\n\n\n\n";
        cout<<"\t\t\t\t\t\t\t INVALID LOGIN\n";
        SetConsoleTextAttribute(hConsole, savedAttributes);
        cin.ignore();
        while(getchar()!='\n');
        system("cls");
            f.close();
        }while(true);
    }
    system("cls");
    return 0;
}
void restaurants(int id);
int locations(location &l)
{
    system("cls");
    fstream f;
    char c;
    string temp,loc;
    do
    {
        cout<<"Enter your location: ";
        getline(cin,loc);
        f.open("LOCATIONS.txt",ios::in);
        while(f>>l.id)
        {

            f.get(c);
            getline(f,l.name);
            if(loc==l.name)
            {
                cout<<"Restaurant near this location....."<<endl;
                restaurants(l.id);
                return l.id;
            }
            getline(f,temp,'\n');
        }
        cout<<"Sorry! Restaurants are not available near this location...."<<endl;
        f.close();
    }while(true);
}
void bill::food_ordered(int ct)
{
    int i=0;
    fstream g;
    char c;
    string name;
    float price;
    //float total=0;
    g.open("order.txt",ios::in);
    getline(g,name,'#');
    while(!g.eof())
    {
        g>>price;
        total_fprice+=price;
        food_order[i].setname(name);
        food_order[i].setprice(price);
        i++;
        g.get(c);
        getline(g,name,'#');
    }
    system("cls");
    cout<<"ORDERED FOODS ARE: "<<endl;
     cout<<"\t\tNAME\t\tPRICE"<<endl;
    for(i=0;i<ct;i++)
    {
        cout<<left<<setw(4)<<i+1<<" ";
        food_order[i].displayfood();
    }
    cin.ignore();
    while(getchar()!='\n');
}
void bill::restaurant_choosed(int &loc,int reg)
{
    system("cls");
    fstream g,f;
    location l;
    float latitude1,longtitude1;
    float latitude2,longtitude2;
    string name2;
    int id;
    g.open("Restaurant_Choice.txt",ios::in);
    g>>r_id;
    getline(g,name1);
    g>>offer;
    g>>l_id;

    f.open("LOCATIONS.txt",ios::in);
    while(f>>id)
        {
            getline(f,name2);
            f>>latitude1;
            f>>longtitude1;
            if(id==l_id)
            {
                l.setdetails(id,name2,latitude1,longtitude1);
                break;
            }
        }
    f.close();
    f.open("LOCATIONS.txt",ios::in);
    while(f>>id)
        {
            getline(f,name2);
            f>>latitude2;
            f>>longtitude2;
            if(id==loc)
            {
                break;
            }
        }

    double lat1_rad = latitude1 * M_PI / 180.0;
    double lat2_rad = latitude2 * M_PI / 180.0;
    double lon1_rad = longtitude1 * M_PI / 180.0;
    double lon2_rad = longtitude2 * M_PI / 180.0;
    double dlat = lat2_rad - lat1_rad;
    double dlon = lon2_rad - lon1_rad;
    double a = pow(sin(dlat/2), 2) + cos(lat1_rad) * cos(lat2_rad) * pow(sin(dlon/2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));
    double R = 6371;
    double dist = R * c;
    //float reg_offer=0;
    if(reg==2)
         {
             cout<<"YOU ARE A NEW CUSTOMER . SO U WILL GET AN OFFER"<<endl;
             reg_offer=30;
         }
    d_amount=(offer*total_fprice)/100.0;
    amount=total_fprice-d_amount;
    if(dist<1)
    {
        cout<<"YOUR DISTANCE FROM THE RESTAURANT IS LESS THAN 1 km, SO FREE DELIVERY !!!!"<<endl;
    }
    else
    {
        delivery_charge=dist*10;
    }
    cout<<"\n\n\n\n\n\n";
    cout<<"_______________________________________________________________________________________\n";
    cout<<"\t\t\t\t\tRESTAURANT                    : "<<name1<<endl;
    cout<<"\t\t\t\t\tDISTANCE FROM YOUR LOCATION IS: "<<dist<<endl;
    cout<<"\t\t\t\t\tDISCOUNT OFFER                : "<<offer<<endl;
    cout<<"\t\t\t\t\tDISCOUNT AMOUNT               : "<<d_amount<<endl;
    cout<<"\t\t\t\t\tDELIVERY CHARGE               : "<<delivery_charge<<endl;
    cout<<"\t\t\t\t\tREGISTRATION OFFER            : "<<((reg_offer*amount)/100.0)<<endl;
    cout<<"_______________________________________________________________________________________\n";
    amount-=((reg_offer*amount)/100.0);
    amount+=delivery_charge;
    cout<<"\t\t\t\t\t\t\t\t\tTOTAL AMOUNT: "<<amount<<endl;


}



