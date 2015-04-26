/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD 1000000007
#define maxn 10005
vector<int> prod[105];
vector<int> adj[10005];
int T[maxn], P[20][maxn], L[maxn], visited[maxn];
int lca(int p, int q)
{
	int lg, i;
	if (L[p] < L[q]) 
		swap(p,q);
	for(lg = 1; (1 << lg) <= L[p]; ++lg);
		lg--;
	for(i = lg; i >= 0; --i)
		if (L[p] - (1 << i) >= L[q])
			p = P[i][p];
	if (p == q) 
		return p;
	for (i = lg; i >= 0; i--)
		if (P[i][p] != -1 && P[i][p] != P[i][q]) 
			p = P[i][p], q = P[i][q];
	return T[p];
}
void bfs(int s)
{
	queue<int> Q;
	Q.push(s);
	L[s]=0;
	visited[s]=1;
   	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0;i<adj[u].size();i++)
		{
			int v=adj[u][i];
			if(visited[v]) 
				continue;
			L[v]=L[u]+1;
			visited[v]=1;
			Q.push(v);
			T[v]=u;
			P[0][v]=u;
		}
	}
}
int lca_rooted_k(int u, int v, int r)
{
	int uv = lca(u, v);
	int ru = lca(u, r);
	int rv = lca(v, r);
	int ruv = lca(r, uv);
	if(ruv != uv)
		return uv;
	if(ru == uv && rv == uv)
		return uv;
	if(rv == uv)
		return ru;
	if(ru == uv)
		return rv;
}
void solve_subtask1_subtask2(int n, int k, int b)
{
	memset(P, -1, sizeof(P));
	bfs(1);
	for(int j=1; (1<<j)<=n; ++j)
		for(int i=1; i<=n; ++i)
			if(P[j-1][i] != -1)
				P[j][i] = P[j-1][P[j-1][i]];
	int q, x, y;
	cin>>q;
	while(q--)
	{
		cin>>x>>y;
		int maxdis = -1, ans = -1;
		for(int i=0; i<prod[y].size(); ++i)
		{
			int lc = lca_rooted_k(x, prod[y][i], b);
			int val = lca(lc, b);
			lc = L[lc] + L[b] - 2 * L[val];
			if(lc == maxdis)
				ans = min(ans, prod[y][i]);
			else if(lc > maxdis)
			{
				ans = prod[y][i];
				maxdis = lc;
			}
		}
		cout<<ans<<endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n, k, b, x, y;
	cin>>n>>k>>b;
	for(int i=0; i<n-1; ++i)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=1; i<=n; ++i)
	{
		cin>>x;
		prod[x].push_back(i);
	}
	solve_subtask1_subtask2(n, k, b);
	return 0;
}