/*
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
class SEATRSF
{
    public static int check=1000000007;
    public static long solve(long x, long y)
    {
        if(y==1)
        {
            return x%check;        
        }
        long p;
        p=solve(x,y/2);
        p=(p*p)%check;
        if(y%2==1)
        {
            p=(p*x)%check;
        }
        return p;
    }
    public static void main(String[] args) throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        String str=br.readLine();
        int t=Integer.parseInt(str);
        int i;
        for(i=0;i<t;++i)
        {
            long n,m,q,k;
            String[] str1=br.readLine().split(" ");
            n=Long.parseLong(str1[0]);
            m=Long.parseLong(str1[1]);
            q=Long.parseLong(str1[2]);
            k=Long.parseLong(str1[3]);
            if(m<=q)
            {
                System.out.println(0);
            }
            else
            {
                long ans;
                ans=(solve(q+1,n) + solve(q-1,n) - 2*solve(q,n) + 2*check)%check;
                ans=((m-q)*ans)%check;
                System.out.println(ans);
            }
        }
    }
}
 
