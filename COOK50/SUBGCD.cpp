/*
ID: ashish1610
PROG: 
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
#define sl(i)	scanf("%lld",&i)
#define pl(i)	printf("%lld\n",i)
int main()
{
	ll t;
	sl(t);
	while(t--)
	{
		ll n,tmp;
		sl(n);
		ll gcd_val=0;
		for(int i=0;i<n;++i)
		{
			sl(tmp);
			gcd_val=__gcd(gcd_val,tmp);
		}
		if(gcd_val==1)
			pl(n);
		else
			pl(-1LL);
	}
	return 0;
}
