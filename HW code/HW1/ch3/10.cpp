#include<iostream>
using namespace std;

int male(int d,int m)
{
	return (m*13/12 + d)/2;
}
int female(int d,int m)
{
	return (d*12/13 + m)/2;
}


int main(void)
{
	int child_gender , momI , momF , momH , dadI , dadF , dadH , childI , childF;
	char check;
	do
	{
		cout<<"Wish gender of your future child (0 for boy, 1 for girl):";	
		cin>>child_gender;

		cout<<"Height of mom (feets / inches):";
		cin>>momF>>momI;
		cout<<"Height of dad (feets / inches):";
		cin>>dadF>>dadI;
	
		dadH = dadF * 12 + dadI;
		momH = momF * 12 + momI;

		if(child_gender==0)
		{
			childI = male(dadH,momH) / 12;
			childF = male(dadH,momH) % 12;
		}
		else if(child_gender==1)
		{
			childI = female(dadH,momH) / 12;
			childF = female(dadH,momH) % 12;
		}
		else
			cout<<"Wrong number."<<endl;
	
		cout<<"Your future child is estimated to grow to "<<childI<<" feets and "<<childF<<" inches."<<endl;

		cout<<"If you want to try again, press R(upper case),any other to exit:";
		cin>>check;

	}while(check=='R');
	
	return 0;
	
}
