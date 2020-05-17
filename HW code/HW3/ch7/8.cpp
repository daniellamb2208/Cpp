#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int c, min=0;
	vector<int> input;

	cout<<"Enter each grade and then -1 to stop:"<<endl;
	while(cin>>c && c != -1)
		input.push_back(c);

	vector<int> histogram(*max_element(input.begin(),input.end())+1,0);
	
	for(int i=0;i<input.size();i++)
		histogram[input[i]] ++;

	for(int i=0;i<histogram.size();i++)
		cout<<histogram[i]<<" grade(s) of "<<i<<endl;

	return 0;
}

