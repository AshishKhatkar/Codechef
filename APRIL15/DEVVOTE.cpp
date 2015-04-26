/*
ID: ashish1610
PROG:
LANG: C++
Solution Generation Code : http://ideone.com/QXtwSl
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
double res[7] = {1.000000, 2.000000, 2.000000, 1.777778, 1.656250, 1.660800, 1.733668};
int main()
{
	int t;
	si(t);
	while(t--)
	{
		int n;
		si(n);
		if(n <= 7)
			printf("%.6f\n", res[n - 1]);
		else
			printf("0.000000\n");
	}
	return 0;
}