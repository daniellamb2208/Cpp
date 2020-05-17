#include<iostream>
#include<string>
#include<cmath>
using namespace std;

void input(int &m, int &r)
{
	cout<<"Enter a movie to rate(100-105): ";
	cin>>m;
	cout<<"Enter ranting for this movie(1-5): ";
	cin>>r;
}

int cal(const int ms[][6],const int ip[][2])
{
	int a[4], b[4], c[4], i, j;
	double dis[4];
	
	for(i=0;i<4;i++)
	{
		a[i] =  ms[i][ip[0][0]] - ip[0][1]  ;
		b[i] =  ms[i][ip[1][0]] - ip[1][1]  ;
		c[i] =  ms[i][ip[2][0]] - ip[2][1]  ;
	
		dis[i] = sqrt((a[i]*a[i] + b[i]*b[i] + c[i]*c[i]));
//		cout<<dis[i]<<endl;
	}
	
    double min = dis[0];              
	int  index = 0, t;
	
	for(i=1;i<4;i++)
	{
		if(min > dis[i])
		{
			min = dis[i];
			index = i;	
		}	
	}

	return index;
}

int in(int i,int ip[][2])
{
	for(int j=0;j<3;j++)
		if(i == ip[j][0])
			return 1;
	
	return 0;
} 

int main()
{
	int ms[4][6]={3,1,5,2,1,5
		     ,4,2,1,4,2,4
		     ,3,1,2,4,4,1
		     ,5,1,4,2,4,2};
	
	int ip[3][2], i, j, k, predict;	

	for(i=0;i<3;i++)
	{
		input(ip[i][0],ip[i][1]);
		ip[i][0] %= 100;
	}
	
	predict = cal(ms,ip);
	cout<<"The closest reviewer is number : "<<predict<<endl;
	
	cout<<"Prediction for movies you have not seen:"<<endl;
	
	for(i=0;i<6;i++)
		if(!in(i,ip))
			cout<<"Movie "<<(i+100)<<" : "<<"Predictd Rating = "<<ms[predict][i]<<endl;	

	

	return 0;
}
