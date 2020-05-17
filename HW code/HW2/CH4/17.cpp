#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int getPlayerScore(string n, string *name, int *s, int m)
{
	for(int i=0;i<m;i++)
	{	
		if(n == name[i])
			return s[i];
	}
	
	return 0;
}
void output(string n, string *name, int *s, int m, int ave)
{
	int score = getPlayerScore(n, name, s, m);
	if(score)
	{
		cout<<n<<" : ";

		if(score > ave)
			cout<<score<<" is higher than average."<<endl;
		else if(score < ave)
			cout<<score<<" is lower than average."<<endl;
		else
			cout<<score<<" is just the same as average."<<endl;
	}
	else
		cout<<"Not found in the player's list."<<endl;

}
int main(void)
{
	fstream fs;
	fs.open("scores.txt");
	
	int score[10], member=0, sum=0, average;
	string name[10];

	while(fs>>name[member]>>score[member])
		member++;
	fs.close();

	for(int i=0;i<member;i++)
		sum += score[i];

	average = sum / member;
	cout<<"Average is : "<<average<<endl;
	
	while(1)
	{
		string n;
		cout<<"Please enter the player's name: ";
		cin>>n;			
		
		output(n, name, score, member, average);
	}
	
	return 0;
}
