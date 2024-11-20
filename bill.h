class bill:public restaurant,public food
{
    food food_order[25];
    double reg_offer;
    float d_amount;
    float delivery_charge;
    float amount;

    float total_fprice;
public:
    bill()
    {
        reg_offer=0;
        delivery_charge=0;
        amount=0;
        total_fprice=0;
        d_amount=0;

    }
    void food_ordered(int);
    void restaurant_choosed(int &,int);

};
