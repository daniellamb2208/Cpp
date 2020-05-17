#include<iostream>
#include<cstring>
#include<fstream>
#include<iomanip>
using namespace std;

struct employee
{
	int num;
	double core;
	double performance;
	double ideation;
	double score;
	int rank;
};

int main()
{
	int i;
	string a,b,c,d;
	fstream fs;
	fs.open("CH6_01_data.txt");

	fs>>a>>b>>c>>d;

	employee who[5];
	for(i=0;i<5;i++)
	{
		fs>>who[i].num
		  >>who[i].core
		  >>who[i].performance
		  >>who[i].ideation;
	}
	fs.close();

	for(i=0;i<5;i++)
	{
		who[i].score = (who[i].core / 10 * 3 +who[i].performance / 30 * 5 +who[i].ideation / 10 * 2) * 10;
		if(who[i].score >= 80)
			who[i].rank = 1;
		else if (who[i].score < 80 && who[i].score >=60)
			who[i].rank = 2;
		else if (who[i].score < 60 && who[i].score >=50)
			who[i].rank = 3;
		else
			who[i].rank = 4;
	}

	cout<<"Number\tTotal\tPoint\n";

	for(i=0;i<5;i++)
		cout<<who[i].num<<"\t"<<fixed<<setprecision(2)<<who[i].score<<"\t"<<who[i].rank<<endl;

	return 0;
}
