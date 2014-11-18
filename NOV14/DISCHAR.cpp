/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
void solve_subtask1_subtask2(string str)
{
	int ar[26];
	memset(ar,0,sizeof(ar));
	int len=str.length();
	for(int i=0;i<len;++i)
		ar[str[i]-'a']++;
	int ans=0;
	for(int i=0;i<26;++i)
		if(ar[i]>0)
			ans++;
	cout<<ans<<endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		solve_subtask1_subtask2(str);
	}
	return 0;
}