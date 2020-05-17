#include<iostream>
using namespace std;

double hat_size(double h,double w)
{
	return  w / h *2.9;
}
double jacket_size(double h,double w,double a)
{
	double j;
	j = w * h / 288;

	if(a>=30)
	{
		a = a - 20;
		while(a>0)
		{
			j = j + 0.125;
			a = a - 10;
		}
	} 
	return j;	
}
double waist_size(double h,double w,double a)
{
	double waist;
	waist = w / 5.7;
	if(a>=28)
	{
		a = a-26;
		while(a>0)
		{
			waist = waist + 0.1;
			a = a -2;
		}
	}
	return waist;
}

int main(void)
{	
	double h , w , a , hat , jacket , waist; 
	char check;
	
	do
	{
		cout<<"Size of hat, jacket, waist program."<<endl;
		cout<<"Your height(inches):";
		cin>>h;
		cout<<"Your weight(pounds):";
		cin>>w;
		cout<<"Your age:";
		cin>>a;
		
		hat = hat_size(h,w);

		jacket = jacket_size(h,w,a);
	
		waist = waist_size(h,w,a);

		cout<<"hat size = "<<hat<<endl;
		cout<<"jacket size = "<<jacket<<endl;
		cout<<"waist size = "<<waist<<endl;

		cout<<"\n"<<"Enter Y or y to repeat the calculation, any other to end:";
		cin>>check;
	}while(check=='Y' || check=='y');
}
