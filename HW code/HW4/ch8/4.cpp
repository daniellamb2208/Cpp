#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;

class CharPair
{
	public: 
		CharPair(int);
		CharPair(int,char);
		int gs();
		void clean();
		char& operator [](int index);
		friend ostream& operator <<(ostream&,CharPair&);
	private:
		char array[100];
		int size;
};

ostream& operator <<(ostream &o, CharPair &c)
{
	for(int i=0;i<c.size;i++)
		o<<c[i]<<" ";

	return o;
}

char& CharPair :: operator [](int index)
{
	if(index >= size || index < 0)
	{
		cout<<"Wrong index.\n";
		exit(EXIT_FAILURE);
	}

	return array[index];
}

CharPair :: CharPair(int s)
{
	if(s > 100)
	{
		cout<<"Size cannot be over 100.\n";
		exit(EXIT_FAILURE);
	}
	size = s;

	memset(array,'#',size);
}

CharPair :: CharPair(int s, char c)
{
	if(s > 100)
	{
		cout<<"Size cannot be over 100.\n";
		exit(EXIT_FAILURE);
	}

	size = s;

	memset(array,c,size);
}

void CharPair :: clean()
{
	memset(array,'\0',100);
	size = 0;
}

int CharPair :: gs()
{
	return size;
}

int main()
{
	CharPair de(10);
	cout<<"Default : "<<de<<"\nSize : "<<de.gs()<<endl;
	de.clean();

	int s;
	char c;
	cout<<"First sz member of char array to #: ";
	cin>>s;
	CharPair cRequire(s);
	cout<<cRequire<<"\nSize : "<<cRequire.gs()<<endl;
	cRequire.clean();

	cout<<"Please input size and char(int,char) :";
	cin>>s>>c;
	CharPair dRequire(s,c);
	cout<<dRequire<<"\nSize : "<<dRequire.gs()<<endl;
	dRequire.clean();	

	return 0;
}
