#include<iostream>
using namespace std;
int main(void)
{
	double caf , overdosed;
	
	cout<<"How many milligrams of caffeine in the drink?"<<endl;
	
	cin>>caf;
	
	overdosed = 10000 / caf;

	cout<<"you will be killed after drinking "<<overdosed<<"(units) drinks."<<endl;
	
	return 0;
}
