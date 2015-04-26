/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define	ll	long long int
#define MOD	1000000007
ll tree[4 * 50005];
ll ar[50005];
void build_tree(int node, int lft, int rgt)
{
	if(lft > rgt)
		return;
	if(lft == rgt)
	{
		tree[node] = ar[lft];
		return;
	}
	int mid = (lft + rgt) >> 1;
	build_tree(2 * node, lft, mid);
	build_tree(2 * node + 1, mid + 1, rgt);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
void update_tree(int node, int lft, int rgt, int ind, int val)
{
	if(lft == rgt)
	{
		ar[lft] = val;
		tree[node] = tree[node] + val;
		return;
	}
	int mid = (lft + rgt) >> 1;
	if(ind <= mid)
		update_tree(2 * node, lft, mid, ind, val);
	else
		update_tree(2 * node + 1, mid + 1, rgt, ind, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}
ll query_tree(int node, int lft, int rgt, int l, int r)
{
	if(lft > rgt || lft > r || rgt < l)
		return 0;
	if(lft >= l && rgt <= r)
		return tree[node];
	int mid = (lft + rgt) >> 1;
	ll ans1 = query_tree(2 * node, lft, mid, l, r);
	ll ans2 = query_tree(2 * node + 1, mid + 1, rgt, l, r);
	return ans1 + ans2;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(tree, 0, sizeof(tree));
		int n, q;
		scanf("%d %d", &n, &q);
		for(int i=0; i<n; ++i)
			scanf("%lld", &ar[i]);
		build_tree(1, 0, n - 1);
		while(q--)
		{
			int type, x, y;
			scanf("%d %d %d", &type, &x, &y);
			if(type == 2)
			{
				update_tree(1, 0, n - 1, x, y);
				update_tree(1, 0, n - 1, x + 1, -y);
			}
			else
			{
				ll res = query_tree(1, 0, n - 1, x, y);
				printf("%lld\n",res);
			}
		}
	}
	return 0;
}