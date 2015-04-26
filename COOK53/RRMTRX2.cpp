/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	10000007
int main()
{
	ios_base::sync_with_stdio(false);
	int n, m;
	cin>>n>>m;
	ll ans = 1;
	ll ar[n][m];
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j)
			cin>>ar[i][j];
	for(int j=0; j<m; ++j)
	{
		ll cnt = 0;
		for(int i=0; i<n; ++i)
			cnt = (cnt + ar[i][j]) % MOD;
		ans = (ans * cnt) % MOD;
	}
	while(ans < 0)
		ans += MOD;
	ans %= MOD;
	cout<<ans<<endl;
	return 0;
}