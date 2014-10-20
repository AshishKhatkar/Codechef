/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	string str;
	cin>>t;
	getchar();
	while(getline(cin,str))
	{
		int temp;
		for(int i=0;i<str.length();++i)
		{
			if(str[i]>='a' && str[i]<='z')
			{
				temp=str[i]-'a'+18;
				if(temp%26>=0 && temp%26<=9)
					cout<<(temp%26);
				else
				{
					char ch='a'+(temp%36);
					cout<<ch;
				}
			}
			else if(str[i]>='0' && str[i]<='9')
			{
				temp=str[i]-'0';
				char ch='i'+temp;	
				cout<<ch;
			}
			else
				cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}
