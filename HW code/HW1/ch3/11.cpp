#include<iostream>
#include<time.h>
using namespace std;

void gameofpig();
int humanTurn(int hp);
int computerTurn(int cp);

int main(void)
{
	srand(time(NULL));
	
	gameofpig();	

	return 0;	
}
void gameofpig()
{
	int hp=0, cp=0;

	hp = humanTurn(hp);
	
	while(hp != -1)
	{
		cp = computerTurn(cp);
		if(cp==-1)
			break;
		hp = humanTurn(hp);
	}
	
}
int humanTurn(int hp)
{
	int point=0, get;
	char next;
	cout<<"\nYour score is now "<<hp<<endl;
	cout<<"It's your turn! Enter 'r' to roll."<<endl;

	cin>>next;

	while(next=='r')
	{
		get = (rand() % 6) +1;
		point = point + get;

		if(get ==  1)
		{
			cout<<"You Rolled 1 (and get no score in this round),take turn to another player.\n"<<endl;
			//not get any point in the round
			return hp;
		}	
		else 
		{
			cout<<"You rolled : "<<get<<endl;
			cout<<"Your score in this round is: "<<point<<endl;
			cout<<"Your total score is now "<<hp + point<<" if you hold."<<endl;

			if(hp + point >= 100)
			{
				cout<<"You win!"<<endl;
				cout<<"You get "<<hp +point<<" score!"<<endl;
				return -1;
			}

			cout<<"Press 'h' to hold or 'r' to roll again."<<endl;
			cin>>next;
		}
		if(next=='h')
			return (hp + point);
	}
}	

int computerTurn(int cp)
{
	int point=0, get;
	cout<<"It's computer's round."<<endl;
	cout<<"Computer's total score is now: "<<cp<<endl;
	
	while(point<20)
	{
		get = (rand() % 6) + 1;
		point = point + get;
		
		if(get == 1)
		{
			cout<<"Computer rolled 1."<<endl;
			cout<<"Get no score this round.\n"<<endl;
			return cp;
		}
	
		else
		{	
			cout<<"Computer rolled "<<get<<endl;
			cout<<"Computer's score in this round is: "<<point<<endl;
			cout<<"Computer's total score is now "<<cp + point<<endl;

			if(cp + point >= 100)
			{
				cout<<"Computer win."<<endl;
				cout<<"Score : "<<cp +point<<endl;
				return -1;
			}	
		}
	}

	cout<<"\n"<<"Computer's total score: "<<cp + point<<"\n"<<endl;
	return cp + point;
}
