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
ll tree[4 * 100005][2], ar[100005];
void build_tree(int node, int lft, int rgt)
{
	if(lft == rgt)
	{
		tree[node][0] = ar[lft] * ar[lft];
		tree[node][1] = ar[lft];
		return;
	}
	int mid = (lft + rgt) >> 1;
	build_tree(2 * node, lft, mid);
	build_tree(2 * node + 1, mid + 1, rgt);
	tree[node][0] = tree[2 * node][0] + tree[2 * node + 1][0] + tree[2 * node][1] * tree[2 * node + 1][1];
	tree[node][1] = tree[2 * node][1] + tree[2 * node + 1][1];
}
pll query_tree(int node, int lft, int rgt, int l, int r)
{
	// cout<<lft<<" "<<rgt<<endl;
	if(lft > rgt || lft > r || rgt < l)
		return mp(-1, -1);
	if(lft >= l && rgt <= r)
		return mp(tree[node][0], tree[node][1]);
	int mid = (lft + rgt) >> 1;
	pll p1 = query_tree(2 * node, lft, mid, l, r);
	pll p2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	if(p1.first == -1)
		return p2;
	else if(p2.first == -1)
	{
		// cout<<"here1\n";
		return p1;
	}
	else
		return mp(p1.first + p2.first + p1.second * p2.second, p1.second + p2.second);
}
int main()
{
	int n, m, i, l, r;
	si(n);
	rep(i, 0, n - 1)
		sl(ar[i]);
	build_tree(1, 0, n - 1);
	// rep(i, 1, 9)
	// 	cout<<tree[i][0]<<" "<<tree[i][1]<<endl;
	si(m);
	while(m--)
	{
		si(l);
		si(r);
		pl(query_tree(1, 0, n - 1, l, r).first);
		pn;
	}
	return 0;
}