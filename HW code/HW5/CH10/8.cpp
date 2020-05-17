#include<iostream>
#include<string>
#include<vector>
using namespace std;

class TV
{
	private:
		string displayType;
		double dimension;
		string* connectivitySupport;
		int num;
	public:
		inline TV() {}
		TV(string,double,string*,int);
		void custimize();
		friend ostream& operator <<(ostream&, TV&);
		TV& operator =(TV&);
};

TV :: TV(string t,double d,string* l,int n)
{
	displayType = t;
	dimension = d;
	connectivitySupport = l;
	num = n;
}

void TV :: custimize()
{
	cout<<"Enter the display type:\n";
	cin>>this->displayType;
	cout<<"Enter the TV dimension:\n";
	cin>>this->dimension;
	cout<<"Enter the number of connectivity support mode:\n";
	cin>>this->num;
	delete[] this->connectivitySupport;
	this->connectivitySupport = new string[num];
	cout<<"Enter the connectivity support types:\n";
	for(int i=0;i<this->num;i++)
	{
		cout<<i+1<<": ";
		cin>>connectivitySupport[i];
	}
}

TV& TV :: operator=(TV& o)
{
	this->displayType = o.displayType;
	this->dimension = o.dimension;

	this->connectivitySupport = new string[o.num];

	for(int i=0;i<this->num;i++)
		this->connectivitySupport[i] = o.connectivitySupport[i];

	return *this;
}

ostream& operator <<(ostream& o, TV& output)
{
	o<<"Display type: "<<output.displayType<<endl;
	o<<"Dimension (inches): "<<output.dimension<<endl;
	o<<"Connectivity support type:\n";
	for(int i=0;i<output.num;i++)
		o<<i+1<<": "<<output.connectivitySupport[i]<<endl;
		
	return o;
}

int main()
{
	string type, *list;
	double dimension;
	int num;

	cout<<"Enter default TV display type: ";
	cin>>type;
	cout<<"Enter default TV dimension: ";
	cin>>dimension;
	cout<<"Enter the default number of connectivity modes: ";
	cin>>num;
	
	list = new string[num];
	for(int i=0;i<num;i++)
	{	
		cout<<i+1<<": ";
		cin>>list[i];
	}
	TV theDefault(type, dimension, list, num);
	cout<<theDefault;

	cout<<"Enter TV numbers: ";
	cin>>num;

	vector<TV> proto;

	for(int i=0;i<num;i++)
		proto.push_back(theDefault);

	int index;

	while(cout<<"Enter index of TVs to custimize, (-1 for exit)\n" && cin>>index && index != -1)
	{
		if(index >= num)
			cerr<<"Error index.\n";
		else
			proto[index].custimize();
	}

	for(int i=0;i<num;i++)
		cout<<"\nTV"<<i+1<<"\n"<<proto[i];
	
	return 0;
}
