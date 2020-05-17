#include<iostream>
#include<string>
#include<vector>
using namespace std;

class blog
{
	public:
		blog () {}
		vector<string> p;
};

class owner : public blog
{
	public:
		owner() {}
		void post() 
		{
			string po;
			cout<<"New post:";
			cin>>po;
			p.push_back(po); 
			cout<<"Posted\n";
		}
		void display()
		{
			for(int i=0;i<p.size();i++)
				cout<<i+1<<". "<<p[i]<<endl;
		}
		void deleted()
		{
			int n;
			cout<<"Choose the post you would like to delete ";
			cin>>n;
			p.erase(p.begin()+n-1);
			cout<<"The post is gone\n";
		}
};


class viewer : public blog
{
	public:
		viewer(owner& e)
		{
			for(int i=0;i<e.p.size();i++)
				this->p.push_back(e.p[i]);
		}
		void display()
		{
			for(int i=0;i<p.size();i++)
				cout<<i+1<<". "<<p[i]<<endl;
		}
};

int main()
{
	owner A;
	int c;
	cout<<"First enter data as the owner.\n";
	cout<<"0 for eixt\n1 for display all\n2 for post new\n3 for delete\n";
	while(cout<<"Enter command: " && cin>>c && c!=0)
	{
		if(c==1)
			A.display();
		else if(c==2)
			A.post();
		else if(c==3)
			A.deleted();
		else
			cerr<<"Something wrong\n";
	}

	viewer B(A);
	cout<<"Access data as viewer.\n";
	cout<<"0 for exit\n1 for display\n";
	while(cout<<"Enter command" && cin>>c && c!=0)
	{
		if(c==1)
			B.display();
		else
			cerr<<"Somthng wrong\n";
	}

	return 0;
}
