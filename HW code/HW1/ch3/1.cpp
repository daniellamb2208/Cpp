#include<iostream>
using namespace std;
#define M 8000;
double file_size(double r,double d)
{
	r = r / M;
	d = d * 60;
	return (r * d);
}

int main(void)
{	
	double rate , dura , size;
	cout<<"Bit rate:";
	cin>>rate;
	cout<<"The duration in minutes of a video clip:";
	cin>>dura;
	
	size = file_size(rate,dura);

	cout<<"The file size of the video clip in megabytes:"<<size<<endl;
	
	return 0; 
}
