/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define ld	long double
#define MOD	1000000007
void solve_subtask1_subtask2_subtask3(ll x, ll k)
{
	ll val=0;
	ll tmp=k;
	while(tmp!=1)
	{
		val++;
		tmp>>=1;
	}
	ll segments=(1LL<<(val+1));
	assert(k>=(1LL<<val) && k<=(1LL<<(val+1)));
	double ans=(x*1.0)/segments;
	segments>>=1;
	segments=k-segments;
	ans=ans+segments*2*ans;
	printf("%.10lf\n",ans);
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll x,k;
		cin>>x>>k;
		solve_subtask1_subtask2_subtask3(x,k);
	}
	return 0;
}