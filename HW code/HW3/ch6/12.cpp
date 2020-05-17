#include<iostream>
#include<cstring>
#include<fstream>
#include<time.h>
#include<cstdlib>
using namespace std;

class BoxOfProduce
{
	public:
		void mutator();
		void accessor();		
		void getAll(); //read file
		void output();

	private:
		string all[5];		
		string bundle[3];
};

void BoxOfProduce :: getAll()
{
	fstream fs;
	fs.open("produce.txt");
	for(int i=0;i<5;i++)
		fs>>all[i];
	fs.close();
}

void BoxOfProduce :: accessor()
{
	getAll();
	srand(time(NULL));
	for(int i=0;i<3;i++)
		bundle[i] = all[rand() % 5] ; 
}

void BoxOfProduce :: output()
{
	accessor();

	char check = 'c'; 
	while(check != 'q')	
	{
		cout<<"The box contain: (1)"<<bundle[0]<<" (2)"<<bundle[1]<<" (3)"<<bundle[2]<<endl;
		cout<<"Enter 'c' to change a bundle.\n";
		cout<<"Enter 'q' to quit.\n";

		cin>>check;

		if(check == 'c')
			mutator();

	}
	cout<<"Final contents: "<<endl;
	cout<<"The box contain: (1)"<<bundle[0]<<" (2)"<<bundle[1]<<" (3)"<<bundle[2]<<endl;
}

void BoxOfProduce :: mutator()
{
	int change;
	cout<<"Enter the index of item to change: ";
	cin>>change;
	cout<<"Enter the item to substitute: ";
	cin>>bundle[change-1];
}


int main()
{
	BoxOfProduce buy;
	
	buy.output();

	return 0;
}


