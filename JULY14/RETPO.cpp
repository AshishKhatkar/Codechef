/*
ID: ashish1610
PROG: Reach The Point
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
		ll x,y;
		scanf("%lld %lld",&x,&y);
		x=abs(x);
		y=abs(y);
		ll mx=max(x,y);
		if((x%2==0 && y%2==0)||(x%2 && y%2))
			printf("%lld\n",2*mx);
		else if(x>y)
			printf("%lld\n",2*mx+1);
		else
			printf("%lld\n",2*mx-1);
	}
	return 0;
}
