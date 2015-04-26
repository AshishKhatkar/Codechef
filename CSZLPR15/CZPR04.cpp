/*
ID: ashish1610
PROG:
LANG: C++
Same as one on HackerEarth
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
int tree[4 * 100005][2], ar[100005];
void build_tree(int node, int lft, int rgt)
{
	if(lft == rgt)
	{
		tree[node][0] = ar[lft];
		tree[node][1] = ar[lft];
		return;
	}
	int mid = (lft + rgt) >> 1;
	build_tree(2 * node, lft, mid);
	build_tree(2 * node + 1, mid + 1, rgt);
	tree[node][0] = max(tree[2 * node][0], tree[2 * node + 1][0]);
	tree[node][1] = min(tree[2 * node][1], tree[2 * node + 1][1]);
}
void update_tree(int node, int lft, int rgt, int ind, int val)
{
	if(lft == rgt)
	{
		ar[lft] = val;
		tree[node][0] = val;
		tree[node][1] = val;
		return;
	}
	int mid = (lft + rgt) >> 1;
	if(ind <= mid)
		update_tree(2 * node, lft, mid, ind, val);
	else
		update_tree(2 * node + 1, mid + 1, rgt, ind, val);
	tree[node][0] = max(tree[2 * node][0], tree[2 * node + 1][0]);
	tree[node][1] = min(tree[2 * node][1], tree[2 * node + 1][1]);
}
pii query_tree(int node, int lft, int rgt, int l, int r)
{
	if(lft > rgt || lft > r || rgt < l)
		return mp(INT_MIN, INT_MAX);
	if(lft >= l && rgt <= r)
		return mp(tree[node][0], tree[node][1]);
	int mid = (lft + rgt) >> 1;
	pii p1 = query_tree(2 * node, lft, mid, l, r);
	pii p2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	return mp(max(p1.first, p2.first), min(p1.second, p2.second));
}
bool check(int l, int r, int val, int n)
{
	pii res = query_tree(1, 0, n - 1, l, r);
	return (res.first - ar[l] <= val && ar[l] - res.second <= val);
}
void solve(int ind, int val, int n)
{
	int ans1 = -1;
	int ans2 = -1;
	if(val >= 0)
	{
		int low = ind, high = n - 1, mid;
		while(low <= high)
		{
			mid = (low + high) >> 1;
			if(check(ind, mid, val, n) && (mid == n - 1 || !check(ind, mid + 1, val, n)))
				break;
			else if(check(ind, mid, val, n))
				low = mid + 1;
			else
				high = mid - 1;
		}
		ans1 = mid - ind + 1;
		pii res = query_tree(1, 0, n - 1, ind, mid);
		ans2 = max(res.first - ar[ind], ar[ind] - res.second);
	}
	cout<<ans1<<" "<<ans2<<endl;
}
int main()
{
	int n, m, i, l, r;
	char ch;
	si(n);
	si(m);
	rep(i, 0, n - 1)
		si(ar[i]);
	build_tree(1, 0, n - 1);
	while(m--)
	{
		cin>>ch;
		si(l);
		si(r);
		if(ch == 'U')
			update_tree(1, 0, n - 1, l - 1, r);
		else
			solve(l - 1, r, n);
	}
	return 0;
}