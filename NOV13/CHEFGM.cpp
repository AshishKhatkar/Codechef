/*ashish1610*/
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

void mergeSort(int arr[],int low,int mid,int high)
{ 
    int i,m,k,l,temp[100];
    l=low;
    i=low;
    m=mid+1;
    while((l<=mid)&&(m<=high))
	{
         if(arr[l]<=arr[m])
		 {
             temp[i]=arr[l];
             l++;
         }
         else
		 {
             temp[i]=arr[m];
             m++;
         }
         i++;
    }
    if(l>mid)
	{
         for(k=m;k<=high;k++)
		 {
             temp[i]=arr[k];
             i++;
         }
    }
    else
	{
         for(k=l;k<=mid;k++)
		 {
             temp[i]=arr[k];
             i++;
         }
    }
    for(k=low;k<=high;k++)
	{
         arr[k]=temp[k];
    }
}

void partition(int arr[],int low,int high)
{ 
    int mid;
    if(low<high)
	{
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    	int m,n,i,j;
    	vector<int>v;
    	double ans=0.0;
        scanf("%d",&m);
        for(j=0;j<m;j++)
        {
            v.clear();
            scanf("%d",&n);
            int a[n];
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
            }
            partition(a,0,n-1);
            for(i=0;i<n;i++)
            {
                if(!i)
                {
                    v.push_back(a[i]&1);
                    continue;
                }
                if(a[i]==a[i-1])
                {
                    continue;
                }
                v.push_back(a[i]&1);
            }
            int flag=0;
            int temp;
            long long count=1;
            double sum=0.0;
            for(i=0;i<v.size();i++)
            {
                if((i!=0)&&(v[i]!=v[i-1]))
                {
                    flag=1;
                }
                if(v[i])
                {
                    temp=-1;
                }
                else
                {
                    temp=1;
                }
                if(flag)
                {
                    count=count<<1;
                }
                sum=sum+(1.0*(temp*1.0)/count);
            }
            ans+=sum;
        }
        if(ans==0.0)
        {
            printf("DON'T PLAY\n");
        }
        else if(ans>0.0)
        {
            printf("EVEN\n");
    	}
		else
        {
            printf("ODD\n");
        }
    }
    return 0;
}
