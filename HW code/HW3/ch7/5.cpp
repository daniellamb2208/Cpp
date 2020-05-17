#include<iostream>
#include<vector>
using namespace std;

int main()				
{
	int size;
	cout<<"Enter the number of suitors\n";
	cin>>size;
	vector<int> line;
	
	for(int i=0;i<size;i++)
		line.push_back(i+1);

	int eliminate=2;

	for(int i=0;i<size-1;i++)
	{
		line.erase(line.begin()+eliminate);
		(eliminate += 2)  %= int(line.size());
	}	

	cout<<"You should stand in position "<<line[0]<<" to win the princess."<<endl;
	
	return 0;
}
