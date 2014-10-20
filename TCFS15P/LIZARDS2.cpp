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
		ll n;
		cin>>n;
		ll ans=(n*(n-1));
		ll den=8;
		cout<<(ans/(__gcd(ans,den)))<<"/"<<(den/(__gcd(ans,den)))<<endl;
	}
	return 0;
}
