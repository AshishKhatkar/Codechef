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
pll p[1005];
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
    return D[n + 1];
}
int main()
{
	int n, x1, y1;
	cin>>n>>x1>>y1;
	int i, j;
	rep(i, 1, n)
		cin>>p[i].first>>p[i].second;
	rep(i, 1, n)
	{
		pb(G[0], mp((p[i].first * p[i].first + p[i].second * p[i].second), i));
		pb(G[i], mp((p[i].first * p[i].first + p[i].second * p[i].second), 0));
	}
	pb(G[0], mp(x1 * x1 + y1 * y1, n + 1));
	pb(G[n + 1], mp(x1 * x1 + y1 * y1, 0));
	rep(i, 1, n)
	{
		rep(j, i + 1, n)
		{
			pb(G[i], mp((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second), j));
			pb(G[j], mp((p[i].first - p[j].first) * (p[i].first - p[j].first) + (p[i].second - p[j].second) * (p[i].second - p[j].second), i));
		}
	}
	rep(i, 1, n)
	{
		pb(G[i], mp((p[i].first - x1) * (p[i].first - x1) + (p[i].second - y1) * (p[i].second - y1), n + 1));
		pb(G[n + 1], mp((p[i].first - x1) * (p[i].first - x1) + (p[i].second - y1) * (p[i].second - y1), i));
	}
	ll ans = Dijkstra(0, n);
	cout<<ans<<endl;
	return 0;
}