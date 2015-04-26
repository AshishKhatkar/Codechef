/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll			long long int
#define vi			vector<int>
#define vl			vector<ll>
#define pii			pair<int,int>
#define pil			pair<int, ll>
#define pll			pair<ll, ll>
#define pli 			pair<ll, int>
#define pb(v, a)		v.push_back(a)
#define mp(a, b)		make_pair(a, b)
#define MOD			1000000007
#define rep(i, a, b)		for(i=a; i<=b; ++i)
#define rrep(i, a, b)		for(i=a; i>=b; --i)
#define si(a)			scanf("%d", &a)
#define sl(a)			scanf("%lld", &a)
#define pi(a)			printf("%d", a)
#define pl(a)			printf("%lld", a)
#define pn 			printf("\n")
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
pii p[100005];
bool compare(pii p1, pii p2)
{
	if(p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}
int main()
{
	int t, i, j, n;
	si(t);
	rep(i, 1, t)
	{
		si(n);
		rep(j, 1, n)
		{
			si(p[j].first);
			si(p[j].second);
		}
		sort(p + 1, p + n + 1, compare);
		int ans = 1;
		int miny = p[1].second;
		rep(j, 2, n)
		{
			if(p[j].first > miny)
			{
				ans++;
				miny = p[j].second;
			}
			else
				miny = min(miny, p[j].second);
		}
		pi(ans);
		pn;
	}
	return 0;
}