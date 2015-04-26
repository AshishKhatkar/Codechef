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
vector<int> ind[2], ind1[2];
int cnt[2]; 
//0 for blue and 1 for green
int main()
{
	int t, i, j, type, len, correct, wrong;
	si(t);
	string str;
	rep(i, 1, t)
	{
		si(type);
		cin>>str;
		len = str.length();
		cnt[0] = cnt[1] = 0;
		rep(j, 0, len - 1)
		{
			if(str[j] == 'B')
				cnt[0]++;
			else
				cnt[1]++;
		}
		if(abs(cnt[0] - cnt[1]) > 1)
		{
			printf("-1\n");
			continue;
		}
		if(type == 0)
		{
			correct = wrong = 0;
			rep(j, 0, len - 1)
			{
				char ch = (j & 1) ? 'G' : 'B';
				if(str[j] == ch)
					correct++;
				else
					wrong++;
			}
			int ans = correct;
			if(ans & 1)
				ans = wrong;
			else if(!(wrong & 1))
				ans = min(ans, wrong);
			pi(ans / 2);
			pn;
		}
		//type 1 == type 2
		//Consider this example : type = 1, string = BBBGG ans is 3
		//now consider type = 2, ans is again 3, why because it is better to take dis steps rather than less than dis.
		else
		{
			ind[0].clear();
			ind[1].clear();
			ind1[0].clear();
			ind1[1].clear();
			correct = wrong = 0;
			rep(j, 0, len - 1)
			{
				char ch = (j & 1) ? 'G' : 'B';
				if(str[j] == ch)
				{
					correct++;
					if(str[j] == 'B')
						pb(ind[0], j);
					else
						pb(ind[1], j);
				}
				else
				{
					wrong++;
					if(str[j] == 'B')
						pb(ind1[0], j);
					else
						pb(ind1[1], j);
				}
			}
			int ans1 = 0, ans2 = 0;
			if(correct & 1)
				ans1 = INT_MAX;
			else
				rep(j, 0, correct / 2 - 1)
					ans1 += abs(ind[0][j] - ind[1][j]);
			if(wrong & 1)
				ans2 = INT_MAX;
			else
				rep(j, 0, wrong / 2 - 1)
					ans2 += abs(ind1[0][j] - ind1[1][j]);
			pi(min(ans1, ans2));
			pn;
		}
	}
	return 0;
}