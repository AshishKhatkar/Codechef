/*
ID: ashish1610
PROG: Guessing Game
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
ll gcd(ll a, ll b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n,m;
		scanf("%lld %lld",&n,&m);
		ll odd_n=n/2;
		if(n%2)
			odd_n++;
		ll even_n=n/2;
		ll odd_m=m/2;
		if(m%2)
			odd_m++;
		ll even_m=m/2;
		ll ans=odd_n*even_m+odd_m*even_n;
		ll fac=gcd(ans,n*m);
		printf("%lld/%lld\n",ans/fac,n*m/fac);
	}
	return 0;
}
