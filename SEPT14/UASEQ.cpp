/*
ID: ashish1610
PROG: Chef and Sequence
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*	fast input	*/
inline void inp(ll &n) 
{
    	n=0;
	register ll ch=getchar_unlocked();
	ll sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
bool compare(pair<ll,ll> p1, pair<ll,ll> p2)
{
	if(p1.second!=p2.second)
		return p1.second<p2.second;
	return p1.first<p2.first;
}
int main()
{
	ll n,k,diff,st_term,ind;
	inp(n);
	inp(k);
	ll ar[n];
	vector<pair<ll,ll> > v;
	for(int i=0;i<n;++i)
	{
		inp(ar[i]);
		if(i!=0)
		{
			diff=ar[i]-ar[i-1];
			st_term=ar[i]-i*diff;
		}
		ind=-1;
		for(int k=0;k<v.size();++k)
		{
			if(v[k].first==diff)
			{
				ind=k;
				break;
			}
		}
		if(ind!=-1)
			v[ind]=make_pair(diff,st_term);
		else
			v.push_back(make_pair(diff,st_term));
	}
	sort(v.begin(),v.end(),compare);
	int sz=v.size(),cnt;
	ll ans;
	bool flag;
	for(int i=0;i<sz;++i)
	{
		cnt=0;
		ans=v[i].second;
		flag=true;
		for(int j=0;j<n;++j)
		{
			if(ar[j]!=ans)
				cnt++;
			if(cnt>k)
			{
				flag=false;
				break;
			}
			ans+=v[i].first;
		}
		if(flag)
		{
			ans=v[i].second;
			for(int j=0;j<n;++j)
			{
				printf("%lld",ans);
				if(j!=n-1)
					printf(" ");
				else
					printf("\n");
				ans+=v[i].first;
			}
			break;
		}
	}
	return 0;
}
