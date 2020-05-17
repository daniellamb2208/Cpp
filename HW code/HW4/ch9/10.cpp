#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Trivia
{
	public:
		Trivia(string,string,int);
		friend ostream& operator <<(ostream&, Trivia&);

		string gq() {return question;}
		string ga() {return answer;}
		int gm()    {return  award;}

	private:
		string question;
		string answer;
		int award;
};

Trivia :: Trivia(string q, string a, int m) : question(q),answer(a),award(m)
{}

ostream& operator <<(ostream &o, Trivia &t)
{
	o<<t.question<<endl;

	return o;
}
int main()
{
	cout<<"It's kinda hard Trivia game~Now you have $0.\nLet's start.\n";
	
	Trivia question1("Who wrote Lazarillo de Tormes?","anonymous",10),
	       question2("How many states are there in the United States of America?","50",10),
	       question3("Which German city is famous for the perfume it produces?","Cologne",10),
	       question4("What year did the Spanish Civil War end?","1939",10),
	       question5("Where is the smallest bone in the body? ","ear",10),
	       question6("What’s the best known artificial international language?","esperanto",15),
	       question7("How many dots are there on two dice?","42",15),
	       question8("How many children has Queen Elizabeth the Second got?","4",15),
	       question9("When did the American Civil War end? ","1865",15),
	       question10("Which is the largest ocean?","Pacific",15),
	       question11("What was Portuguese name for Taiwan?","Ilha Formosa",100);

	vector<Trivia> question;
	
	question.push_back(question1);
	question.push_back(question2);
	question.push_back(question3);
	question.push_back(question4);
	question.push_back(question5);
	question.push_back(question6);
	question.push_back(question7);
	question.push_back(question8);
	question.push_back(question9);
	question.push_back(question10);
	question.push_back(question11);

	string ans;
	int win = 0;
	
	for(int i=0;i<question.size();i++)
	{
		cout<<i+1<<". "<<question[i];
		cin>>ans;
		if(ans == question[i].ga())
		{
			cout<<"Bingo!  You win $"<<question[i].gm()<<endl;
			win = win + question[i].gm();
		}
		else
			cout<<">< Wrong answer~The answer is "<<question[i].ga()<<endl;

		cout<<"You have won $"<<win<<"\n\n";
	}

	cout<<"Game over. You totally win $"<<win<<endl;

	return 0;
}

