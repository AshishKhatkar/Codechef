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
int ar[15][15];
bool visited[1 << 15][145][15];
bool res = false;
void dfs(int nd, int st, int mask, int l, int n)
{
	visited[mask][l][nd] = true;
	bool done = true;
	for(int i = 0; i < n; ++i)
	{
		if(l - ar[nd][i] >= 0 && !(mask & (1 << i)))
		{
			if(!visited[mask + (1 << i)][l - ar[nd][i]][i])
			{
				done = false;
				dfs(i, st, mask + (1 << i), l - ar[nd][i], n);
			}
		}
	}
	if(done)
	{
		if(l == ar[nd][st])
			res = true;
	}
}
int main()
{
	int n, l;
	si(n);
	si(l);
	int i, j;
	rep(i, 0, n - 1)
		rep(j, 0, n - 1)
			si(ar[i][j]);
	if(l > n * 10)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	rep(i, 0, n - 1)
	{
		memset(visited, false, sizeof(visited));
		dfs(i, i, (1 << i), l, n);
		if(res)
			break;
	}
	if(res)
		printf("POSSIBLE\n");
	else
		printf("IMPOSSIBLE\n");
	return 0;
}