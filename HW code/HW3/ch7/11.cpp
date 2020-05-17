#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Player
{
	public:
		Player(string,double);

		string name;
		double score;	
};

Player :: Player(string n,double s)
{
	name = n;
	score = s;
}

void add(vector<Player> &list)
{
	string name;
	double score;
	cout<<"Enter the new player name: ";
	cin>>name;
	cout<<"Enter the highest score the player got: ";
	cin>>score;
	
	Player will_add(name,score);

	list.push_back(will_add);

	cout<<"\n"<<name<<" is now added the player list.\n";
}
void print(vector<Player> &list)
{
	cout<<"PLAYER LIST:\n";
	for(int i=0;i<list.size();i++)
		cout<<list[i].name<<" "<<list[i].score<<endl;
	cout<<"\n-----------------------\n";
}
void search(vector<Player> &list)
{
	string find;
	cout<<"Which player would you like to search for?\n";
	cin>>find;

	int found=-1;
	for(int i=0;i<list.size();i++)
		if(list[i].name == find)
			found = i;

	if(found == -1)
		cout<<"Not found the player in the player list.\n";
	else
		cout<<find<<"'s highest score is "<<list[found].score<<endl;
}

void deleted(vector<Player> &list)
{
	string to_be_removed;
	cout<<"Which player would you like to remove from the list?\n";
	cin>>to_be_removed;

	int found=-1;
	for(int i=0;i<list.size();i++)
		if(list[i].name == to_be_removed)
			found = i;

	if(found == -1)
		cout<<"Not found the player in the player list.\n";
	else
	{
		list.erase(list.begin()+found);
		cout<<"Player "<<to_be_removed<<" has been removed from playerlist.\n";
	}
}
int main()
{	
	cout<<"Options (only a charcter with a b c d e)"<<endl;
	cout<<"a. Add new player and whose score.\n";
	cout<<"b. Print all players and scores.\n";
	cout<<"c. Search for a player's score.\n";
	cout<<"d. Remove a player from the list.\n";
	cout<<"e. Quit.\n";
	
	char options;
	vector<Player> list;	

	while(cin>>options && options != 'e')
	{
		switch(options)	
		{
			case 'a':
				if(list.size() >= 10)
				{
					cout<<"There's been already ten players in the list.\n";
					break;
				}				
				add(list);
				break;
			case 'b':
				print(list);
				break;
			case 'c':
				search(list);
				break;
			case 'd':
				deleted(list);
				break;
			default:
				cout<<"Wrong input.\n";
		} 	
	}

	return 0;
}
