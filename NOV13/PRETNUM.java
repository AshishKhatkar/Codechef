import java.io.BufferedReader;
import java.io.InputStreamReader;
 
/**
 *
 * @author ashish1610
 */
class PRETNUM 
{
    public static final int max = 1000007;
    public static int[] temp_prime = {2,4,6,10,12,16,18,22,28,30,36,40,42,46};
    public static long[] ar = new long[max];
    public static long[] prime = new long[max];
    public static int k=0;
    public static void sieve_prime()
    {
        int i,j;
        ar[0]=1;
        ar[1]=1;
        for(i=2;i*i<max;++i)
        {
            if(ar[i]==0)
            {
                for(j=i*2;j<max;j+=i)
                {
                    ar[j]=1;
                }
            }
        }
        for(i=0;i<max;++i)
        {
            if(ar[i]==0)
            {
                prime[k++]=i;
            }
        }
    }
    public static void main(String[] args) throws Exception
    {
        sieve_prime();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            String[] str=br.readLine().split(" ");
            long l=Long.parseLong(str[0]);
            long r=Long.parseLong(str[1]);
            int[] pre_ans=new int[max];
            for(int i=0;i<max;++i)
            {
                pre_ans[i]=0;
            }
            long ans = 0;
            for(int i=0;prime[i]*prime[i]<=r;++i)
            {
                long less = l/prime[i];
                less*=prime[i];
                for(long j=less;j<=r;j+=prime[i])
                {
                    if(j>=l && j!=prime[i] && pre_ans[(int)(j-l)]!=2)
                    {
                        pre_ans[(int)(j-l)]=1;
                    }
                }
                long a=(int)Math.ceil(Math.log(l)/Math.log(prime[i]));
                long b=(int)Math.floor(Math.log(r)/Math.log(prime[i]));
                for(int p=0;p<14;++p)
                {
                    if(temp_prime[p]>=a && temp_prime[p]<=b)
                    {
                        long temp = (long)(Math.pow(prime[i],temp_prime[p]));
                        pre_ans[(int)(temp-l)]=2;
                    }
                    else if(temp_prime[p]>b)
                    {
                        break;
                    }
                }
            }
            for(int i=0;i<=r-l;++i)
            {
                if((pre_ans[i]==0 && (i+l)!=1) || (pre_ans[i]==2 && (i+l)!=1))
                {
                    ans+=1;
                }
            }
            System.out.println(ans);
        }
    }
}
