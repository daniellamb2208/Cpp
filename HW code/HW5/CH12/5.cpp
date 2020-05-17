#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
using namespace std;

int main()
{
	ifstream fs;
	string filename;
	cout<<"Enter file name:\n";
	getline(cin,filename);
	fs.open(filename.c_str());

	if(fs.fail())
	{
		cerr<<"File opening failed.\n";
		exit(1);
	}

	ofstream ofs;
	ofs.open("data3_out.txt");


	int first,count = 0;
	fs>>first;
	ofs<<first<<"\n";
	while(!fs.eof())
	{
		int next;
		fs>>next;
	
		count ++ ;
		if((next -first) != 4*count)
		{
			cout<<"data3 created.\n";
			break;
		}
		else
			ofs<<next<<"\n";
	}

	fs.close();
	ofs.close();
	
	return 0;
}
