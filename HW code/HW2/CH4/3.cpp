#include<iostream>
using namespace std;

const int A=10,B=20,C=30,D=40;
void cal(int &itemCode,int &voucherValue);

int main(void)
{
	int itemCode, voucherValue;
	
	cout<<"1.Bagel:"<<A<<endl;
	cout<<"2.Cake:"<<B<<endl;
	cout<<"3.Croissant:"<<C<<endl;
	cout<<"4.Toast:"<<D<<endl;
	cout<<"Input your value of voucher:";
	cin>>voucherValue;

	do
	{
		cout<<"Which item do you want?";
		cin>>itemCode;
		cout<<"\n";
		cal(itemCode,voucherValue);
	}while(voucherValue>A);
	
	cout<<"\nYou don'y have enough value of voucher to buy anything."<<endl;
	return 0;
}

void cal(int &itemCode,int &voucherValue)
{
	switch(itemCode)
	{
		case 1:
			cout<<"The price of item which you buy is:"<<A<<endl;
			voucherValue -= A;
			break;
		case 2:
			cout<<"The price of item which you buy is:"<<B<<endl;
			voucherValue -= B;
			break;
		case 3:
			cout<<"The price of item which you buy is:"<<C<<endl;
			voucherValue -= C;
			break;
		case 4:
			cout<<"The price of item which you buy is:"<<D<<endl;
			voucherValue -= D;
	}
	
	cout<<"You still have value of voucher:"<<voucherValue<<endl;

}
