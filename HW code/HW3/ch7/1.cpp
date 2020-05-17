#include<iostream>
using namespace std;
	
const char name[7] = {'R','O','Y','G','B','I','P'};

class RainbowColor
{
	public:
		RainbowColor(char);
		RainbowColor(int);
		RainbowColor() {};

		void input();
		void output();
		void output_int();
		void output_char();
		RainbowColor next(int);

		int color;
	
};

RainbowColor :: RainbowColor(char c)
{
	for(int i=0;i<7;i++)
		if(name[i]  == c)
			color = i + 1;
	output();
}

RainbowColor :: RainbowColor(int num)
{
	if(num<=7 && num>=1)
	{
		color = num;
		output();
	}
}

void RainbowColor :: output()
{
	output_int();
	cout<<" ";
	output_char();
	cout<<endl;
}

void RainbowColor :: output_int()
{
	cout<<color;
}
void RainbowColor ::  output_char()
{
	cout<<name[color-1];
}
void RainbowColor :: input()
{
	char input_char;
	bool check = true;
	color = 0;
	while(check)
	{
		cout<<"Testing getRainbowColor and all output method."<<endl;
		cin>>input_char;
		for(int i=0;i<7;i++)
		{
			if(name[i] == input_char)
			{
				color = i + 1;
				output();			
			}		
		}
		if(color == 0)		//Not Found
		{
			cout<<input_char<<" is not a color of rainbow. Exiting \n\nend of loops.\n"<<endl;
			check = false;
		}
		
		color = 0;           //initial
	}	
}

RainbowColor RainbowColor :: next(int c)
{
	RainbowColor next;

	next.color = c+1;
	if(next.color == 8)
		next.color = 1; 		

	return next;
}
void tc()
{
	cout<<"Testing char constructor"<<endl;
	RainbowColor R('R'), O('O'), Y('Y'), G('G'), B('B'), I('I'), P('P');
}

void ti()
{
	cout<<"Testing integer constructor"<<endl;
	for(int i=0;i<7;i++)	
		RainbowColor num(i+1);
}

void testing()
{
	RainbowColor testing;
	testing.input();
}

void tn()
{
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
}
int main()
{
	tc();ti();
	testing();
	tn();

	return 0;
}
