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
	getline(cin, filename);
	fs.open(filename.c_str());

	if(fs.fail())
	{
		cerr<<"File opening failed.\n";
		exit(1);
	}
	
	double data, sum = 0, count = 0;

	while(fs >> data)
	{
		sum += data;
		count++;
	}
	fs.close();

	cout<<"Average of "<<count<<" numbers is: "<<sum / count<<endl;


	return 0;
}
