#include<iostream>
using namespace std;

class D
{
	private:
		double** array;
		int MaxRows, MaxCols;
	public:
		D(int,int);
		D(D&);
		inline ~D() {delete[] array;}

		inline void input()
		{
			for(int i=0;i<MaxRows;i++)
				for(int j=0;j<MaxCols;j++)
					cin>>array[i][j];
		}
	
		D& operator =(D&);
		friend D& operator +(D&,D&);		
		friend ostream& operator <<(ostream&, D&);
};

D :: D(D& c)
{
	this->MaxRows = c.MaxRows;
	this->MaxCols = c.MaxCols;

	double** brand= new double*[MaxRows];
	for(int i=0;i<MaxRows;i++)
		brand[i] = new double[MaxCols];

	this->array = brand;

	for(int i=0;i<this->MaxRows;i++)
		for(int j=0;j<this->MaxCols;j++)
			this->array[i][j] = c.array[i][j];
	
}

ostream& operator<<(ostream& o, D& output)
{
	o<<"Rows "<<output.MaxRows<<" Columns "<<output.MaxCols<<endl;
	for(int i=0;i<output.MaxRows;i++)
	{
		for(int j=0;j<output.MaxCols;j++)
			o<<output.array[i][j]<<" ";
		o<<endl;
	}
	return o;
}

D& operator +(D& a, D& b)
{
	if(a.MaxRows != b.MaxRows || a.MaxCols != b.MaxCols)
	{
		cerr<<"Different size\n";
		return a;
	}
	D *added = new D(a);

	added->MaxRows = a.MaxRows;
	added->MaxCols = a.MaxCols;

	double** array = new double*[added->MaxRows];
	for(int i=0;i<added->MaxRows;i++)
		array[i] = new double[added->MaxCols];
	added->array = array;
	
	for(int i=0;i<added->MaxRows;i++)
		for(int j=0;j<added->MaxCols;j++)
			added->array[i][j] = a.array[i][j] + b.array[i][j];
	return *added;
}

D& D :: operator =(D& another)
{
	this->MaxRows = another.MaxRows;
	this->MaxCols = another.MaxCols;

	double** array = new double*[this->MaxRows];
	for(int i = 0;i<this->MaxRows;i++)
		array[i] = new double[this->MaxCols];

	this->array = array;
	for(int i=0;i<MaxRows;i++)
		for(int j=0;j<MaxCols;j++)
			this->array[i][j] = another.array[i][j];
	return *this;
}


D :: D(int a = 4,int b = 4)
{
	MaxRows = a;
	MaxCols = b;
	
	double** brand= new double*[MaxRows];
	for(int i=0;i<MaxRows;i++)
		brand[i] = new double[MaxCols];

	array = brand;
}


int main()
{
	int x,y;
	cout<<"Enter the row and column (default 4*4) of the array\n";
	cin>>x>>y;
	cout<<"Enter the value of eacj position\n";
	D m1(x,y);
	m1.input();

	cout<<"Enter the row and column (default 4*4) of the array\n";
	cin>>x>>y;
	cout<<"Enter the value of eacj position\n";
	D m2(x,y);
	m2.input();	

	D m3(m2);
	cout<<"Assign m2 to m3\n"<<m3<<endl;

	D m4 = m1 + m2;
	cout<<"m4 = m1 + m2\n"<<m4<<endl;
	return 0;
}

