/*
ID: ashish1610
PROG:
LANG: C++
Same as codechef LEEXAMS
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
double r[105][(1 << 15) + 5];
int p[105], a[105], b[105];
int main()
{
	int t, i, j, k;
	si(t);
	rep(i, 1, t)
	{
		int n;
		cin>>n;
		rep(j, 0, n - 1)
		{
			cin>>p[j]>>a[j]>>b[j];
			a[j]--;
			b[j]--;
		}
		// if(n > 15)
		// {
		// 	printf("0\n");
		// 	continue;
		// }
		memset(r, 0, sizeof(r));
		r[0][0] = 1.0;
		rep(j, 0, n - 1)
		{
			rep(k, 0, (1 << 15) - 1)
			{
				if((k & (1 << a[j])) == 0)
					r[j + 1][k + (1 << a[j])] += r[j][k] * p[j] / 100.0;
				if((k & (1 << b[j])) == 0)
					r[j + 1][k + (1 << b[j])] += r[j][k] * (100.0 - p[j]) / 100.0;
			}
		}
		double res = 0.0;
		rep(j, 0, (1 << 15) - 1)
			res += r[n][j];
		printf("%.6lf\n", res);
	}
	return 0;
}