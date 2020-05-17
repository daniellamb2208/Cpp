#include<iostream>
#include<string>
using namespace std;

void stock(string item[], int *num)
{
	cout<<"Stock\n";
	int i;
	for(i=0;i<5;i++)
		cout<<i+1<<"\t"<<num[i]<<endl;
}
void cart(string item[], int buylist[])
{
	cout<<"\nBuy list:"<<endl;
	
	int i;
	for(i=0;i<5;i++)
		if(buylist[i] != 0)
			cout<<item[i]<<"\t"<<buylist[i]<<endl;

}

int buy(int *num, int *buylist, string item[])
{
	string b;
	int amount, item_which, i;

	cout<<"Which item do you want to buy?(Item_name<b>Amount):";
	cin>>b>>amount;

	for(i=0;i<5;i++)
	{
		if(item[i] == b)		
		{
			item_which = i;
			break;
		}
	}

	num[item_which] -= amount;

	buylist[item_which] += amount;

	stock(item, num);
	cart(item, buylist);
	
	for(i=0;i<5;i++)
	{
		if(num[i] <= 0)
		{
			cout<<"Something out of stock!"<<endl;
			return 0;
		}
	}

	return 1;
}

int main()
{
	string item[5]={"Chocolate","Vanilla","Strawberry","Raspberry","Butterscotch"};
	int num[5]={20,15,15,20,20}, buylist[5]={0}, i;
	char check;
	
	cout<<"Code\tFlavor"<<endl;
	for(i=0;i<5;i++)
		cout<<i+1<<"\t"<<item[i]<<endl;

	do
	{
		if(! buy(num,buylist,item))
			break;		
	
		cout<<"Contunue? (y / n): ";
		cin>>check;
	}while(check == 'y');
	
	return 0;
}

