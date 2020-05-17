#include <string>
#include <iostream>
using namespace std;

/*
// --------------------------------
// ----- ENTER YOUR CODE HERE -----
// --------------------------------*/

class  DynamicStringArray
{
	private:
		string* dynamicArray;
		int size;
	public:
		DynamicStringArray();
		~DynamicStringArray();
		int getSize();
		void addEntry(string);
		void deleteEntry(string);
		string getEntry(int);
		string gs(int i) const {return dynamicArray[i];}
		
		DynamicStringArray& operator=(const DynamicStringArray&);
		
};

int DynamicStringArray :: getSize()
{
	return size;
}

DynamicStringArray& DynamicStringArray :: operator=(const DynamicStringArray& d)
{
	this->size = d.size;
	this->dynamicArray = new string[this->size];

	for(int i=0;i<this->size;i++)
		dynamicArray[i] = d.gs(i);

	return *this;
}

DynamicStringArray :: DynamicStringArray()
{
	dynamicArray = NULL;
	size = 0;
}

DynamicStringArray :: ~DynamicStringArray()
{
	delete[] dynamicArray;
	size = 0;
}

void DynamicStringArray :: addEntry(string a)
{
	if(size == 0)
	{
		delete[] dynamicArray;
		size = 1;
		dynamicArray = new string[size];
		dynamicArray[0] = a;
		
	}
	else
	{
		size++;		//increment
		string newarray[size];
		for(int i=0;i<size-1;i++)
			newarray[i] = dynamicArray[i];
		newarray[size-1] = a;	

		delete[] dynamicArray;	

		dynamicArray = new string[size];
	
		for(int i=0;i<size;i++)
			 dynamicArray[i] = newarray[i];
	}
}

void DynamicStringArray :: deleteEntry(string d)
{
	bool c = false;
	int index = -1;

	if(size == 0)
		cerr<<"Empty\n";		
	else
	{
		for(int i=0;i<size;i++)
		{
			if(dynamicArray[i] == d)
			{
				index = i;			
				c=true;
			}		
		}
		if(!c)
			cerr<<"Not found\n";
		else
		{	
			if(size == 1)
			{
//				cout<<"Deleted all";
				delete[] dynamicArray;
				dynamicArray = NULL;
				size = 0; 
			}
			else
			{			
				size--;		//decrement
				string* s = new string[size];
	
				/*int i = 0;
				for(i=0;i<size;i++)
				{
					if(d == dynamicArray[i])
						break;
					s[i] = dynamicArray[i];
				}
				while(i<size)
					s[i] = dynamicArray[i+1];*/

				for(int i=0;i<index;i++)
					s[i] = dynamicArray[i];
				for(int i=index;i<size;i++)
					s[i] = dynamicArray[i+1];
	
				delete[] dynamicArray;
	
				dynamicArray = new string[size];

				for(int i=0;i<size;i++)
					dynamicArray[i] = s[i];
			}
		}
	}
}

string DynamicStringArray :: getEntry(int i)
{
	if(i>size)
		return NULL;
	return dynamicArray[i];
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
	DynamicStringArray names;

	// List of names
	names.addEntry("Allen");
	names.addEntry("Bob");
	names.addEntry("Ciro");
	names.addEntry("David");
	names.addEntry("Eddie");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Add and remove some names
  names.addEntry("Frank");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Bob");
  cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.deleteEntry("Garfield");
  cout << "After removing a name that isn't on the list (Garfield):" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Hamlet");
  cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  // Remove all of the names by repeatedly deleting the last one
  while (names.getSize() > 0) {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
  }

  cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

  names.addEntry("Isaac");
  cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getSize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Isaac from names
	names.deleteEntry("Isaac");
  	cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getSize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Isaac from names2
	names2.deleteEntry("Isaac");
     	cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getSize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;
}
