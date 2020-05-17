#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<cstring>
using namespace std;

void read(vector<string> &file)
{
	string song;
	fstream fs;
	fs.open("list.txt");
	
	while(getline(fs,song))
	{
		file.push_back(song);
		if(fs.peek() == '\n')
			fs.ignore(1);
	}	
		
	fs.close();
}

void a(vector<string> &file)
{
	for(int i=0;i<file.size();i++)
	{
		while(file[i][0] != ' ')
			file[i].erase(0,1);
		file[i].erase(0,1);
	}
}

void b(vector<string> &file)
{
	for(int i=0;i<file.size();i++)
	{
		for(int j=0;j<file[i].size();j++)
		{
			if(file[i][j] == ' ' && file[i][j+1] == ' ')
			{
				file[i].erase(j,1);
				j--;
			}		
		}
	}
}

void c(vector<string> &file)
{
	for(int i=0;i<file.size();i++)
	{
		int count = 0;
		for(int j=0;j<file[i].size();j++)
			if(file[i][j] == '-')
				count++;
		if(count>1)
		{
			for(int j=0;j<file[i].size();j++)
			{
				if(file[i][j] == '-')
				{
					file[i][j] = ' ';
					count--;
					if(count == 1)
						break;
				}
			}
		}
	}
}

void d(vector<string> &file)
{
	for(int i=0;i<file.size();i++)
	{
		for(int j=0;j<file[i].size();j++)
		{
			if(file[i][j] == '-' && file[i][j-1] != ' ')
			{
				file[i].insert(j,1,' ');
				break;
			}
		}

		file[i][file[i].size()] = '\0';
	}
}

void e(vector<string> &file)
{
	int name;
	string song,composer;
	for(int i=0;i<file.size();i++)
	{
		song.clear();
		composer.clear();
		for(int j=0;j<file[i].size();j++)
		{
			if(file[i][j] == '-')
			{
				name = j;
				break;
			}
		}

		song = file[i].substr(0,name-1);
		composer = file[i].substr(name+2,file[i].size()-(name+2)-1);
		file[i] = composer + " - " +song;
	}
}

void exhausted()
{	
	vector<string> song;

	read(song);

	a(song);
	b(song);
	c(song);	
	d(song);
	e(song);
	sort(song.begin(),song.end());

	for(int i=0;i<song.size();i++)
		cout<<i+1<<". "<<song[i]<<endl;
}

int main()
{
	exhausted();

	return 0;
}
