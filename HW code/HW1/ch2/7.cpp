#include<iostream>
using namespace std;

int main(void)
{
	int subject , i , j=1 , point , count=0;
	double avg;
	cout<<"Input the number of subjects:"<<endl;
	cin>>subject;

	char score;
	i=subject;
	cout<<"Please use UPPER case."<<endl;
	while(i>0)
	{
		cout<<"Score recieved for subjects "<<j<<":";
		j++;
		cin>>score;

		switch(score)
		{
			case 'S':
				point = 10; break;
			case 'A':
				point = 9; break;
			case 'B':
				point = 8; break;
			case 'C':
				point = 7; break;
			case 'D':
				point = 6; break;
			case 'E':
				point = 5; break;
			case 'F':
				point = 0; break;
			default:
				cout<<"Please use UPPER case."<<endl;				
		}
		count = count + point;

		i--;
	}
	avg = double(count) / double(subject) ;
	cout<<"The average of the grade points :"<<avg<<endl;
	return 0;
}
