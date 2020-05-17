#include"pizza.cpp"
#include<vector>
#include<string>
using namespace std;

class Order
{
	public:
		void initial();

		void add();
		void computeall();
		void output_order_price();
		void set_default(Pizza);
	private:
		vector<Pizza> m;
		double total;
};
void Order :: initial()
{
	total =0;
}
void Order :: add()
{
	Pizza a;

	string size,type;
	int size_int,type_int,ppt,cst;
	cout<<"\n";
	cout<<"Pizza size (small,medium,large): ";
	cin>>size;
	cout<<"Pizza type (deepfish,handtossed,pan): ";
	cin>>type;
	cout<<"Pizza pepperonitoppings: ";
	cin>>ppt;
	cout<<"Pizza cheesetoppings: ";
	cin>>cst;

	if(size == "small")
		size_int = 0;
	else if(size == "medium")
		size_int = 1;
	else if(size == "large")
		size_int = 2;

	if(type == "deepfish")
		type_int = 0;
	else if(type == "handtossed")
		type_int = 1;
	else if(type == "pan")
		type_int = 2;

	a.setSize(size_int);
	a.setType(type_int);
	a.setPepperoniToppings(ppt);
	a.setCheeseToppings(cst);

	m.push_back(a);
}

void Order :: computeall()
{
	double sum = 0;
	for(int i=0;i<m.size();i++)
		sum += m[i].computePrice();
	total = sum;
}

void Order :: output_order_price()
{
	cout<<"\n";
	for(int i=0;i<m.size();i++)
		m[i].outputDescription();

	cout<<"The total price is $ "<<total;
	cout<<endl;
}

void Order :: set_default(Pizza a)
{
	m.push_back(a);
}
void _user_input()
{
	cout<<"'Stop' to check your order,'Order' for add more pizza.\n";
	cout<<"Pizza size and type should enter exactly every alphabet correct to order,Thanks!\n"<<endl;
	Order user_input;
	user_input.initial();	
	string willadd;
	
	cout<<endl;
	while(cout<<"'Stop' / 'Order': "&&cin>>willadd && willadd == "Order")
	{
		user_input.add();
		user_input.computeall();
		user_input.output_order_price();
	}

	cout<<"\nYour final order here: \n";
	user_input.output_order_price();
	cout<<"Thank you very much.\n";
}
void _default()
{
	Order defaultpizza;

	Pizza f(SMALL,HANDTOSSED,0,3),s(LARGE,PAN,2,1);
	defaultpizza.set_default(f);
	defaultpizza.set_default(s);

	defaultpizza.computeall();
	defaultpizza.output_order_price();
	
}
int main()
{
	_default();      //given default testing data 

	cout<<"\n";

	_user_input();	 //data which user input
	
	return 0;
}

