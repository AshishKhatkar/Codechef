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
struct seg_node
{
	ll gcd_val, maxx;
};
seg_node tree[4 * 100005];
ll ar[100005];
void build_tree(int node, int lft, int rgt)
{
	if(lft > rgt)
		return;
	if(lft == rgt)
	{
		tree[node].gcd_val = ar[lft];
		tree[node].maxx = ar[lft];
		return;
	}
	int mid = (lft + rgt) >> 1;
	build_tree(2 * node, lft, mid);
	build_tree(2 * node + 1, mid + 1, rgt);
	tree[node].gcd_val = __gcd(tree[2 * node].gcd_val, tree[2 * node + 1].gcd_val);
	tree[node].maxx = max(tree[2 * node].maxx, tree[2 * node + 1].maxx);
}
seg_node query_tree(int node, int lft, int rgt, int l, int r)
{
	if(lft > rgt || lft > r || rgt < l)
	{
		seg_node nd;
		nd.gcd_val = 0;
		nd.maxx = INT_MIN;
		return nd;
	}
	if(lft >= l && rgt <= r)
		return tree[node];
	int mid = (lft + rgt) >> 1;
	seg_node ans1 = query_tree(2 * node, lft, mid, l, r);
	seg_node ans2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	if(ans1.maxx == INT_MIN)
		return ans2;
	else if(ans2.maxx == INT_MIN)
		return ans1;
	seg_node ans;
	ans.gcd_val = __gcd(ans1.gcd_val, ans2.gcd_val);
	ans.maxx = max(ans1.maxx, ans2.maxx);
	return ans;
}
int main()
{
	int n, q;
	scanf("%d %d", &n, &q);
	assert(n >= 1 && n <= 100000);
	assert(q >= 1 && q <= 100000);
	for(int i=0; i<n; ++i)
	{
		scanf("%lld", &ar[i]);
		assert(ar[i] >= 1LL && ar[i] <= 1000000000LL);
	}
	build_tree(1, 0, n - 1);
	while(q--)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		assert(y >= 1 && y <= n);
		assert(x >= 1 && x <= y);
		seg_node res = query_tree(1, 0, n - 1, x -1, y - 1);
		printf("%lld %lld\n",res.maxx, res.gcd_val);
	}
	return 0;
}