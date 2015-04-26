/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2_subtask3(vector<int> v)
{
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	cout<<v.size()<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n, tmp;
		cin>>n;
		vector<int> v;
		for(int i=0; i<n; ++i)
		{
			cin>>tmp;
			v.push_back(tmp);
		}
		solve_subtask1_subtask2_subtask3(v);
	}
	return 0;
}