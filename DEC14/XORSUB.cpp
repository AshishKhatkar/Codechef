/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2(vector<int> v, int k)
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<int> sub;
	sub.push_back(0);
	for(int i=0; i<(int)v.size(); ++i)
	{
		int sz = (int)sub.size();
		for(int j=0; j<sz; ++j)
			sub.push_back(sub[j] ^ v[i]);
		sort(sub.begin(), sub.end());
		sub.erase(unique(sub.begin(), sub.end()), sub.end());
	}
	int ans=0;
	for(int i=0; i<sub.size(); ++i)
		ans = max(ans, sub[i] ^ k);
	cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n, k, tmp;
		cin>>n>>k;
		vector<int> v;
		for(int i=0; i<n; ++i)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		solve_subtask1_subtask2(v, k);
	}
	return 0;
}