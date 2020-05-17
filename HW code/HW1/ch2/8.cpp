#include<iostream>
using namespace std;

int main(void)
{
	float c=100 , f=0;
	
	while(c!=f)
	{
		f = c*9/5 + 32;
		if(c!=f)
			c--;
	}
	cout<<"Temperature (Fahrenheit and Celsius)"<<endl;;
	cout<<"they will be equal at "<<c<<endl;
	return 0; 
	
}
