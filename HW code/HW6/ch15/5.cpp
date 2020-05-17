#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Player
{
	public:
		Player() {}
		virtual int getGuess() = 0;
};

class Human : public Player
{
	public:
		Human() : Player() {}
		virtual int getGuess()
		{
			int a;
			cin>>a;
			return a;
		}
};

class Computer : public Player
{
	public:
		Computer() : Player() {}
		virtual int getGuess()
		{
			int a = rand()%100;
			cout<<a<<endl;
			return a;
		}
};

bool checkForWin(int guess, int answer)
{
	if (answer ==guess)
	{
		cout << "You're right! You win!" << endl;
		return true;
	}
	else if (answer < guess)
		cout << "Your guess is too high." << endl;
	else
		cout << "Your guess is too low." << endl;
	return false;
}
void play(Player &player1, Player &player2)
{
	int answer = 0, guess = 0;
	answer = rand() % 100;
	bool win = false;
	while (!win)
	{
		cout << "Player 1's turn to guess." <<endl;
		guess = player1.getGuess();
		win = checkForWin(guess, answer);
		if (win) return;
		cout <<"Player 2's turn to guess." <<endl;
		guess = player2.getGuess();
		win = checkForWin(guess, answer);
	}
}

int main()
{
	srand(time(NULL));
	cout<<"Human vs Human\n";
	Human a,b;
	play(a,b);

	cout<<"\nHuman vs Computer\n";
	Human c;
	Computer d;
	play(c,d);

	cout<<"\nComputer vs Computer\n";
	Computer e,f;
	play(e,f);

	return 0;
}
