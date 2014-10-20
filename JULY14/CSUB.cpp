/*
ID: ashish1610
PROG: Count Substrings
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		string str;
		cin>>str;
		ll cnt=0;
		for(int i=0;i<n;++i)
		{
			if(str[i]=='1')
				cnt++;
		}
		printf("%lld\n",(cnt*(cnt+1))/2);
	}
	return 0;
}
