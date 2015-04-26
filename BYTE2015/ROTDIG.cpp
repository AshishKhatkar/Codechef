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
string rl(string str)
{
	str += str[0];
	str.erase(str.begin());
	int ind = 0, j;
	while(str[ind] == '0')
		ind++;
	string res = "";
	rep(j, ind, str.length() - 1)
		res += str[j];
	return res;
}
string rr(string str)
{
	str = str[str.length() - 1] + str;
	str.erase(str.end() - 1);
	int ind = 0, j;
	while(str[ind] == '0')
		ind++;
	string res = "";
	rep(j, ind, str.length() - 1)
		res += str[j];
	return res;
}
int main()
{
	int t, i, j, k;
	si(t);
	rep(i, 1, t)
	{
		string str;
		cin>>str;
		string tmp = str;
		ll ans = 0;
		rep(j, 0, str.length() - 1)
		{
			str = rl(str);
			ll val = 0;
			rep(k, 0, str.length() - 1)
				val = val * 10 + (str[k] - '0');
			ans = max(ans, val);
		}
		str = tmp;
		rep(j, 0, str.length() - 1)
		{
			str = rr(str);
			ll val = 0;
			rep(k, 0, str.length() - 1)
				val = val * 10 + (str[k] - '0');
			ans = max(ans, val);
		}
		str = tmp;
		str = rl(rr(str));
		ll val = 0;
		rep(k, 0, str.length() - 1)
			val = val * 10 + (str[k] - '0');
		ans = max(ans, val);
		str = tmp;
		str = rr(rl(str));
		val = 0;
		rep(k, 0, str.length() - 1)
			val = val * 10 + (str[k] - '0');
		ans = max(ans, val);
		cout<<ans<<endl;
	}
	return 0;
}