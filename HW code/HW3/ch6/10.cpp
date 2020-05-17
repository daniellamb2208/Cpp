#include<iostream>
#include<cstring>
using namespace std;

class Weight
{
	public:
		Weight(string m, double p);
		void setWeightPounds(double a);
		void setWeightKilograms(double a);
		void steWeightOunces(double a);
		void output();
		
	private:
		double input;			//input stores in pounds
		double pound;
		double kilogram;
		double ounces;
};
Weight :: Weight(string m, double p) 
{
	if(m == "Kilograms")
	{
		cout<<"Set Kilograms = "<<p<<endl;
		input = p *2.21;
	}
	else if(m == "Pounds")
	{
		cout<<"Set Pounds = "<<p<<endl;
		input = p;
	}	
	else
	{
		cout<<"Set Ounces = "<<p<<endl;
		input =  p / 16;
	}

	setWeightPounds(input);
	setWeightKilograms(input/2.21);
	steWeightOunces(input*16);

	output();
}

void Weight :: setWeightPounds(double a)
{
	pound = a;
}
void Weight :: setWeightKilograms(double a)
{
	kilogram = a;
}
void Weight :: steWeightOunces(double a)
{
	ounces = a;
}
void Weight :: output()
{
	cout<<"> In Kilograms: "<<kilogram<<endl;
	cout<<"> In Pounds: "<<pound<<endl;
	cout<<"> In Ounces: "<<ounces<<endl;
	cout<<"\n";
}
int main()
{
	Weight first("Kilograms",60), second("Pounds",110), third("Ounces",1800);

	return 0;
}
