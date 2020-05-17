#include<iostream>
#include<time.h>
using namespace std;

void random(int *r)
{
	*r = (rand() % 25) +1;
}

int main(void)
{	
	srand(time(NULL));

	int a, b, c, d;

	random(&a);

	do
	{
		random(&b);
	}while(a==b);

	do
	{		
		random(&c);
	}while(a==c || b==c);	
	
	do
	{	
		random(&d);
	}while(a==d || b==d || c==d);

	cout<<"The four winners are:"<<endl;
	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	return 0;

}
