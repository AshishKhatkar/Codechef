/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
vector<pair<ll,char> > v;
//map<ll,char> mp;
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		v.clear();
		//mp.clear();
		ll n,m,ind;
		char col;
		cin>>n>>m;
		while(m--)
		{
			cin>>col>>ind;
			v.push_back(make_pair(ind,col));
			//mp[ind]=col;
		}
		sort(v.begin(),v.end());
		ll ans=1;
		for(int i=1;i<v.size();++i)
		{
			if(v[i].second!=v[i-1].second)
				ans=(ans*(v[i].first-v[i-1].first))%(MOD+2);
		}
		/*ll ind1=1;
		while(!mp[ind1])
			ind1++;
		for(ll i=ind1+1;i<=n;++i)
		{
			if(mp[i])
			{
				//cout<<i<<" "<<mp[i]<<" "<<ind1<<endl;
				if((mp[i]!=mp[ind1]))
					ans=(ans*(i-ind1))%(MOD+2);
				ind1=i;
			}
		}*/
		cout<<ans<<endl;
	}
	return 0;
} 
