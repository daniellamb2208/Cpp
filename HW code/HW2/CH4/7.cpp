#include<iostream>
using namespace std;

void input(double &p, double &o)
{
	cout<<"Input pound: ";
	cin>>p;
	cout<<"Input ounce: ";
	cin>>o;
}

void trans(int &k, double &g)
{
	double pound, ounce;
	input(pound,ounce);
	double total_p, total_k, total_g;
	
	total_p = pound + (ounce/16);
	total_k = total_p / 2.2046;
	total_g = total_k * 1000;

	k = int(total_g / 1000);
	g = total_g - (k*1000);
}

void output()
{
	int k;
	double g;
	trans(k,g);

	cout<<"Weight: "<<endl;
	cout<<k<<"kg and "<<g<<"g"<<endl;
}

int main(void)
{
	char exit;
	do
	{
		output();
		cout<<"Calculate again? (y/n): ";
		cin>>exit;
	}while(exit == 'y');
	
	return 0;
}
