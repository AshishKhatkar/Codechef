/*
ID: ashish1610
PROG: LEBALONS
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
vector<int> v[45];
vector<ll> ar,ar1;
ll comb[45][45],ind;
ll compute_pow(ll a, ll b)
{
	ll x=1,y=a; 
	while(b>0)
	{
		if(b%2)
			x*=y;
		y*=y; 
		b/=2;
	}
	return x;
}
ll compute(ll n,ll r)
{
	if(n<0)
	{
		if(r!=0)
			return 0;
		else 
			return 1;
	}
	else if(r<0)
		return 0;
	if(comb[n][r]>=0)
		return comb[n][r];
	ll temp=0;
	if(n!=ind)
		temp=temp+(compute_pow(2,ar[n])-1)*compute(n-1,r-1);
	temp=temp+compute(n-1,r);
	comb[n][r]=temp;
	return comb[n][r];
}
int main()
{
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		memset(comb,-1,sizeof(comb));
		for(int i=0;i<45;++i)
			v[i].clear();
		ar.clear();
		ar1.clear();
		ll n,m;
		scanf("%lld %lld",&n,&m);
		ll c,p,cnt=0;
		for(ll i=0;i<n;++i)
		{
			scanf("%lld %lld",&c,&p);
			v[c].push_back(p);
		}
		for(ll i=1;i<=40;++i)
		{
			if(v[i].size())
			{
				ar.push_back(v[i].size());
				ar1.push_back(i);
				cnt++;
			}	
		}
		ll ans=0,sub_cnt=0;
		ind=-1;
		for(ll i=m;i<=cnt;++i)
			sub_cnt=sub_cnt+compute(ar.size()-1,i);
		for(ll i=0;i<ar.size();++i)
		{
			ll cmb1=0;
			memset(comb,-1,sizeof(comb));
			ind=i;
			for(ll j=m;j<=cnt;++j)
				cmb1=cmb1+compute(ar.size()-1,j-1);
			cmb1=cmb1*compute_pow(2,v[ar1[i]].size()-1);
			ll cnt1=0;
			for(ll j=0;j<v[ar1[i]].size();++j)
				cnt1=cnt1+v[ar1[i]][j];
			ans+=(cnt1*cmb1);
		}
		printf("%0.7lf\n",(ans*1.0)/sub_cnt);
	}
	return 0;
}
