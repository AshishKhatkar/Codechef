/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
struct segment
{
	long long int start;
	long long int end;
	segment(long long int i, long long int j)
	{
		start=i;
		end=j;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long int n,k,p;
		cin>>n>>k>>p;
		vector<segment> ks;
		vector<segment> ps;
		long long int x,y;
		for(int i=0;i<k;++i)
		{
			cin>>x>>y;
			/*	for circular	*/
			if(y<x)
				y+=n;
			ks.push_back(segment(x,y));
		}
		for(int i=0;i<p;++i)
		{
			cin>>x>>y;
			/*	for circular	*/
			if(y<x)
				y+=n;
			ps.push_back(segment(x,y));
		}
		/*for(int i=0;i<k;i++)
		{
			cout<<ks[i].start<<" "<<ks[i].end<<endl;
		}
		for(int i=0;i<p;i++)
		{
			cout<<ps[i].start<<" "<<ps[i].end<<endl;
		}*/
		bool flag=false;
		for(int i=0;i<k;++i)
		{
			flag=false;
			for(int j=0;j<p;++j)
			{
				/*	ks[i].start+n>=ps[j].start && ks[i].end+n<=ps[j].end for circular	*/
				if((ks[i].start>=ps[j].start && ks[i].end<=ps[j].end)||(ks[i].start+n>=ps[j].start && ks[i].end+n<=ps[j].end))			
				{
					flag=true;
					break;
				}
			}
			if(!flag)
				break;
		}
		if(flag)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
