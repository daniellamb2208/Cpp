#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

class Vector2D
{
	public:
		int getx();
		int gety();
		void setx(int a) {x=a;}
		void sety(int b) {y=b;}
		Vector2D() {}
		Vector2D(int,int);

		friend int operator *(Vector2D&, Vector2D&);
		friend ostream& operator <<(ostream&, Vector2D&);
	private:
		int x,y;
};

int operator *(Vector2D &a, Vector2D &b)
{
	return a.x*b.x+a.y*b.y;
}

ostream& operator <<(ostream &o, Vector2D &v)
{
	o<<"("<<v.x<<","<<v.y<<")";

	return o;
}

int Vector2D :: getx()
{
	return x;
}

int Vector2D :: gety()
{
	return y;
}

Vector2D :: Vector2D(int a, int b)
{
	x=a;
	y=b;
}
int main()
{
	srand(time(NULL));
	
	Vector2D test1(rand()%20, rand()%20);
	Vector2D test2(rand()%20, rand()%20);
	
	cout<<test1<<" * "<<test2<<" = "<<test1*test2<<endl;

	return 0;
}
