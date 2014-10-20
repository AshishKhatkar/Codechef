/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
struct point
{
	int x,y;
};
bool compare(point p1, point p2)
{
	if(p1.x==p2.x)
		return p1.y<p2.y;
	return p1.x<p2.x;
}
int main() 
{
	ios_base::sync_with_stdio(false);
	int n,k,x,y;
	cin>>n>>k;
	int ar[n];
	for(int i=0;i<n;++i)
		cin>>ar[i];
	sort(ar,ar+n);
	vector<point>v(k);
	for(int i=0;i<k;++i)
		cin>>v[i].x>>v[i].y;
	sort(v.begin(),v.end(),compare);
	int minx=v[0].x, maxx=v[k-1].y;
	int ans=0;
	int j=0;
	for(int i=0;i<n && j<k;)
	{
		if(i>=n || ar[i]>maxx)
			break;
		while(i<n && ar[i]<minx)
			++i;
		while(i<n && ar[i]>=v[j].x && ar[i]<=v[j].y)
		{
			++ans;
			++i;
		}
		minx=v[++j].x;
	}
	cout<<ans<<endl;
	return 0;
}
