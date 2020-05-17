#include<iostream>
#include<string>
using namespace std;

class Payment
{
	private:
		float pay;
	public:
		inline Payment() {}
		inline Payment(float p) : pay(p) {}
		inline float get() { return pay; }
		inline void paymentDetail() { cout<<"Total payment amount: "<<get()<<endl; }
};

class Cashpayment : public Payment
{
	public:
		inline Cashpayment(float p) : Payment(p) {}
		inline void paymentDetail() { cout<<"Payment with Cash: "<<get()<<endl; }
};

class CreditCardPayment : public Payment
{
	public:
		inline CreditCardPayment(string n1,string e,string n2,float p) : Payment(p), name(n1), expiration(e), number(n2) {}
		inline void paymentDetail() 
		{
			cout<<"Payment with credit card: "<<get()<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Expiration date: "<<expiration<<endl;
			cout<<"Credit card number: "<<number<<endl;
		}
	private:
		string name;
		string expiration;
		string number;
};

int main()
{
	Cashpayment A(50.2), B(20.45);
	cout<<"Cash 1 details:\n";
	A.paymentDetail();
	cout<<"\nCash 2 details:\n";
	B.paymentDetail();

	CreditCardPayment C("Fred","10/5/2010","123456789",10.5), D("Barney","11/15/2009","987645312",100);
	cout<<"\nCredit card 1 details:\n";
	C.paymentDetail();
	cout<<"\nCredit card 2 details:\n";
	D.paymentDetail();

	return 0;
}
