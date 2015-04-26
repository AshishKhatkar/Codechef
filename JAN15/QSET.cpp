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
int n, m;
string str;
struct seg_node
{
	ll pref[3], suff[3], ans, cmp;
};
struct seg_node tree[3 * 100005];
void build_tree(int node, int lft, int rgt)
{
	int i;
	if(lft == rgt)
	{
		rep(i, 0, 2)
			tree[node].pref[i] = tree[node].suff[i] = 0LL;
		tree[node].pref[(str[lft] - '0') % 3] = 1LL;
		tree[node].suff[(str[lft] - '0') % 3] = 1LL;
		tree[node].cmp = (str[lft] - '0') % 3;
		tree[node].ans = ((str[lft] - '0') % 3 == 0) ? 1LL : 0LL;
		return;
	}
	int mid = (lft + rgt) >> 1;
	build_tree(2 * node, lft, mid);
	build_tree(2 * node + 1, mid + 1, rgt);
	rep(i, 0, 2)
	{
		tree[node].pref[((tree[2 * node].cmp) + i) % 3] = tree[2 * node].pref[((tree[2 * node].cmp) + i) % 3] + tree[2 * node + 1].pref[i];
		tree[node].suff[((tree[2 * node + 1].cmp) + i) % 3] = tree[2 * node + 1].suff[((tree[2 * node + 1].cmp) + i) % 3] + tree[2 * node].suff[i];
	}
	tree[node].cmp = (tree[2 * node].cmp + tree[2 * node + 1].cmp) % 3;
	tree[node].ans = tree[2 * node].ans + tree[2 * node + 1].ans + tree[2 * node].suff[0] * tree[2 * node + 1].pref[0] + tree[2 * node].suff[1] * tree[2 * node + 1].pref[2] + tree[2 * node].suff[2] * tree[2 * node + 1].pref[1];
}
void update_tree(int node, int lft, int rgt, int ind, int val)
{
	int i;
	if(lft == rgt)
	{
		rep(i, 0, 2)
			tree[node].pref[i] = tree[node].suff[i] = 0LL;
		tree[node].pref[val % 3] = 1LL;
		tree[node].suff[val % 3] = 1LL;
		tree[node].cmp = val % 3;
		tree[node].ans = (val % 3 == 0) ? 1LL : 0LL;
		return;
	}
	int mid = (lft + rgt) >> 1;
	if(ind <= mid)
		update_tree(2 * node, lft, mid, ind, val);
	else
		update_tree(2 * node + 1, mid + 1, rgt, ind, val);
	rep(i, 0, 2)
	{
		tree[node].pref[((tree[2 * node].cmp) + i) % 3] = tree[2 * node].pref[((tree[2 * node].cmp) + i) % 3] + tree[2 * node + 1].pref[i];
		tree[node].suff[((tree[2 * node + 1].cmp) + i) % 3] = tree[2 * node + 1].suff[((tree[2 * node + 1].cmp) + i) % 3] + tree[2 * node].suff[i];
	}
	tree[node].cmp = (tree[2 * node].cmp + tree[2 * node + 1].cmp) % 3;
	tree[node].ans = tree[2 * node].ans + tree[2 * node + 1].ans + tree[2 * node].suff[0] * tree[2 * node + 1].pref[0] + tree[2 * node].suff[1] * tree[2 * node + 1].pref[2] + tree[2 * node].suff[2] * tree[2 * node + 1].pref[1];
}
struct seg_node query_tree(int node, int lft, int rgt, int l, int r)
{
	int i;
	if(lft > rgt || lft > r || rgt < l)
	{
		struct seg_node tmp;
		rep(i, 0, 2)
			tmp.pref[i] = tmp.suff[i] = -1LL;
		tmp.cmp = -1LL;
		tmp.ans = -1LL;
		return tmp;
	}
	if(lft >= l && rgt <= r)
		return tree[node];
	int mid = (lft + rgt) >> 1;
	struct seg_node q1 = query_tree(2 * node, lft, mid, l, r);
	struct seg_node q2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	if(q1.ans == -1)
		return q2;
	if(q2.ans == -1)
		return q1;
	else
	{
		struct seg_node res;
		rep(i, 0, 2)
		{
			res.pref[(q1.cmp + i) % 3] = q1.pref[(q1.cmp + i) % 3] + q2.pref[i];
			res.suff[(q2.cmp + i) % 3] = q2.suff[(q2.cmp + i) % 3] + q1.suff[i];
		}
		res.cmp = (q1.cmp + q2.cmp) % 3;
		res.ans = q1.ans + q2.ans + q1.suff[0] * q2.pref[0] + q1.suff[1] * q2.pref[2] + q1.suff[2] * q2.pref[1];
		return res;
	}
}
int main()
{
	int i;
	si(n);
	si(m);
	cin>>str;
	build_tree(1, 0, n - 1);
	rep(i, 1, m)
	{
		int type, x, y;
		si(type);
		si(x);
		si(y);
		if(type == 1)
			update_tree(1, 0, n - 1, x - 1, y);
		else
		{
			pl(query_tree(1, 0, n - 1, x - 1, y - 1).ans);
			pn;
		}
	}
	return 0;
}