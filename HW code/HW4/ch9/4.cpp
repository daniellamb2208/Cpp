#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

void transform(string s)
{
	string shortstring, newstring="";

	int i=0;

	while(i<s.size())
	{
		shortstring = "";
		do
		{

			shortstring += s[i];
			i++;
		}while(isalpha(s[i-1]) && isalpha(s[i]));

		if(shortstring.size() == 4)
		{
			if(isupper(shortstring[0]))
				shortstring = "Love";
			else
				shortstring = "love";
		}
		
		newstring += shortstring;
	}

	cout<<newstring<<endl;
}

int main()
{
	string input;

	cout<<"When enter a single ""-1"" in one line will this program end.\n";
	while(getline(cin,input) && input != "-1")
		transform(input);

	return 0;
}
