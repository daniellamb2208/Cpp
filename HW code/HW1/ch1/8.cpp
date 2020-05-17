#include<iostream>
#include<iomanip>
using namespace std;
int main(void)
{
	double guess , n , r , i;
	
	cout<<"Please enter the number you want to estimate its square root:"<<endl;
	
	cin>>n;

	guess = n / 2;

	for(i=0;i<5;i++)
	{
		r = n / guess;
	
		guess = (guess + r) / 2;

	}

	cout<<fixed<<setprecision(2)<<guess<<endl;
	
	return 0;		
}
