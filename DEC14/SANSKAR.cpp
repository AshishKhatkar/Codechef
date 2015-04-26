/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2(vector<ll> v, int k, ll cnt)
{
	if(cnt == 0 && v.size() >= k)
	{
		cout<<"yes\n";
		return;
	}
	if(cnt % k != 0 || v.size() < k)
	{
		cout<<"no\n";
		return;
	}
	int n = v.size();
	ll eq = cnt / k, sm;
	vector<ll> masks;
	for(int i = 1; i < (1 << n); ++i)
	{
		sm = 0;
		for(int j = 0; j < n; ++j)
			if(i & (1 << j))
				sm += v[j];
		if(sm == eq)
			masks.push_back(i);
	}
	if(masks.size() < k)
	{
		cout<<"no\n";
		return;
	}
	ll mask = 0, ans = 0;
	for(int i = 0; i < masks.size(); ++i)
	{
		bool found = true;
		for(int j = 0; j < n; ++j)
		{
			if((masks[i] & (1 << j)) && (mask & (1 << j)))
			{
				found = false;
				break;
			}
		}
		if(found)
		{
			ans++;
			mask |= masks[i];
		}
	}
	if(ans == k)
	{
		cout<<"yes\n";
		return;
	}
	cout<<"no\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n, k;
		cin>>n>>k;
		vector<ll> v;
		ll tmp, cnt = 0;
		for(int i = 0; i < n; ++i)
		{
			cin>>tmp;
			cnt += tmp;
			v.push_back(tmp);
		}
		random_shuffle(v.begin(), v.end());
		solve_subtask1_subtask2(v, k, cnt);
	}
	return 0;
}