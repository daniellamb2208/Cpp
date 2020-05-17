#include<iostream>
using namespace std;
int main(void)
{
	int i , j , check;
	
	cout<<"Primes between 3~100:"<<endl;

	for(i=3;i<=100;i++)
	{
		check=0;
		
		for(j=2;j<i;j++)
		{
			if(i%j==0)
				check=1;
		}

		if(check==0)
			cout<<i<<endl;

	}		
		return 0;	
}
