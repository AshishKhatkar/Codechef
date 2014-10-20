/*
ID: ashish1610
PROG:
LANG: C++
Suffix Array Implementation code taken from http://www.snip2code.com/Snippet/14344/Suffix-Array-Construction-in-O(nlogn)-us
*/
#include<bits/stdc++.h>
using namespace std;
#define ll    long long int
#define MOD   1000000007
#define MAX     1000005
/* fast io */
inline void inp(ll &n) 
{
        n=0;
    register ll ch=getchar_unlocked();
    ll sign=1;
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
/* Suffix Array */
char txt[MAX*10];
int iSA[MAX*10], SA[MAX*10], cnt[MAX*10], nxt[MAX*10], len, dis_str_i_i_prev[MAX*10], lcp[MAX*10], LCP[MAX][25];
bool bh[MAX*10], b2h[MAX*10];
ll pre_sum_dis_substr[MAX*10], ansK1, ansK2, ansL, ansR;
bool smaller_first_char(int a, int b)
{
    return txt[a] < txt[b];
}
inline void suffixSort(int n)
{
    for(int i=0; i<n; ++i)
        SA[i] = i;
    sort(SA, SA + n, smaller_first_char);
    for(int i=0; i<n; ++i)
    {
        bh[i] = i == 0 || txt[SA[i]] != txt[SA[i-1]];
        b2h[i] = false;
    }
    for(int h = 1; h < n; h <<= 1)
    {
        int buckets = 0;
        for(int i=0, j; i < n; i = j)
        {
            j = i + 1;
            while (j < n && !bh[j])
                j++;
            nxt[i] = j;
            buckets++;
        }
        if (buckets == n)
            break;
        for (int i = 0; i < n; i = nxt[i])
        {
            cnt[i] = 0;
            for(int j = i; j < nxt[i]; ++j)
                iSA[SA[j]] = i;
        } 
        cnt[iSA[n - h]]++;
        b2h[iSA[n - h]] = true;
        for(int i = 0; i < n; i = nxt[i])
        {
            for(int j = i; j < nxt[i]; ++j)
            {
                int s = SA[j] - h;
                if(s >= 0)
                {
                    int head = iSA[s];
                    iSA[s] = head + cnt[head]++;
                    b2h[iSA[s]] = true;
                }
            }
            for(int j = i; j < nxt[i]; ++j)
            {
                int s = SA[j] - h;
                if(s >= 0 && b2h[iSA[s]])
                {
                    for(int k = iSA[s]+1; !bh[k] && b2h[k]; k++)
                        b2h[k] = false;
                }
            }
        }
        for(int i=0; i<n; ++i)
        {
            SA[iSA[i]] = i;
            bh[i] |= b2h[i];
        }
    }
    for(int i=0; i<n; ++i)
        iSA[SA[i]] = i;
}
inline void getlcp(int n)
{
    for (int i=0; i<n; ++i) 
        iSA[SA[i]] = i;
    lcp[0] = 0;
    for(int i=0, h=0; i<n; ++i)
    {
        if (iSA[i] > 0)
        {
            int j = SA[iSA[i]-1];
            while (i + h < n && j + h < n && txt[i+h] == txt[j+h]) 
                h++;
            lcp[iSA[i]] = h; 
            if (h > 0) 
                h--;
        }
    }
}
struct node
{
    int cnt;
    node *lft,*rgt, *insert_node(int l, int r, int val);
}*root[MAX],*leaf;
node *node::insert_node(int l, int r, int val)
{
    if(l==r)
    {
        node *res=(node*)malloc(sizeof(node));
        res->cnt=this->cnt+1;
        res->lft=leaf;
        res->rgt=leaf;
        return res;
    }
    int mid=(l+r)>>1;
    if(val<=mid)
    {
        node *res=(node*)malloc(sizeof(node));
        res->cnt=this->cnt+1;
        res->lft=this->lft->insert_node(l,mid,val);
        res->rgt=this->rgt;
        return res;
    }
    else
    {
        node *res=(node*)malloc(sizeof(node));
        res->cnt=this->cnt+1;
        res->lft=this->lft;
        res->rgt=this->rgt->insert_node(mid+1,r,val);
        return res;
    }
}
inline int querySelect(node *nd1, node *nd2, int l, int r, int k)
{
    if(l==r)
        return l;
    int cn=(nd2->lft->cnt)-(nd1->lft->cnt);
    int mid=(l+r)>>1;
    if(cn>=k)
        return querySelect(nd1->lft,nd2->lft,l,mid,k);
    else
        return querySelect(nd1->rgt,nd2->rgt,mid+1,r,k-cn);
}
inline int queryRank(node *nd1, int l, int r, int val)
{
    if(r<0||l>val)
        return 0;
    if(l>=0&&r<=val)
        return nd1->cnt;
    int mid=(l+r)>>1;
    int q1=queryRank(nd1->lft,l,mid,val);
    int q2=queryRank(nd1->rgt,mid+1,r,val);
    return q1+q2;
}
inline int com_sol(int x, int y)
{
    if(x==y)
        return len-iSA[x];
    if(x>y)
        swap(x,y);
    int pow_2=0;
    while((1<<pow_2)<=(y-x))
        pow_2++;
    return min(LCP[x+1][pow_2-1],LCP[y-(1<<(pow_2-1))+1][pow_2-1]);
}
inline void pre_compute()
{
    for(int i=0;i<len;++i)
        LCP[i][0]=lcp[i];
    for(int j=1;(1<<j)<=len;++j)
        for(int i=0;(1<<j)+i-1<len;++i)
            LCP[i][j]=min(LCP[i][j-1], LCP[i+(1<<(j-1))][j-1]);
    dis_str_i_i_prev[0]=0;
    pre_sum_dis_substr[0]=len-SA[0];
    for(int i=1;i<len;++i)
    {
        dis_str_i_i_prev[i]=com_sol(i-1,i);
        pre_sum_dis_substr[i]=(len-SA[i])-dis_str_i_i_prev[i];
        pre_sum_dis_substr[i]+=pre_sum_dis_substr[i-1];   
    }
    node *tmp=(node*)malloc(sizeof(node));
    tmp->cnt=0;
    tmp->lft=NULL;
    tmp->rgt=NULL;
    leaf=tmp;
    leaf->lft=leaf;
    leaf->rgt=leaf;
    root[0]=leaf->insert_node(0,len-1,SA[0]);
    for(int i=1;i<len;++i)
        root[i]=(root[i-1])->insert_node(0,len-1,SA[i]);
}
inline int binarySearch(int ind, int n, int ord)
{
    int low, high, mid;
    if(ord==1)
    {
        low=0;
        high=ind;
    }
    else
    {
        low=ind;
        high=len-1;
    }
    bool flag1, flag2;
    while(low<=high)
    {
        mid=(low+high)>>1;
        if(com_sol(ind,mid)>=n)
            flag1=true;
        else
            flag1=false;
        if(ord==1)
        {
            if(mid==0 || com_sol(ind,mid-1)<n)
                flag2=true;
            else
                flag2=false;
            if(flag1 && flag2)
                break;
            else if(flag1)
                high=mid-1;
            else
                low=mid+1;
        }
        else
        {
            if(mid==len-1 || com_sol(ind,mid+1)<n)
            flag2=true;
            else
                flag2=false;
            if(flag1 && flag2)
                break;
            else if(flag1)
                low=mid+1;
            else
                high=mid-1;
        }
    }
    return mid;
}
inline void typeS(ll k1, int k2)
{
    int ind=lower_bound(pre_sum_dis_substr,pre_sum_dis_substr+len,k1)-pre_sum_dis_substr;
    if(ind)
        k1-=pre_sum_dis_substr[ind-1];
    int n = dis_str_i_i_prev[ind]+k1;
    int l=binarySearch(ind,n,1);
    int r=binarySearch(ind,n,2);
    if(l)
        ansL=querySelect(root[l-1],root[r],0,len-1,k2);
    else
        ansL=querySelect(leaf,root[r],0,len-1,k2);
    printf("%lld %lld\n",ansL+1,ansL+n);
}
inline void typeR(int l1, int r1)
{
    int pos = iSA[l1];
    int l=binarySearch(pos,r1-l1+1,1);
    ansK1=0;
    if(l)
        ansK1+=pre_sum_dis_substr[l-1];
    ansK1+=(r1-l1+1-dis_str_i_i_prev[l]);
    int r = binarySearch(pos,r1-l1+1,2);
    ansK2=queryRank(root[r],0,len-1,l1);
    if(l)
        ansK2-=queryRank(root[l-1],0,len-1,l1);
    else
        ansK2-=queryRank(leaf,0,len-1,l1);
    printf("%lld %lld\n",ansK1,ansK2);
}
int main()
{
    scanf("%s",txt);
    len=strlen(txt); 
    suffixSort(len); 
    getlcp(len);
    pre_compute();
    ll q,k1,k2,l1,r1;
    inp(q);
    char type[7];
    //scanf("%d",&q);
    while(q--)
    {
        scanf("%s",type);  
        if(type[0]=='S')
        {
            inp(k1),inp(k2);
            //scanf("%lld %d",&k1,&k2);
            typeS(k1,k2);
        }
        else
        {
            inp(l1),inp(r1);
            //scanf("%d %d",&l1,&r1);
            typeR(l1-1,r1-1);
        }   
    }
    return 0;
}
