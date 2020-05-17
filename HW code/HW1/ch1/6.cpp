#include<iostream>
using namespace std;
int main(void)
{
	double dis,time,fee=0;

	cout<<"Distance and Time:";
	cin >> dis >> time ;
	
	if(dis <= 2 && dis > 0)
		dis = 2;
	else if(dis > 2 && dis <= 8)
	{
		dis = dis - 2;
		dis = dis * 0.5;
		dis = dis + 2;
	}
	else if(dis > 8)
	{
		dis = dis - 8;      //exclude first 6k
		dis = dis * 1;      //after 6k
		dis = dis + 2 + (6 * 0.5); 
	}
	else
		cout<<"Something wrong with entering the distance."<<endl;

	time = time * 0.2;	

	fee = dis + time;
	
	cout<<"Total fee: "<<fee<<endl;

	return 0;
}
