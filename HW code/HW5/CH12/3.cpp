#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
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

	vector<double> data;
	while(!fs.eof())
	{
		double input;
		fs>>input;
		data.push_back(input);
	}
	fs.close();
	sort(data.begin(),data.end());

	int size = data.size();
	
	if(size % 2)	//odd
	{
		int half = (size-1) / 2;
		cout<<"Median name: "<<data[half]<<endl;

		double front[half], back[half];
		for(int i=0;i<half;i++)
		{
			front[i] = data[i];
			back[i]  = data[size-i];
		}

		if(half % 2)
		{		
			int quater = (half-1) / 2;
			cout<<"Quatile: "<<front[quater]<<" "<<data[half]<<" "<<back[quater]<<endl;						
		}	
		else
		{
			int upper = size/2 ,lower = upper - 1;
			double f_quatile = (front[upper] + front[lower]) / 2;
			double median = data[half];
			double td_quatile = (back[upper] + back[upper]) / 2;

			cout<<"Quatile: "<<f_quatile<<" "<<median<<" "<<td_quatile<<endl;
		}		
	}
	else
	{
		int upper_t = size / 2, half = upper_t;
		int lower_t = upper_t -1;

		double median = (data[upper_t] + data[lower_t]) / 2;
		double front[half], back[half];
		for(int i=0;i<half;i++)
		{
			front[i] = data[i];
			back[i] = data[size-i];
		}
		
		if(half % 2)
		{		
			int quater = (half-1) / 2;
			cout<<"Quatile: "<<front[quater]<<" "<<data[half]<<" "<<back[quater]<<endl;						
		}
		else
		{
			int upper = size/2 ,lower = upper - 1;
			double f_quatile = (front[upper] + front[lower]) / 2;
			double median = data[half];
			double td_quatile = (back[upper] + back[upper]) / 2;

			cout<<"Quatile: "<<f_quatile<<" "<<median<<" "<<td_quatile<<endl;
		}					
	}	

	return 0;
}
