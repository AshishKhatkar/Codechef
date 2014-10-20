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
		int n,m;
		cin>>n>>m;
		int ar[n];
		int cnt=m;
		for(int i=0;i<n;++i)
		{
			cin>>ar[i];
			cnt+=ar[i];
		}
		bool flag=true;
		for(int i=0;i<n;++i)
		{
			if(ar[i]>(cnt/n))
			{
				flag=false;
				break;
			}
		}
		if(flag && cnt%n==0)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
} 
