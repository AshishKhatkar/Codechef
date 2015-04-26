/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll				long long int
#define vi				vector<int>
#define vl				vector<int>
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
int pow_mod(int a, int b)
{
	int res = 1;
	while(b)
	{
		if(b & 1)
			res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}
int tree[4 * 10005], lazy[4 * 10005];
void update_tree(int node, int lft, int rgt, int l, int r, int val)
{
	if(lazy[node] != 0)
	{
		tree[node] += (rgt - lft + 1) * lazy[node];
		if(lft != rgt)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(l > rgt || lft > r)
		return;
	if(lft >= l && rgt <= r)
	{
		tree[node] += (rgt - lft + 1) * val;
		if(lft != rgt)
		{
			lazy[2 * node] += val;
			lazy[2 * node + 1] += val;
		}
		return;
	}
	int mid = (lft + rgt) >> 1;
	update_tree(2 * node, lft, mid, l, r, val);
	update_tree(2 * node + 1, mid + 1, rgt, l, r, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
int query_tree(int node, int lft, int rgt, int l, int r)
{
	if(lft > rgt || lft > r || rgt < l)
		return 0;
	if(lazy[node] != 0)
	{
		tree[node] += (rgt - lft + 1) * lazy[node];
		if(lft != rgt)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if(lft >= l && rgt <= r)
		return tree[node];
	int mid = (lft + rgt) >> 1;
	int p1, p2;
	p1 = query_tree(2 * node, lft, mid, l, r);
	p2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	return p1 + p2;
}
int main()
{
	int t, i, j, q, n, u, l, r, val;
	si(t);
	rep(i, 1, t)
	{
		memset(tree, 0, sizeof(tree));
		memset(lazy, 0, sizeof(lazy));
		si(n);
		si(u);
		rep(j, 1, u)
		{
			si(l);
			si(r);
			si(val);
			update_tree(1, 0, n - 1, l, r, val);
		}
		si(q);
		while(q--)
		{
			si(l);
			int res = query_tree(1, 0, n - 1, l, l);
			pi(res);
			pn;
		}
	}
	return 0;
} 