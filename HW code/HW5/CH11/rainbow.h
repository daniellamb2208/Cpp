#include<iostream>

namespace rainbow
{
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

}
