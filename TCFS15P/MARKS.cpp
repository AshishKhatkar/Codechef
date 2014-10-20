/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
vector<int>sub[5];
int main()
{
	ios_base::sync_with_stdio(false);
	int n,mark;
	cin>>n;
	char ch;
	for(int i=0;i<n;++i)
	{
		cin>>ch>>mark;
		sub[ch-'A'].push_back(mark);
	}
	vector<int>::iterator it;
	for(int i=0;i<5;++i)
	{
		int per=sub[i].size()/10;
		int cnt=0;
		map<ll,ll>mp;
		map<ll,ll>::iterator it1;
		for(it=sub[i].begin();it!=sub[i].end();++it)
		{
			mp[(*it)]++;
			cnt++;
		}
		if(cnt==0)
			cout<<"Nothing Unusual\n";
		else
		{
			int tmp=0;
			for(it1=mp.begin();it1!=mp.end();++it1)
			{
				if(it1->second>per)
				{
					cout<<it1->first<<" ";
					tmp++;
				}
			}
			if(tmp)
				cout<<endl;
			else
				cout<<"Nothing Unusual\n";
		}
	}
	return 0;
}
