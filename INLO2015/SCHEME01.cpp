/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<ll>
#define	pii				pair<int,int>
#define pil				pair<int, ll>
#define pll				pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD				1000000007
#define rep(i, a, b)	for(i=a; i<=b; ++i)
#define rrep(i, a, b)	for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 				printf("\n")
ll pow_mod(ll a, ll b)
{
	ll res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
ll val[1005];
vector<vector<pair<ll,int> > >G(1005);
ll Dijkstra(int s, int n)
{
	vector<ll> D(1005, LONG_LONG_MAX);
    set<pli> Q;
    D[s] = 0;
    Q.insert(mp(0,s));
    while(!Q.empty())
    {
        pli top = *Q.begin();
        Q.erase(Q.begin());
        int v = top.second;
        int d = top.first;
 
        for (vector<pli>::const_iterator it = G[v].begin(); it != G[v].end(); it++)
        {
            int v2 = it->second;
            int cost = it->first;
            if(cost > val[v2])
            {
            	if(D[v2] > D[v] + cost - val[v2])
            	{
            		if (D[v2] != LONG_LONG_MAX)
	                {
	                    Q.erase(Q.find(mp(D[v2], v2)));
	                }
	                D[v2] = D[v] + cost - val[v2];
	                Q.insert(mp(D[v2], v2));
            	}
            }
            else
            {
	            if (D[v2] > D[v] + cost)
	            {
	                if (D[v2] != LONG_LONG_MAX)
	                {
	                    Q.erase(Q.find(mp(D[v2], v2)));
	                }
	                D[v2] = D[v] + cost;
	                Q.insert(mp(D[v2], v2));
	            }
	        }
        }
    }
    return D[n];
}
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n, m;
		si(n);
		si(m);
		int i, j;
		int x, y;
		ll c;
		rep(i, 0, 1004)
			G[i].clear();
		rep(i, 1, m)
		{
			si(x);
			si(y);
			sl(c);
			pb(G[x - 1], mp(c, y - 1));
		}
		rep(i, 0, n - 1)
			sl(val[i]);
		int src, dest;
		si(src);
		si(dest);
		ll ans = Dijkstra(src - 1, dest - 1);
		if(ans == LONG_LONG_MAX)
			printf("-1\n");
		else
		{
			pl(ans * 10LL);
			pn;
		}
	}
	return 0;
}