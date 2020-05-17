#include<iostream>
using namespace std;

void output(int p,double o)
{
	cout<<"Weight: "<<endl;
	cout<<p<<" pound and "<<o<<" ounces"<<endl;
}

void trans(double k,double g)
{
	double total_k, total_p;
	int p;	
	double o;
	total_k = k + (g/1000);
	total_p = total_k * 2.2046;
	p = int(total_p);
	o = (total_p - p) * 16;

	output(p,o);
}

void input()
{
	double k, g; 
	cout<<"Input kiligram: ";
	cin>>k;
	cout<<"Input gram: ";
	cin>>g;

	trans(k,g);
}

int main(void)
{
	char exit;
	do
	{
		input();
		cout<<"Calculate again? (y/n): ";
		cin>>exit;
	}while(exit == 'y');
	
	return 0;
}
