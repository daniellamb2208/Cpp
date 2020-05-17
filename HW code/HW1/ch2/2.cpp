#include<iostream>
#include<iomanip>
using namespace std;
int main(void)
{
	int i = 0;
	double remaining , rate , withdraw , interests , temp;
	
	cout<<"deposit:";
	cin>>remaining;
	cout<<"Rate:";
	cin>>rate;
	cout<<"Fixed amount withdrawn every month:";
	cin>>withdraw;	
	
	cout<<"\n"<<"Month\t\tInterest\tPrinciple"<<endl;
	
	remaining = remaining - withdraw;

	while(1)
	{
		i++;
		temp = remaining;
		remaining = remaining * (1 + rate);
		interests = remaining - temp;
		
//		cout.unsetf(ios::fixed);                    let i be int without decimal problem 
		cout<<i<<"\t\t";
		cout<<fixed<<setprecision(2)<<interests<<"\t\t"<<remaining<<endl;
		
		if(remaining<withdraw)
		{
			remaining = remaining * (1 + rate);
			break;		
		}
	
		remaining = remaining - withdraw;	
	}


		cout<<"\n";
		cout<<"number of payments   = "<<i+1<<endl;
		cout<<"last month insterest = "<<interests<<endl;
		cout<<"last patments        = "<<remaining<<endl;	
	
	return 0;
}
