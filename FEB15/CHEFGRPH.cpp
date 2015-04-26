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
struct edge
{
	ll e[4];
};
bool compare(edge e1, edge e2)
{
	return mp(e1.e[2], e1.e[3]) < mp(e2.e[2], e2.e[3]);
}
vector<edge> edges(50005);
vector<pll> dp(2 * 50005);
vector<pair<pll, ll> > v(2 * 50005);
int bin_search1(int low, int high, int cur_ind)
{
	int res = 0;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(dp[mid].first >= cur_ind)
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return res;
}
int bin_search2(int low, int high, pll cur_ind)
{
	int res = 0;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(mp(edges[mid].e[2], edges[mid].e[3]) >= cur_ind)
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return res;
}
int bin_search3(int low, int high, pll cur_ind)
{
	int res = 0;
	while(low <= high)
	{
		int mid = (low + high) >> 1;
		if(v[mid].first >= cur_ind)
		{
			res = mid;
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	return res;
}
int main()
{
	ll n, m, k, i;
	sl(n);
	sl(m);
	sl(k);
	edge e1;
	rep(i, 0, k - 1)
	{
		sl(e1.e[0]);
		sl(e1.e[1]);
		sl(e1.e[2]);
		sl(e1.e[3]);
		edges[i] = e1;
		dp[2 * i] = mp(e1.e[0], 0);
		dp[2 * i + 1] = mp(e1.e[2], 0);
		v[2 * i] = mp(mp(e1.e[0], e1.e[1]), 0);
		v[2 * i + 1] = mp(mp(e1.e[2], e1.e[3]), 0);
	}
	if(k == 0)
	{
		pl(pow_mod(m, n));
		pn;
	}
	else
	{
		sort(dp.begin(), dp.end());
		sort(v.begin(), v.end());
		sort(edges.begin(), edges.end(), compare);
		/* Remove the Duplicates */
		dp.erase(unique(dp.begin(), dp.end()), dp.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int sz = v.size(), sz1 = dp.size(), edg_sz = edges.size(), ind;
		ll cnt = 0, cnt1 = 0;
		rep(i, 0, sz - 1)
		{
			// cout<<i<<" "<<cnt<<" "<<cnt1<<endl;
			if(i == 0)
			{
				if(v[i].first.first >= 1)
					cnt1 = pow_mod(m, v[i].first.first - 1);
				else
					cnt1 = 1;
				ind = bin_search1(0, sz1 - 1, v[i].first.first);
				dp[ind].second = cnt1;
			}
			else if(v[i].first.first != v[i - 1].first.first)
			{
				ind = bin_search1(0, sz1 - 1, v[i - 1].first.first);
				if(v[i - 1].first.first)
				{
					dp[ind].second = cnt;
					dp[ind].second = (dp[ind].second + (cnt1 * m)) % MOD;
				}
				cnt = 0;
				cnt1 = (dp[ind].second * pow_mod(m, v[i].first.first - v[i - 1].first.first - 1)) % MOD;
			}
			ind = bin_search2(0, edg_sz - 1, v[i].first);
			while(ind < edg_sz && mp(edges[ind].e[2], edges[ind].e[3]) == v[i].first)
			{
				int tmp = bin_search3(0, sz - 1, mp(edges[ind].e[0], edges[ind].e[1]));
				v[i].second = (v[i].second + v[tmp].second) % MOD;
				ind++;
			}
			cnt = (cnt + v[i].second) % MOD;
			v[i].second = (v[i].second + cnt1) % MOD;
		}
		// cout<<i<<" "<<cnt<<" "<<cnt1<<endl;
		// rep(i, 0, sz1 - 1)
		// 	cout<<dp[i].first<<" "<<dp[i].second<<endl;
		// rep(i, 0, sz - 1)
		// 	cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second<<endl;
		ll res = (cnt + ((v[sz - 1].first.first != n + 1) ? cnt1 * m : cnt1)) % MOD;
		if(v[sz - 1].first.first < n + 1)
			res = (res * pow_mod(m, n - v[sz - 1].first.first)) % MOD;
		pl(res);
		pn;
	}
	return 0;
} 