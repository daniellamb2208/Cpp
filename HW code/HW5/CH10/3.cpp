#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	char *head, *tail, sentence[81];		// 1 for \0

	head = NULL;
	tail = NULL;

	cout<<"Enter the string with length less than 80 characters\n";
	cin.getline(sentence,81);

	int len = strlen(sentence);
	head = &sentence[0];
	tail = &sentence[len-1];

	int count = 0;
	while(head < tail)
	{
		if(*head == ' ')
			count ++;
		if(*tail == ' ')
			count ++;
	
		char tmp = *head;
		*head = *tail;
		*tail = tmp;

		head ++;
		tail --;
	}

	cout<<"Reversed string: "<<sentence<<endl;
	cout<<"The number of words is: "<<count<<endl;

	return 0;
}
