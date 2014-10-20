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
		ll a,b,p;
		cin>>a>>b>>p;
		ll ans=0;
		for(ll i=1;i<p;++i)
		{
			if((i*i*i)%p==1)
				ans=(ans+(p+b-i)/p-(p+a-1-i)/p);
		}
		cout<<ans<<endl;
	}
	return 0;
}
