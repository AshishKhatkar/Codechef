/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int len=str.length();
		int ind1=0,ind2=len-1;
		while(ind1<=ind2)
		{
			if(str[ind1]!=str[ind2])
				break;
			ind1++;
			ind2--;
		}
		if(ind1>ind2)
		{
			cout<<"YES\n";
			continue;
		}
		bool flag1;
		int ind3=ind1+1,ind4=ind2;
		while(ind3<=ind4)
		{
			if(str[ind3]!=str[ind4])
				break;
			ind3++;
			ind4--;
		}
		if(ind3>ind4)
		{
			cout<<"YES\n";
			continue;
		}
		ind3=ind1,ind4=ind2-1;
		while(ind3<=ind4)
		{
			if(str[ind3]!=str[ind4])
				break;
			ind3++;
			ind4--;
		}
		if(ind3>ind4)
		{
			cout<<"YES\n";
			continue;
		}
		cout<<"NO\n";
	}
	return 0;
}