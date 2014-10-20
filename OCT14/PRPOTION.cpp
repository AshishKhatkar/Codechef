/*
ID: ashish1610
PROG:
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
#define MOD 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        ll r,g,b,m;
        cin>>r>>g>>b>>m;
        ll maxr=0,maxg=0,maxb=0,tmp;
        for(int i=0;i<r;++i)
        {
            cin>>tmp;
            maxr=max(maxr,tmp);
        }
        for(int i=0;i<g;++i)
        {
            cin>>tmp;
            maxg=max(maxg,tmp);
        }
        for(int i=0;i<b;++i)
        {
            cin>>tmp;
            maxb=max(maxb,tmp);
        }
        ll ans=max(maxr,max(maxg,maxb));
        ll val=ans;
        while(m--)
        {
            if(val==maxr)
            {
                maxr/=2;
                //maxg++;
                //maxb++;
            }
            else if(val==maxg)
            {
                //maxr++;
                maxg/=2;
                //maxb++;
            }
            else
            {
                //maxr++;
                //maxg++;
                maxb/=2;
            }
            val=max(maxr,max(maxg,maxb));
            ans=min(ans,val);
        }
        cout<<ans<<endl;
    }
    return 0;
} 
