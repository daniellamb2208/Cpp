#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cmath>
#include<iomanip>
using namespace std;
#define N 1000
void creat()
{
	fstream fs;
	fs.open("Data.txt");
	
	for(int i=0;i<N;i++)
		fs<<rand()<<endl;

	fs.close();
}

void read()
{
	fstream fs;
	fs.open("Data.txt");

	string data[N];
	double time[10];	

	for(int i=0;i<N;i++)
	{
		fs>>data[i];
		time[(data[i][0]-'0')] ++;
	}	
	for(int i=0;i<10;i++)
		cout<<i<<"\t"<<setw(5)<<setprecision(3)<<(time[i] / N * 100)<<" %"<<endl;	

	fs.close();
}

int main()
{
	srand(time(NULL));
	
	creat();
	read();	

	return 0;
}
