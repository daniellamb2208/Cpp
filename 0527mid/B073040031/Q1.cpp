#include <iostream>
#include <string>
#include <vector>
using namespace std;

/* Please complete the program here by class definition
                                  and function definitions*/
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------*/

class Player
{
	private:
		string name;
		int score;
	public:
		Player() {}
		Player(string n, int s) : name(n), score(s) {}
		inline string getname() const {return name;}
		inline int getscore() const {return score;}
};

void addPlayer(int& n, vector<Player>& l)
{
	if(n>=5)
	{
		cerr<<"The club is full.\n";
		return ;
	}

	n++;

	string name;
	int score;

	cout<<"Enter new player's name\n";
	cin>>name;
	cout<<"Enter new player's socre\n";
	cin>>score;

	Player np(name,score);
	
	l.push_back(np);
}

void printPlayer(int n, const vector<Player>& l)
{
	cout<<"Player list\n";
	for(int i=0;i<n;i++)
		cout<<l[i].getname()<<" "<<l[i].getscore()<<endl;

}

void searchPlayer(int n,const vector<Player>& l)
{
	string sn;
	cout<<"Which player would u like to search for?\n";
	cin>>sn;

	int index = -1;

	for(int i=0;i<n;i++)
		if(l[i].getname() == sn)
			index = i;

	if(index != -1)
		cout<<"The score of "<<sn<<" is "<<l[index].getscore()<<endl;	
	else
		cerr<<"The player isn't in the club.\n";	
}

void removePlayer(int& n, vector<Player>& l)
{
	string rn;
	cout<<"Which player would u like to remove from the club?\n";
	cin>>rn;

	int index = -1;
	for(int i=0;i<n;i++)
		if(l[i].getname() == rn)
			index = i;

	if(index == -1)
		cerr<<"The player isn't in this club.\n";
	else
	{
		l.erase(l.begin()+index);
		cout<<rn<<" removed.\n";
		n--;
	}
}

/*
// --------------------------------
// --------- END USER CODE --------
// --------------------------------

// You cannot change this part of code*/
int main()
{
  char option;
  vector<Player> players;
  int numPlayers=0;

  do
  {
   cout << "Enter an option." << endl;
   cout << "a. Add new player and score." << endl;
   cout << "b. Print all players and scores." << endl;
   cout << "c. Search for a player's score." << endl;
   cout << "d. Remove a player." << endl;
   cout << "e. Quit." << endl;

   cin >> option;
   cout << endl;
   if (option == 'a')
     addPlayer(numPlayers, players);
   else if (option == 'b')
     printPlayer(numPlayers, players);
   else if (option == 'c')
     searchPlayer(numPlayers, players);
   else if (option == 'd')
     removePlayer(numPlayers, players);
   cout << endl;
  } while (option != 'e');

  return 0;
}
