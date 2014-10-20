/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
class Main1 
{    
    public static long binary_search(long a[], long b, int n)
    {
	int first = 0;
	int last = n - 1;
   	int middle = (first+last)/2;
   	while( first <= last )
   	{
            if (a[middle] <= b)
            {
            	first = middle + 1;
            }
            else if(a[middle] > b)
            {
      		if(middle-1<0)
      		{
      			return middle;
      		}
      		else if(a[middle-1]<=b)
      		{
      			return middle;
      		}
      		else
                    last = middle - 1;
            }
            middle = (first + last)/2;
        }
   	return n+1;
    }
    
    public static void main(String[] args)throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        int t=Integer.parseInt(str);
        for(int a=0;a<t;++a)
        {
            int i,j,k,l;
            long count1=0,count2=0;
            double count=0;
            String str1=br.readLine();
            int n=Integer.parseInt(str1);
            long[] x=new long[n];
            long[] y=new long[n];
            String[] str2=br.readLine().split(" ");
            for(i=0;i<n;++i)
            {
                x[i]=Long.parseLong(str2[i]);
            }
            String[] str3=br.readLine().split(" ");
            for(j=0;j<n;++j)
            {
                y[j]=Long.parseLong(str3[j]);
                if(y[j]==1)
                {
                    count1++;
                }
                if(y[j]==2)
                {
                    count2++;
                }
            }
            if(n==4)
            {
                for(k=0;k<n;++k)
                {	
                    for(l=0;l<n;++l)
                    {
                        if((x[k]<=3)&&(y[l]<=3)||((x[k]==2)&&(y[l]==4))||((x[k]==4)&&(y[l]==2)))
			{
                            if(Math.pow(x[k],y[l]) > Math.pow(y[l],x[k]))
                            {
                                count++;
                            }
                        }
                        else
                        {
                            if(x[k]<y[l])
                            {
                                count++;
                            }
			}
                    }
		}
            }
            else
            {
                Arrays.sort(y);
                int u;
                long v;
                for(u=0;u<n;++u)
                {
                    if(x[u]==1)
                    {
                        continue;
                    }
                    else if(x[u]==2)
                    {
                        v=binary_search(y,x[u]+2,n);
                        if(v!=n+1)
                        {
                            count=count+(n-v);
                        }
                        count=count+count1;
                    }
                    else if(x[u]==3)
                    {
                        v=binary_search(y,x[u],n);
			if(v!=n+1)
			{
                            count=count+(n-v);
                        }
			count=count+count2+count1;
                    }
                    else
                    {
                        v=binary_search(y,x[u],n);
			if(v!=n+1)
			{
                            count=count+(n-v);
			}
			count=count+count1;
                    }
                }
            }
            double ans;
            ans=count/n;
            System.out.printf("%.6f\n",ans);
        }
    }
} 
