import java.io.BufferedReader;
import java.io.InputStreamReader;
/**
 *
 * @author ashish1610
 */
class SDSQUARE 
{
    public static int[] ar = new int[100010];
    public static int check(long n)
    {
        int t=1;
        long rem;
        while(n!=0)
        {
            rem=n%10;
            if(rem==0 || rem==1 || rem==4 || rem==9)
            {
		n/=10;
            }
            else
            {
		t=0;
		break;
            }
        }
        return t;
    }
    public static void compute()
    {
        ar[0]=1;
        ar[1]=1;
        ar[2]=1;
        ar[3]=1;
        long i=4;
        while(i<=100000)
        {
            long p=i*i;
            ar[(int)i]=check(p);
            ++i;
        }
    }
    public static void main(String[] args) throws Exception
    {
        compute();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            long a,b,count=0,c,d;
            String[] str = br.readLine().split(" ");
            a = Long.parseLong(str[0]);
            b = Long.parseLong(str[1]);
            c = (long)Math.sqrt(a);
            d = (long)Math.sqrt(b);
            //System.out.println(c+" "+d);
            long i=c;
            while(i<=d)
            {
                if(i*i>=a && i*i<=b)
                {
                    count+=ar[(int)i];
                }
                ++i;
            }
            System.out.println(count);
        }
    }
}
