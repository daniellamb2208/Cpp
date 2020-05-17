#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------*/

class BoxOfProduce
{
	private:
		vector<string> bundle;
	public:
		BoxOfProduce() {}
		BoxOfProduce(vector<string>);
	
		void addBundle(string);
		BoxOfProduce& boxContents();		

		friend BoxOfProduce operator+(BoxOfProduce&,BoxOfProduce&);
		friend ostream& operator<<(ostream&,BoxOfProduce&);
};

ostream& operator<<(ostream& o ,BoxOfProduce& b)
{
	for(int i=0;i<b.bundle.size();i++)
		o<<"("<<i+1<<")"<<b.bundle[i]<<" ";

	return o;
}

BoxOfProduce :: BoxOfProduce(vector<string> nv)
{
	for(int i=0;i<nv.size();i++)
		bundle.push_back(nv[i]);
}

void BoxOfProduce :: addBundle(string a)
{
	bundle.push_back(a);
}

BoxOfProduce& BoxOfProduce :: boxContents()
{
	return *this;
}

BoxOfProduce operator+(BoxOfProduce& a,BoxOfProduce& b)
{
	vector<string> nv;		//new vector
	
	for(int i=0;i<a.bundle.size();i++)
		nv.push_back(a.bundle[i]);
	for(int i=0;i<b.bundle.size();i++)
		nv.push_back(b.bundle[i]);

	return BoxOfProduce(nv);
}

/*
// --------------------------------
// --------- END USER CODE --------
// --------------------------------
// ============================================================
//     main function -- You are not allowed to change here!
// ============================================================*/
int main()
{
	BoxOfProduce b1;
	b1.addBundle("Tomato");
	b1.addBundle("Potato");

	BoxOfProduce b2;
	b2.addBundle("Apple");
	b2.addBundle("Pear");
	b2.addBundle("Kiwi");
	b2.addBundle("Durian");

	BoxOfProduce b3;
	b3 = b1 + b2;

	cout << "box-1 " <<b1.boxContents() << endl;
	cout << "box-2 " <<b2.boxContents() << endl;
	cout << "box-3 " <<b3.boxContents() << endl;

	return 0;
}
