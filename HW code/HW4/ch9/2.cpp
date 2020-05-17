#include<iostream>
#include<cstring>
using namespace std;

void decrypt(string e)
{	
	int asc;

	for(int i=0;i<e.size();i++)
	{
		if(isalpha(e.at(i)) && isupper(e.at(i)))
		{
			asc = e.at(i) - 'A';
			asc = (asc + 3) % 26;
			e.at(i) = asc + 'A';
		}
		else if(isalpha(e.at(i)) && islower(e.at(i)))
		{
			asc = e.at(i) - 'a';
			asc = (asc + 3) % 26;
			e.at(i) = asc + 'a';
		}
		else if(isdigit(e.at(i)))
		{
			asc = e.at(i) - '0';
			asc = (asc + 5) %10;
			e.at(i) = asc + '0';
		}
		else if(e.at(i) == '\n' || e.at(i) == ' ')
		{
			e.erase(i,1);
			i--;
		}	
		else
			e.at(i) = ' ';
	}

	cout<<e<<endl;
}

int main()
{
	cout<<"When enter a single ""-1"" in one line will this program end.\n";
	string encrypted;

	while(getline(cin,encrypted) && encrypted != "-1")
		decrypt(encrypted);

	return 0;
}
