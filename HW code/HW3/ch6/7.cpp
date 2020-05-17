#include<iostream>
#include"pizza.h"
using namespace std;

int main()
{
	Pizza pizza_a(SMALL,HANDTOSSED,0,3), pizza_b(LARGE,PAN,2,1);	

	return 0;
}

Pizza :: Pizza(int s,int t,int p,int c)
{
	setSize(s);
	setType(t);
	setPepperoniToppings(p);
	setCheeseToppings(c);
	outputDescription();
}
/*Pizza :: ~Pizza()
{
	delete &size; 
	delete &type;
	delete &pepperoniToppings;
	delete &cheeseToppings;
}*/
int Pizza :: getPepperoniToppings()
{
	return pepperoniToppings;
}

int Pizza :: getCheeseToppings()
{	
	return cheeseToppings;
}

int Pizza :: getSize()
{
	return size;
}

int Pizza :: getType()
{
	return type;
}

void Pizza :: setPepperoniToppings(int numPepperoni)
{
	pepperoniToppings = numPepperoni;
}
void Pizza :: setCheeseToppings(int numCheese)
{
	cheeseToppings = numCheese;
}
void Pizza :: setSize(int newSize)
{
	size = newSize;
}
void Pizza :: setType(int newType)
{
	type = newType;
}
void Pizza :: outputDescription()
{
	cout<<"The pizza is ";
	switch(getSize())
	{
		case 0:
			cout<<"Small, ";
			break;
		case 1:
			cout<<"Midium, ";
			break;
		case 2:
			cout<<"Large, ";
	}
	switch(getType())
	{
		case 0:
			cout<<"Deepfish, ";
			break;
		case 1:
			cout<<"Handtossed, ";
			break;
		case 2:
			cout<<"Pan, ";
	}
	cout<<"with "<<getPepperoniToppings()<<" pepperoni toppings and "<<getCheeseToppings()<<" cheese toppings."<<endl;

	cout<<"Price of pizza: "<<computePrice()<<endl;
	cout<<"\n";
}
double Pizza :: computePrice()
{
	double price = 0;

	switch(getSize())
	{
		case 0:
			price += 10;
			break;
		case 1:
			price += 14;
			break;
		case 2:
			price += 17;
	}

	return price + (getPepperoniToppings()*2) + (getCheeseToppings()*2);	 
}
