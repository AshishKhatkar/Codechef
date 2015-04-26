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
ll ar[100005];
int main()
{
	int t, i, j;
	si(t);
	rep(i, 1, t)
	{
		int n;
		si(n);
		rep(j, 0, n - 1)
			sl(ar[j]);
		if(n == 1)
		{
			printf("1 0\n");
			continue;
		}
		ll val1 = ar[0], val2 = ar[n - 1];
		int ind1 = 1, ind2 = n - 2, cnt1 = 1, cnt2 = 1;
		while(ind1 <= ind2)
		{
			if(val1 < val2)
			{
				val1 += ar[ind1];
				ind1++;
				cnt1++;
			}
			else if(val1 > val2)
			{
				val2 += ar[ind2];
				ind2--;
				cnt2++;
			}
			else if(val1 == val2)
			{
				if(ind1 != ind2)
				{
					val1 += ar[ind1];
					val2 += ar[ind2];
					ind1++;
					ind2--;
					cnt1++;
					cnt2++;
				}
				else
				{
					val1 += ar[ind1];
					ind1++;
					cnt1++;
				}
			}
		}
		cout<<cnt1<<" "<<cnt2<<endl;
	}
	return 0;
}