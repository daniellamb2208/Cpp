const int SMALL = 0;
const int MEDIUM = 1;
const int LARGE = 2;

const int DEEPDISH = 0;
const int HANDTOSSED = 1;
const int PAN = 2;

class Pizza
{
  public:
     Pizza(int s,int t,int p,int c);
//     ~Pizza() {};
     int getPepperoniToppings();
     void setPepperoniToppings(int numPepperoni);
     int getCheeseToppings();
     void setCheeseToppings(int numCheese);
     int getSize();
     void setSize(int newSize);
     int getType();
     void setType(int newType);
     void outputDescription();
     double computePrice();
  private:
     int size;
     int type;
     int pepperoniToppings;
     int cheeseToppings;
};


