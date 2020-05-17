#include<iostream>
#include<string>
using namespace std;
int main(void)
{
	char ch[50], vowel[5]={'a','e','i','o','u'};
	int t[5]={0};

	cout<<"Please input the string : ";
	cin.getline(ch,50);
	
	int i=0, j;

	while(ch[i] != '\0')
		i++;	
	
	for(j=0;j<i;j++)
	{
		switch(ch[j])
		{
			case 'a':
				t[0]++;
				break;
			case 'e':
				t[1]++;
				break;
			case 'i':
				t[2]++;
				break;
			case 'o':
				t[3]++;
				break;
			case 'u':
				t[4]++;
				break;
		}
	}

	cout<<"Vowel\tCount"<<endl;	

	for(j=0;j<5;j++)
		cout<<vowel[j]<<"\t"<<t[j]<<endl;
	return 0;
}
