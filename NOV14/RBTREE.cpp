/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll	long long int
#define MOD	1000000007
ll lca(ll u, ll v)
{
	while(u!=v)
	{
		if(u>v)
			u>>=1; 
		else
			v>>=1;
	}
	return u;
}
void solve_subtask1_subtask2_subtask3(ll q)
{
	ll x,y;
	string type;
	bool root=true;//black
	while(q--)
	{
		cin>>type;
		if(type=="Qi")
		{
			root=!root;
			continue;
		}
		cin>>x>>y;
		ll lca_val=lca(x,y);
		ll level_x=(ll)log2(x);
		level_x++;
		ll level_y=(ll)log2(y);
		level_y++;
		ll level_lca_val=(ll)log2(lca_val);
		level_lca_val++;
		if(x==y && type=="Qb")
		{
			if(level_x&1)
				cout<<(root?1:0)<<endl;
			else
				cout<<(root?0:1)<<endl;
			continue;
		}
		else if(x==y && type=="Qr")
		{
			if(level_x&1)
				cout<<(root?0:1)<<endl;
			else
				cout<<(root?1:0)<<endl;
			continue;
		}
		if(type=="Qb")
		{
			if(root)
			{
				ll ans=(level_x+1)/2 + (level_y+1)/2;
				ll tmp=(level_lca_val+1)/2;
				if(level_lca_val!=1)
					ans=ans-2*tmp;
				else
					ans--;
				if(level_lca_val!=1 && level_lca_val&1)
					ans++;
				cout<<ans<<endl;
			}
			else
			{
				ll ans=level_x/2 + level_y/2;
				ll tmp=level_lca_val/2;
				if(level_lca_val!=1)
					ans=ans-2*tmp;
				if(!(level_lca_val&1))
					ans++;
				cout<<ans<<endl;
			}
		}
		else 
		{
			if(root)
			{
				ll ans=level_x/2 + level_y/2;
				ll tmp=level_lca_val/2;
				if(level_lca_val!=1)
					ans=ans-2*tmp;
				if(!(level_lca_val&1))
					ans++;
				cout<<ans<<endl;
			}
			else
			{
				ll ans=(level_x+1)/2 + (level_y+1)/2;
				ll tmp=(level_lca_val+1)/2;
				if(level_lca_val!=1)
					ans=ans-2*tmp;
				else
					ans--;
				if(level_lca_val!=1 && level_lca_val&1)
					ans++;
				cout<<ans<<endl;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	ll q;
	cin>>q;
	solve_subtask1_subtask2_subtask3(q);
	return 0;
}