#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;

int main()
{
	srand(time(NULL));
	
	int birth[5000]={0} ,i, j, k, same, l ,m;

	double p,count;

	for(i=2;i<=50;i++)              		//number of people
	{
		
		count = 0;
		
		for(j=0;j<5000;j++)			//times
		{

			same = 0;			//same -> 1							

			for(k=0;k<i;k++)  		//random
				birth[k] = rand()%365 ;

			for(l=0;l<(i-1);l++)		//compare 
			{
				for(m=(l+1);m<i;m++)
				{
					if(birth[l] == birth[m])
						same = 1;
				}
			}

			if(same == 1)
				count++;	
		}
		
		p = count / 5000;			//probability		
		cout<<"For "<<i<<" people,the probability of two birthdays is about "<<p<<endl;
	}

	return 0;
}
