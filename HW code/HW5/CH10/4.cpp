#include <iostream>
#include <string>

using namespace std;

class Subscriber
{
	private:
		string name;
		int numChannel;
		string* channelList;
	public:
		Subscriber();
		Subscriber(string n,int c);
		~Subscriber();

		void InputData();
		void OutputData();
		void ResetChannels();
		Subscriber& operator=(Subscriber&);			
};
Subscriber :: Subscriber() 
{
	name = ""; 
	numChannel = 0;
	channelList = NULL;
}

Subscriber :: Subscriber(string n,int c) : name(n), numChannel(c) 
{
	channelList = NULL;
}

Subscriber :: ~Subscriber()
{
	numChannel = 0;
	delete[] channelList;
}

void Subscriber :: InputData()
{
	cout<<"Enter Subscriber's name\n";
	cin>>this->name;
	cout<<"Enter the number of channels\n";
	cin>>this->numChannel;
	
	this->channelList = new string[numChannel];

	for(int i=0;i<numChannel;i++)
	{
		string noc;			//name of channel
		cout<<"Enter name of channel "<<i+1<<endl;
		cin>>this->channelList[i];
	}
}	

void Subscriber :: OutputData()
{
	cout<<"Name: "<<name<<endl;
	cout<<"The number of Channel: "<<numChannel<<endl;
	
	if(numChannel == 0)
		cout<<"\n";	
	else
		for(int i=0;i<numChannel;i++)
			cout<<"\tChannel "<<i+1<<":"<<channelList[i]<<endl;

}

void Subscriber :: ResetChannels()
{
	numChannel = 0;
	channelList = NULL;
}	

Subscriber& Subscriber :: operator=(Subscriber& o)
{
	this -> name = o.name;
	this -> numChannel = o.numChannel;

	this -> channelList = new string[this -> numChannel];
	
	for(int i=0;i<numChannel;i++)
		this->channelList[i] = o.channelList[i];

	return *this;
}

int main()
{

  Subscriber s1, s2;

  cout << "Test of default constructor:" << endl;
  s1.OutputData();

  s1.InputData();		
  cout << "Subscriber 1's data:" << endl;
  s1.OutputData();		

  cout << endl;

  s2 = s1;
  cout << "Subscriber 2's data after assignment from Subscriber 1:" << endl;
  s2.OutputData();		

  s1.ResetChannels();
  cout << "Subscriber 1's data after reset:" << endl;
  s1.OutputData();		

  cout << "Subscriber 2's data, should still have original channels:" << endl;
  s2.OutputData();		

  cout << endl;
  return 0;
}
