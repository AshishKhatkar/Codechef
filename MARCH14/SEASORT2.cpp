/*	ashish1610	*/
#include<bits/stdc++.h>
using namespace std;
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
int ar[10005],temp[10005],temp1[10005];
vector<int>v;
vector<int>v1;
int n;
void from_end()
{
	int e=0,maxx=0,max_index=0;
	bool flag=false;
	while(e<n-1)
	{
		while(e<n && temp[n-e]==temp1[n-e])
			e++;
		maxx=temp1[n-e];
		for(int i=n-e-1;i>=0;--i)
			if(temp1[i]>maxx)
			{
				maxx=temp1[i];
				max_index=i;
				flag=true;
			}
		if(flag)
		{
			v1.push_back(max_index);
			v1.push_back(n-e);
			for(int i=max_index,j=n-e;i<j;--j,++i)
				swap(temp1[i],temp1[j]);
		}
		flag=false;
		e++;
	}
}
void from_start()
{
	int st=0,minx=0,min_index=0;
	bool flag=false;
	while(st<n-1)
	{	
		while(st<n && temp[st+1]==ar[st+1])
			st++;
		minx=ar[st+1];
		for(int i=st+2;i<=n;++i)
			if(ar[i]<minx)
			{
				minx=ar[i];
				min_index=i;
				flag=true;
			}
		if(flag)
		{
			v.push_back(st+1);
			v.push_back(min_index);
			for(int i=st+1,j=min_index;i<j;--j,++i)
				swap(ar[i],ar[j]);
		}
		flag=false;
		st++;
	}
}
int main()
{
	inp(n);
	for(int i=1;i<=n;++i)
		inp(ar[i]);
	for(int i=1;i<=n;++i)
	{
		temp[i]=ar[i];
		temp1[i]=ar[i];
	}
	temp[0]=0;
	sort(temp,temp+n+1);
	from_start();
	from_end();
	long long int sum=0;
	for(int i=0;i<v.size()/2;i++)
	{
		sum+=(v[i+1]-v[i]+1);
	}
	for(int i=0;i<v1.size()/2;i++)
	{
		sum+=(v1[i+1]-v1[i]+1);
	}
	if(sum/n+v.size()/2<v1.size()/2)
	{
		cout<<v.size()/2<<endl;
		for(int i=0;i<v.size();i+=2)
			cout<<v[i]<<" "<<v[i+1]<<endl;
	}
	else
	{
		cout<<v1.size()/2<<endl;
		for(int i=0;i<v1.size();i+=2)
			cout<<v1[i]<<" "<<v1[i+1]<<endl;
	}
	return 0;
}
