/**
 *
 * @author ashish1610
 */
import java.util.Scanner;
class COOLGUYS 
{
    public static long gcd(long a, long b)
    {
        if(b <= a && a%b == 0)
		return b;
	if(a < b)
		return gcd(b,a);
	else
		return gcd(b,a%b);
    }
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        long t = s.nextLong();
        long i;
        for(i=0; i<t; ++i)
        {
            long n,k,j,l,count=0;
            n=s.nextLong();
            for(k=n/(int)Math.sqrt(n); k>1; --k)
            {
		count+=(n/k);
            }
            for(l=1;l<(int)Math.sqrt(n); ++l)
            {
		count+=(n/l-n/(l+1))*l;
            }
            count+=n;
            j=gcd(count, n*n);
            count/=j;
            System.out.println(count+"/"+(n*n)/j);
        }
    }
}
