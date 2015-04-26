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
ll ar[100005];
void subtask1(int n, int k)
{
	bool flag[n + 1];
	memset(flag, true, sizeof(flag));
	bool flag1[10005];
	memset(flag1, false, sizeof(flag1));
	vector<int> sum;
	int i, j, tmp;
	rep(i, 1, k)
	{
		si(tmp);
		flag[tmp] = false;
	}
	if(flag[1] == false)
	{
		printf("Chef\n");
		return;
	}
	if(flag[2] == false)
	{
		printf("Mom\n");
		return;
	}
	rep(i, 1, n)
	{
		if(!flag[i])
			continue;
		int sz = (int)sum.size();
		pb(sum, i);
		flag1[i] = true;
		rep(j, 0, sz - 1)
		{
			if(flag1[sum[j] + i] == false)
			{
				pb(sum, sum[j] + i);
				flag1[sum[j] + i] = true;
			}
		}
		sort(sum.begin(), sum.end());
	}
	int ans;
	rep(i, 1, 10000)
	{
		if(!flag1[i])
		{
			if(i & 1)
				printf("Chef\n");
			else
				printf("Mom\n");
			return;
		}
	}
}
void subtask2(ll n)
{
	ll val = (n * (n + 1)) / 2;
	if(val & 1)
		printf("Mom\n");
	else
		printf("Chef\n");
}
//TODO
void subtask3(ll n, int k)
{
	int i;
	ar[0] = 0;
	ll cnt = 0;
	rep(i, 1, k)
	{
		sl(ar[i]);
		cnt += ar[i];
	}
	sort(ar + 1, ar + k + 1);
	ll covered_till = 0;
	ll tmp;
	rep(i, 1, k)
	{
		tmp = (ar[i] * (ar[i] - 1)) / 2 - (ar[i - 1] * (ar[i - 1] + 1)) / 2;
		covered_till += tmp;
		if(ar[i] > covered_till)
		{
			if(covered_till & 1)
				printf("Mom\n");
			else
				printf("Chef\n");
			return;
		}
	}
	ll val = (n * (n + 1)) / 2 - cnt;
	if(val & 1)
		printf("Mom\n");
	else
		printf("Chef\n");
}
int main()
{
	int t, i, j, k;
	int n, tmp;
	si(t);
	rep(i, 1, t)
	{
		si(n);
		si(k);
		if(k == 0)
			subtask2(1LL * n);
		else if(k == n)
		{
			rep(j, 1, k)
				si(tmp);
			printf("Chef\n");
		}
		else if(n <= 100)
			subtask1(n, k);
		else
			subtask3(1LL * n, k);
	}
	return 0;
}