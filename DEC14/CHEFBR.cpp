/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/* small subtasks */
void solve_subtask1_subtask2(vector<ll> ar, int n)
{
	vector<ll> v;
	stack<ll> sv;
	int cnt = 0;
	for(int i=0; i<(1 << n); ++i)
	{
		v.clear();
		for(int j=0; j<n; ++j)
			if(i & (1 << j))
				v.push_back(ar[j]);
		bool flag = true;
		for(int j=0; j<v.size(); ++j)
		{
			if(v[j] < 0)
				sv.push(v[j]);
			else if(v[j] > 0)
			{
				if(sv.empty() || (abs(sv.top()) != v[j]))
				{
					flag = false;
					break;
				}
				sv.pop();
			}
		}
		if(flag && sv.empty())
			cnt++;
		while(!sv.empty())
			sv.pop();
	}
	cout<<cnt<<endl;
}
/* todo */
ll ans[105][105];
ll dp(vector<ll> ar, int st, int end)
{
	if(ans[st][end] != -1)
		return ans[st][end];
	if(st >= end)
		return 0;
	ll cnt = 0;
	for(int i=st; i<=end; ++i)
	{
		if(ar[i] > 0)
			continue;
		for(int j=i+1; j<=end; ++j)
		{
			if(ar[i] == -ar[j])
			{
				ll val1 = (dp(ar, i+1, j-1) + 1) % MOD; // no. of possible subsequences from (i+1)th index to (j-1)th index
				ll val2 = (dp(ar, j+1, end) + 1) % MOD; // no. of possible subsequences from (j+1)th index to last index
				cnt = (cnt + val1 * val2) % MOD; // total will be val1 * val2
			}
		}
	}
	ans[st][end] = cnt;
	return ans[st][end];
}
void solve_subtask3(vector<ll> ar, int n)
{
	memset(ans, -1, sizeof(ans));
	cout<<(dp(ar, 0, n-1) + 1) % MOD<<endl;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	ll ar[n];
	for(int i=0; i<n; ++i)
		cin>>ar[i];
	vector<ll> v;
	for(int i=0; i<n; ++i)
	{
		bool found = false;
		for(int j=0; j<n; ++j)
		{
			if(ar[i]==-ar[j])
			{
				found = true;
				break;
			}
		}
		if(found)
			v.push_back(ar[i]);
	}
	if(n <= 20)
		solve_subtask1_subtask2(v, v.size());
	else
		solve_subtask3(v, v.size());
	return 0;
}