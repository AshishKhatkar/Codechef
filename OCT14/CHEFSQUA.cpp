/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
/*	fast input	*/
inline void inp(int &n) 
{
    	n=0;
	register int ch=getchar_unlocked();
	int sign=1;
    	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			sign=-1; 
		ch=getchar_unlocked();
	}
    	while(ch>='0'&&ch<='9')
            n=(n<<3)+(n<<1)+ch-'0',ch=getchar_unlocked();
    	n=n*sign;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	inp(n);
	//cin>>n;
	if(n==0)
		cout<<"4\n";
	else if(n==1)
		cout<<"3\n";
	else if(n==2)
		cout<<"2\n";
	else
	{
		vector<pair<int,int> > v;
		pair<int,int> p;
		for(int i=0;i<n;++i)
		{
			inp(p.first);
			inp(p.second);
			//cin>>p.first>>p.second;
			v.push_back(p);
		}
		sort(v.begin(),v.end());
		int ans=2,cnt,x,y;
		pair<int,int>tmp,tmp1;
		for(int i=0;i<n;++i)
		{
			if(ans==0)
				break;
			for(int j=i+1;j<n;++j)
			{
				//if(i==j)
				//	continue;
				cnt=0;
				x=v[i].first+v[j].second-v[i].second;
				y=v[i].second+v[i].first-v[j].first;
				tmp=make_pair(x,y);
				if(tmp!=v[i] && tmp!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				x=v[j].first+v[j].second-v[i].second;
				y=v[j].second+v[i].first-v[j].first;
				tmp1=make_pair(x,y);
				if(tmp1!=tmp && tmp1!=v[i] && tmp1!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp1))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				ans=min(ans,2-cnt);
				
				cnt=0;
				x=v[i].first-v[j].second+v[i].second;
				y=v[i].second-v[i].first+v[j].first;
				tmp=make_pair(x,y);
				if(tmp!=v[i] && tmp!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				x=v[j].first-v[j].second+v[i].second;
				y=v[j].second-v[i].first+v[j].first;
				tmp1=make_pair(x,y);
				if(tmp1!=tmp && tmp1!=v[i] && tmp1!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp1))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				ans=min(ans,2-cnt);
				
				cnt=0;
				x=(v[i].first+v[j].first - abs(v[i].second-v[j].second))/2;
				y=(v[i].second+v[j].second + abs(v[i].first-v[j].first))/2;
				tmp=make_pair(x,y);
				if(tmp!=v[i] && tmp!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				x=(v[i].first+v[j].first + abs(v[i].second-v[j].second))/2;
				y=(v[i].second+v[j].second - abs(v[i].first-v[j].first))/2;
				tmp1=make_pair(x,y);
				if(tmp1!=tmp && tmp1!=v[i] && tmp1!=v[j])
				{
					if(binary_search(v.begin(),v.end(),tmp1))
					{
						//cout<<tmp.first<<" "<<tmp.second<<endl;
						cnt++;
					}
				}
				ans=min(ans,2-cnt);

				if(ans==0)
					break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
