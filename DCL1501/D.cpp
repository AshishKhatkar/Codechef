/*
ID: ashish1610
PROG:
LANG: C++
Matching code taken from : https://sites.google.com/site/indy256/algo_cpp/hopcroft_karp
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
const int MAXN1 = 10005;
const int MAXN2 = 10005;
const int MAXM = 20005;
int n1, n2, edges, last[MAXN1], prev[MAXM], head[MAXM];
int matching[MAXN2], dist[MAXN1], Q[MAXN1];
bool used[MAXN1], vis[MAXN1];
void init(int _n1, int _n2) 
{
    n1 = _n1;
    n2 = _n2;
    edges = 0;
    fill(last, last + n1, -1);
}
void addEdge(int u, int v) 
{
    head[edges] = v;
    prev[edges] = last[u];
    last[u] = edges++;
}
void bfs() 
{
    fill(dist, dist + n1, -1);
    int sizeQ = 0;
    for (int u = 0; u < n1; ++u) 
    {
        if (!used[u]) 
        {
            Q[sizeQ++] = u;
            dist[u] = 0;
        }
    }
    for (int i = 0; i < sizeQ; i++) 
    {
        int u1 = Q[i];
        for (int e = last[u1]; e >= 0; e = prev[e]) 
        {
            int u2 = matching[head[e]];
            if (u2 >= 0 && dist[u2] < 0) 
            {
                dist[u2] = dist[u1] + 1;
                Q[sizeQ++] = u2;
            }
        }
    }
}
bool dfs(int u1) 
{
    vis[u1] = true;
    for (int e = last[u1]; e >= 0; e = prev[e]) 
    {
        int v = head[e];
        int u2 = matching[v];
        if (u2 < 0 || !vis[u2] && dist[u2] == dist[u1] + 1 && dfs(u2)) 
        {
            matching[v] = u1;
            used[u1] = true;
            return true;
        }
    }
    return false;
}
int maxMatching() 
{
    fill(used, used + n1, false);
    fill(matching, matching + n2, -1);
    for (int res = 0;;) 
    {
        bfs();
        fill(vis, vis + n1, false);
        int f = 0;
        for (int u = 0; u < n1; ++u)
            if (!used[u] && dfs(u))
                ++f;
        if (!f)
            return res;
        res += f;
    }
}
int main() 
{
	int n, d;
	si(n);
	si(d);
    init(n, n);
    int src, dest, i;
    rep(i, 0, d - 1)
    {
    	si(src);
    	si(dest);
    	addEdge(src, dest);
    }
    if(maxMatching() == n)
    	printf("YES\n");
    else
    	printf("NO\n");
    return 0;
}