#include<iostream>
using namespace std;

void output_po(int k,double g)
{
	cout<<"Weight: "<<endl;
	cout<<k<<" kilogram and "<<g<<" gram"<<endl;
}
void trans_po(double p,double o)
{
	double total_p, total_k, total_g;
	int k;
	double g;
	total_p = p + (o/16);
	total_k = total_p / 2.2046;
	total_g = total_k * 1000;

	k = int(total_g / 1000);
	g = total_g - (k*1000);

	output_po(k,g);
}
void input_po()
{
	double p, o; 
	cout<<"Input pound: ";
	cin>>p;
	cout<<"Input ounce: ";
	cin>>o;

	trans_po(p,o);
}

void output_kg(int p,double o)
{
	cout<<"Weight: "<<endl;
	cout<<p<<" pound and "<<o<<" ounces"<<endl;
}
void trans_kg(double k,double g)
{
	double total_k, total_p;
	int p;	
	double o;
	total_k = k + (g/1000);
	total_p = total_k * 2.2046;
	p = int(total_p);
	o = (total_p - p) * 16;

	output_kg(p,o);
}
void input_kg()
{
	double k, g; 
	cout<<"Input kilogram: ";
	cin>>k;
	cout<<"Input gram: ";
	cin>>g;

	trans_kg(k,g);
}

void choose()
{
	int check=0;
	cout<<"Conversion from pound and ounce to kilogram and gram, enter 1"<<endl;
	cout<<"Conversion from kilogram and gram to pound and ounce, enter 2"<<endl;
	cin>>check;

	if(check == 1)
		input_po();
	else if(check == 2)
		input_kg();
	else
		return ; 
}

int main(void)
{
	char exit;
	do
	{
		choose();
		cout<<"Calculate again? (y/n): ";
		cin>>exit;
	}while(exit == 'y');
	
	return 0;
}
