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
	int st, end;
	vector<int> ind;
};
seg_node tree[1 << 20];
int ar[500001];
void build_tree(int node, int lft, int rgt)
{
	tree[node].st = lft;
	tree[node].end = rgt;
	if(lft != rgt)
	{
		int mid = (lft + rgt) >> 1;
		build_tree(2 * node, lft, mid);
		build_tree(2 * node + 1, mid + 1, rgt);
	}
}
void query_0(int node, int val, int id)
{
	if(tree[node].st == tree[node].end)
	{
		pb(tree[node].ind, id);
		return;
	}
	int mid = (tree[node].st + tree[node].end) >> 1;
	if(val <= mid)
		query_0(2 * node, val, id);
	else
		query_0(2 * node + 1, val, id);
	pb(tree[node].ind, id);
}
int query_1(int node, int lft, int rgt, int val, bitset<19> bits, int n, int bit_no)
{
	if(tree[node].ind.size() <= n - rgt + lft - 1)
	{
		bool flag = false;
		int low = 0, high = tree[node].ind.size() - 1;
		while(low <= high)
		{
			int mid = (low + high) >> 1;
			if(tree[node].ind[mid] > rgt)
				high = mid - 1;
			else if(tree[node].ind[mid] >= lft)
			{
				flag = true;
				break;
			}
			else
				low = mid + 1;
		}
		if(!flag && high >= 0)
		{
			if(tree[node].ind[high] >= lft && tree[node].ind[high] <= rgt)
				flag = true;
		}
		if(!flag)
			return -1;
	}
	if(tree[node].st == tree[node].end)
		return tree[node].st;
	if(bits[bit_no])
	{
		int res = query_1(2 * node, lft, rgt, val, bits, n, bit_no - 1);
		if(res == -1)
			res = query_1(2 * node + 1, lft, rgt, val, bits, n, bit_no - 1);
		return res;
	}
	else
	{
		int res = query_1(2 * node + 1, lft, rgt, val, bits, n, bit_no - 1);
		if(res == -1)
			res = query_1(2 * node, lft, rgt, val, bits, n, bit_no - 1);
		return res;
	}
}
void query_2(int node, int val)
{
	if(tree[node].st == tree[node].end)
	{
		tree[node].ind.pop_back();
		return;
	}
	int mid = (tree[node].st + tree[node].end) >> 1;
	if(val <= mid)
		query_2(2 * node, val);
	else
		query_2(2 * node + 1, val);
	tree[node].ind.pop_back();
}
int query_3(int node, int lft, int rgt, int val)
{
	if(val >= tree[node].end)
	{
		int res1 = lower_bound(tree[node].ind.begin(), tree[node].ind.end(), lft) - tree[node].ind.begin();
		int res2 = upper_bound(lower_bound(tree[node].ind.begin(), tree[node].ind.end(), lft), tree[node].ind.end(), rgt) - tree[node].ind.begin();
		return res2 - res1;
	}
	int mid = (tree[node].st + tree[node].end) >> 1;
	if(val <= mid)
		return query_3(2 * node, lft, rgt, val);
	else
		return query_3(2 * node, lft, rgt, val) + query_3(2 * node + 1, lft, rgt, val);
}
int query_4(int node, int lft, int rgt, int val)
{
	int low = 0, high = 5 * 100000;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(query_3(1, lft, rgt, mid) >= val)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return high + 1;
}
int main()
{
	int n, i;
	si(n);
	build_tree(1, 0, (1 << 19) - 1);
	int sz = 0;
	rep(i, 1, 500000)
		ar[i] = -1;
	rep(i, 1, n)
	{
		int type;
		si(type);
		if(type == 0)
		{
			int val;
			si(val);
			ar[sz] = val;
			query_0(1, val, sz);
			sz++;
		}
		else if(type == 1)
		{
			int l, r, val;
			si(l);
			si(r);
			si(val);
			bitset<19> bs(val);
			pi(query_1(1, l - 1, r - 1, val, bs, sz, 18));
			pn;
		}
		else if(type == 2)
		{
			int k, j;
			si(k);
			rep(j, 1, k)
			{
				query_2(1, ar[sz - 1]);
				ar[sz - 1] = -1;
				sz--;
			}
		}
		else if(type == 3)
		{
			int l, r, val;
			si(l);
			si(r);
			si(val);
			pi(query_3(1, l - 1, r - 1, val));
			pn;
		}
		else if(type == 4)
		{
			int l, r, val;
			si(l);
			si(r);
			si(val);
			pi(query_4(1, l - 1, r - 1, val));
			pn;
		}
	}
	return 0;
}