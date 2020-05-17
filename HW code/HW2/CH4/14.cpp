#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int cal_dif(string s,string e)
{
	stringstream ss;
	int st, et;
	ss<<s;
	ss>>st;
	ss.str("");
	ss.clear();
	ss<<e;
	ss>>et;

	int st_h, st_m, et_h, et_m;
	int dm = 0;                   //difference about minutes
	st_h = st / 100;
	st_m = st % 100;
	et_h = et / 100;
	et_m = et % 100;

	if(st == et)
		dm = 0;

	else if(st < et)
	{
		if(st_m < et_m)
			dm = (et_m - st_m) + (et_h - st_h)*60 ;
		else
			dm = (60 - st_m) + et_m + (et_h - st_h - 1)*60 ;	
	}

	else
		dm = ((23 - st_h) + et_h)*60 + (60 - st_m) + et_m ;
	
	return dm;	
}


int main(void)
{
	string start, end;
	char y;
	do
	{
		cout<<"Please input start time and end time:";
		cin>>start>>end;

		if(start.length() != 4 || end.length() != 4)
			cout<<"Error input!"<<endl;
		else
			cout<<"The time difference between "<<start<<" and "<<end<<" is "<<cal_dif(start,end)<<" minutes."<<endl;
			
		cout<<"Calculate again? (y/n):";
		cin>>y;

	}while(y == 'y');

	return 0;
}
