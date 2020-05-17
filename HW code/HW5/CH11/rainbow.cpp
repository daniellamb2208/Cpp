#include"rainbow.h"
using namespace rainbow;

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
