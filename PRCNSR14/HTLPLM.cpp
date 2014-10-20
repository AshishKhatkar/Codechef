/*
ID: ashish1610
PROG: Helping Sugam
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
		int n,q;
		scanf("%d %d",&n,&q);
		pair<ll,ll> p[n];
		for(int i=0;i<n;++i)
			scanf("%lld %lld",&p[i].first,&p[i].second);
		while(q--)
		{
			ll val;
			scanf("%lld",&val);
			bool flag=false;
			for(int i=0;i<n;++i)
			{
				if(p[i].first<=val && p[i].second>=val)
				{
					flag=true;
					break;
				}
			}
			if(flag)
				printf("NO\n");
			else
				printf("YES\n");
		}
	}
	return 0;
}
