#include<iostream>
#include<cstdlib>
using namespace std;

class Temperature
{
	public:
		Temperature() {}
		
		void s();		

		friend bool operator ==(Temperature&,Temperature&);
		friend ostream& operator <<(ostream&,Temperature&);
		friend istream& operator >>(istream&,Temperature&);
		
		void setf(double ft) {f = ft;}
		
	private:
		double c,k,f; 
};

void Temperature :: s()
{
	c = (f - 32) * 5 / 9;
	k = c + 273.15;
//-------------------------------
	c = k - 273.15;
	f = k * 9 / 5 - 459.67;

}

bool operator ==(Temperature &a,Temperature &b)
{
	return (a.k == b.k);
}

ostream& operator <<(ostream &o, Temperature &t)
{
	t.s();

	o<<"In Kelvin    : "<<t.k<<endl;
	o<<"In Celisus   : "<<t.c<<endl;
	o<<"In Fahrenheit: "<<t.f<<endl;

	return o;
}

istream& operator >>(istream &i, Temperature &t)
{
	double ft;
	i>>ft;

	t.setf(ft);
	return i;
}

int main()
{
	Temperature a,b;

	cout<<"Temperature1 in Fahrenheit: ";
	cin>>a;
	cout<<a;
	cout<<"Temperature2 in Fahrenheit: ";
	cin>>b;
	cout<<b;

	cout<<"\nTemperature1 == Temperature2 : ";
	if(a==b)
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;

	return 0;
}
