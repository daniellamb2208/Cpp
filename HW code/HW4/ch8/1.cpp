#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

class Money
{
	public:
		Money();
		Money(double amount);
		Money(int theDollars, int theCents);
		Money(int theDollars);
		double getAmount() const;
		int getDollars() const;
		int getCents() const;
		friend const Money operator +(const Money &amount1, const Money &amount2);
		friend const Money operator -(const Money &amount1, const Money &amount2);
		friend bool operator ==(const Money &amount1, const Money &amount2);
		friend const Money operator -(const Money &amount);
		friend ostream& operator <<(ostream &outputStream, const Money &amount);
		friend istream& operator >>(istream &inputStream, Money &amount);

		friend bool operator <(const Money &amount1, const Money &amount2);
		friend bool operator <=(const Money &amount1, const Money &amount2);
		friend bool operator >(const Money &amount1, const Money &amount2);
		friend bool operator >=(const Money &amount1, const Money &amount2);

		Money percent(double);
	private:
		int dollars, cents;
		int dollarsPart(double amount) const;
		int centsPart(double amount) const;
		int round(double amount) const;
};

Money Money :: percent(double p)
{
	p /= 100;
	return getAmount() * p ;
}

Money :: Money() : dollars(0), cents(0)
{/*empty*/}

Money :: Money(int theDollars, int theCents) : dollars(theDollars), cents(theCents)
{/*empty*/}

Money :: Money(int theDollars) : dollars(theDollars), cents(0)
{/*empty*/}

Money :: Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount))
{/*empty*/}

double Money :: getAmount() const			/////////
{
	return (dollars + (cents * 0.01));
}

int Money :: getDollars() const
{
	return dollars;
}

int Money :: getCents() const
{
	return cents;
}
int Money :: dollarsPart(double amount) const
{
	return static_cast<int>(amount);
}

int Money :: centsPart(double amount) const
{
	double doubleCents = amount * 100;
	int intCents = (round(fabs(doubleCents))) % 100;   //fabs (float abs)
	if(amount < 0)
		intCents = -intCents;
	return intCents;
}

int Money :: round(double amount) const
{
	return static_cast<int>(floor(amount + 0.5));
}

const Money operator +(const Money &amount1, const Money &amount2)
{
	return amount1.getAmount() + amount2.getAmount();
}
const Money operator -(const Money &amount1, const Money &amount2)
{
	return fabs(amount1.getAmount() - amount2.getAmount());
}
bool operator ==(const Money &amount1, const Money &amount2)
{
	if(amount1.getAmount() == amount2.getAmount())
		return true;
	else
		return false;
}
const Money operator -(const Money &amount)
{
	return (-( amount.getAmount() ));
}
ostream& operator <<(ostream &outputStream, const Money &amount)
{
	outputStream<<"$ ";

	outputStream<<amount.getAmount();

	return outputStream;
}
istream& operator >>(istream &inputStream, Money &amount)
{
	char dollarSign;
	inputStream>>dollarSign;
	if(dollarSign != '$')
	{
		cout<<"No dollar sign in Money input.\n";
		exit(EXIT_FAILURE);
	}
	
	double amountAsDouble;
	inputStream>>amountAsDouble;
	
	amount.dollars = amount.dollarsPart(amountAsDouble);
	amount.cents = amount.centsPart(amountAsDouble);

	return inputStream;
}

bool operator <(const Money &amount1, const Money &amount2)
{
	if(amount1.getAmount() < amount2.getAmount())
		return true;
	else
		return false;
}
bool operator <=(const Money &amount1, const Money &amount2)
{	
	if(amount1.getAmount() == amount2.getAmount())
		return true;
	else if(amount1.getAmount() < amount2.getAmount())
		return true;
	else
		return false;
}
bool operator >(const Money &amount1, const Money &amount2)
{
	if(amount1.getAmount() > amount2.getAmount())
		return true;
	else
		return false;
}
bool operator >=(const Money &amount1, const Money &amount2)
{	
	if(amount1.getAmount() == amount2.getAmount())
		return true;
	else if(amount1.getAmount() > amount2.getAmount())
		return true;
	else
		return false;
}


int main()
{
	Money yours;
	double tp;
 	cout<<"How much do you have :";
	cin>>yours;
	cout<<"How many percents would you like to take :";
	cin>>tp;

	Money my(10, 9);

	cout<<"\nYou have "<<yours<<endl;
	cout<<"I have "<<my<<endl;
	cout<<tp<<"% of your money : "<<yours.percent(tp)<<endl;
	cout<<"15% of my money :   "<<my.percent(15)<<endl;
	cout<<"\n";
	if(yours == my)
		cout<<"We have the same amount of money\n";
	else
		cout<<"One of us is richer\n";

	cout<<yours<<" + "<<my<<" equals "<<yours+my<<endl;
	cout<<yours<<" - "<<my<<" equals "<<yours-my<<endl;
	
	cout<<"\n";

	cout<<"You have "<<yours<<endl;
	cout<<"I have "<<my<<endl;

	if(yours>=my)		// >=
		cout<<"Your money is more than or equal to my.\n";
	else
		cout<<"You money is not more than me.\n";

	if(yours<=my)		// <=
		cout<<"My money is more than or equal to yours.\n";
	else
		cout<<"My money is not more than yours.\n";

	if(yours+my > yours-my) 	// >
		cout<<"The sum of our money is more than the difference.\n";
	else if(yours+my < yours-my)	// <
		cout<<"The sum of our money is less than the difference.\n";
	else if(yours+my == yours-my)
		cout<<"The sum of our money is equal to the difference .\n";

	return 0;
}
