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
		int n;
		cin>>n;
		ll ar[(1<<n)+5];
		for(int i=0;i<(1<<n);++i)
			cin>>ar[i];
		if(n==1)
		{
			cout<<max(ar[0],ar[1])<<endl;
			continue;
		}
		sort(ar,ar+(1<<n));
		int res[n+5];
		res[0]=ar[1],res[1]=ar[2];
		priority_queue<ll,vector<ll>, greater<ll> > q;
		int cnt=2,ind=3;
		q.push(res[0]+res[1]);
		while(cnt<n)
		{
			if(!q.empty())
			{
				ll val=q.top();
				cout<<q.top();
				if(val==ar[ind])
				{
					q.pop();
					ind++;
					continue;
				}
			}
			res[cnt]=ar[ind];
			for(int i=1;i<(1<<cnt);++i)
			{
				ll sum=0;
				int tmp=i,ind1=0;
				while(tmp>0)
				{
					if(tmp&1)
						sum+=res[ind1];
					tmp>>=1;
					ind1++;
				}
				q.push(sum+ar[ind]);
			}
			cnt++;
			ind++;
		}
		sort(res,res+n);
		for(int i=0;i<n;++i)
			cout<<res[i]<<" ";
		cout<<endl;
	}
	return 0;
}
