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
struct seg_node
{
	int val;
	int count;
};
int n,m;
vector<int>v[100005], temp[100005], fac[100005];
int v1[100005];
vector<seg_node> seg_vec[100005];
void build_segtree(int div, int pos, int s, int e)
{
	if(s==e)
	{
		seg_vec[div][pos].val =v1[temp[div][s]];
		seg_vec[div][pos].count=1;
		return;
	}
	build_segtree(div,pos*2+1, s, (s+e)/2);
	build_segtree(div,pos*2+2, (s+e)/2+1, e);
	if(seg_vec[div][pos*2+1].val<seg_vec[div][pos*2+2].val)
		seg_vec[div][pos] = seg_vec[div][pos*2+2];
	else if(seg_vec[div][pos*2+1].val>seg_vec[div][pos*2+2].val)
		seg_vec[div][pos] = seg_vec[div][pos*2+1];
	else
	{
		seg_vec[div][pos] = seg_vec[div][pos*2+1];
		seg_vec[div][pos].count = seg_vec[div][pos*2+2].count + seg_vec[div][pos*2+1].count;
	}
}
seg_node query(int div, int pos, int s, int e, int x, int y)
{
	if(s == x && e == y)
		return seg_vec[div][pos];
	if(y <= (s+e)/2)
		return query(div, pos*2 + 1, s, (s+e)/2, x, y);
	else if(x > (s+e)/2)
		return query(div, pos*2 + 2, (s+e)/2 + 1, e, x, y);
	else
	{
		seg_node lt, rt, res;
		lt = query(div, pos*2 + 1, s, (s+e)/2, x, (s+e)/2);
		rt = query(div, pos*2 + 2, (s+e)/2 + 1, e, (s+e)/2 + 1, y);
		if(lt.val>rt.val)
			return lt;
		else if(lt.val<rt.val)
			return rt;
		else
		{
			res=lt;
			res.count=rt.count+lt.count;
			return res;
		}
	}
}
void calculate()
{
	seg_node node;
	int val, x, y;
	vector<int>::iterator lt, rt;
	for(int i=0;i<m;++i)
	{
		inp(val);
		inp(x);
		inp(y);
		x--, y--;
		if(y<x)
			swap(x,y);
		int ans=-1;
		int ans_count=-1;
		for(int j=0;j<fac[val].size();++j)
		{
			if(temp[fac[val][j]].size())
			{
				int pp = fac[val][j];
				lt = lower_bound(temp[fac[val][j]].begin(), temp[fac[val][j]].end(), x);
				rt = upper_bound(temp[fac[val][j]].begin(), temp[fac[val][j]].end(), y);
				if(rt==temp[pp].begin())
					continue;
				rt--;
				int xx, yy;
				if(lt==temp[pp].end())
					continue;
				xx = lt-temp[pp].begin();
				yy = rt-temp[pp].begin();
				if(xx>yy)
					continue;
				node = query(fac[val][j], 0, 0, temp[fac[val][j]].size()-1, xx, yy);
				if(node.val>ans)
				{
					ans = node.val;
					ans_count = node.count;
				}
			}
		}
		cout<<ans<<" "<<ans_count<<endl;
	}
}
int main()
{
	inp(n);
	inp(m);
	for(int i=2;i<=100000;++i)
	{
		int val = i;
		for(int j=2; j*j<=val;++j)
		{
			if(val%j==0)
			{
				fac[i].push_back(j);
				while(val%j==0)
					val/=j;
			}
		}
		if(val>1)
			fac[i].push_back(val);
	}
	for(int i=0;i<n;++i)
	{
		inp(v1[i]);
		for(int j=0;j<fac[v1[i]].size();++j)
			temp[fac[v1[i]][j]].push_back(i);
	}
	for(int i=2;i<=100000;++i)
	{
		if(temp[i].size())
		{
			seg_vec[i].resize(4*(temp[i].size()));
			build_segtree(i, 0, 0, temp[i].size()-1);
		}
	}
	calculate();
	return 0;
}
