#include<iostream>
#include<cstring>
#include<fstream>
#include<time.h>
#include<cstdlib>
#include<vector>
using namespace std;

vector<string> cat;

class BoxOfProduce
{
	public:
		BoxOfProduce(int);		
		friend ostream& operator <<(ostream&, BoxOfProduce&);
		friend BoxOfProduce& operator +(BoxOfProduce&,BoxOfProduce&);

	private:
		vector<string> bundle;
};

BoxOfProduce :: BoxOfProduce(int more)
{
	for(int i=0;i<more;i++)
		bundle.push_back(cat[rand()%5]);
}

void getCategories()
{
	fstream fs;
	string a;
	fs.open("produce.txt");
	for(int i=0;i<5;i++)
	{
		fs>>a;
		cat.push_back(a);
	}	
	fs.close();
}

ostream& operator <<(ostream &o, BoxOfProduce &b)
{
	for(int i=0;i<b.bundle.size();i++)
		o<<"("<<i+1<<")"<<b.bundle[i]<<" ";

	o<<endl;
	
	return o;
}
BoxOfProduce& operator +(BoxOfProduce &ini,BoxOfProduce &added)
{
	for(int i=0;i<added.bundle.size();i++)
		ini.bundle.push_back(added.bundle[i]);

	return ini;
}


int main()
{
	srand(time(NULL));

	getCategories();

	BoxOfProduce initial(2);
	
	cout<<"The box contains: "<<initial<<endl;	

	char m;
	while(cout<<"Would you like more bundles ?(y/n):" && cin>>m && m == 'y')
	{
		BoxOfProduce add(rand()%3+1);
		cout<<"The box contains: "<<initial+add<<endl;
	}

	return 0;
}


