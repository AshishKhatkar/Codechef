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
ll tree[505][2][4 * 505];
ll read(ll ind, ll tre, int id)
{
	ll res = 0;
	while(ind)
	{
		res += tree[tre][id][ind];
		ind -= (ind & (-ind));
	}
	return res;
}
void update(ll ind, ll val, ll sz, ll tre, int id)
{
	while(ind <= sz)
	{
		tree[tre][id][ind] += val;
		ind += (ind & (-ind));
	}
}	
int main()
{
	int n, m;
	si(n);
	si(m);
	memset(tree, 0, sizeof(tree));
	int i, j;
	ll val;
	rep(i, 1, n)
	{
		rep(j, 1, m)
		{
			sl(val);
			update(j, val, m, i, 1);
			update(j + 1, -val, m, i, 1);
			update(j, val * (j - 1), m, i, 2);
			update(j + 1, -val * j, m, i, 2);
		}
	}
	int q, type, x1, y1, x2, y2;
	si(q);
	while(q--)
	{
		si(type);
		si(x1);
		si(y1);
		si(x2);
		si(y2);
		if(type == 1)
		{
			sl(val);
			rep(i, x1, x2)
			{
				update(y1, val, m, i, 1);
				update(y2 + 1, -val, m, i, 1);
				update(y1, val * (y1 - 1), m, i, 2);
				update(y2 + 1, -val * y2, m, i, 2);
			}
		}
		else
		{
			ll res = 0;
			rep(i, x1, x2)
			{
				ll tmp_val = (read(y2, i, 1) * y2 - read(y2, i, 2));
				tmp_val = tmp_val - (read(y1 - 1, i, 1) * (y1 - 1) - read(y1 - 1, i, 2));
				res += tmp_val;
			}
			pl(res);
			pn;
		}
	}
	return 0;
}