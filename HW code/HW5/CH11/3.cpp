#include<iostream>
#include"rainbow.h"
using std::endl;
using std::cout;
using std::cin;
using namespace rainbow;


int main()
{
	cout<<"Testing char constructor"<<endl;
	RainbowColor R('R'), O('O'), Y('Y'), G('G'), B('B'), I('I'), P('P');

	cout<<"Testing integer constructor"<<endl;
	for(int i=0;i<7;i++)	
		RainbowColor num(i+1);

	RainbowColor testing;
	testing.input();

	cout<<"Testing nextRainbowColor member\n";

	RainbowColor test_here;

	while(true)
	{
		test_here.color = 0;		
		char c;
		cin>>c;		
		
		for(int i=0;i<7;i++)
			if(name[i] == c)
				test_here.color = i+1; 
		if(test_here.color == 0)
		{		
			cout<<c<<" is not a color of rainbow .\tExiting"<<endl;		
			break;
		}

		RainbowColor test_next = test_here.next(test_here.color);

		cout<<"Current Rainbowcolor: ";
		test_here.output();
		cout<<"Next Rainbowcolor: ";
		test_next.output();		
	}

	return 0;
}

