import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
 
/**
 *
 * @author ashish1610
 */
class MCHAIRS
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            int n;
            n=Integer.parseInt(br.readLine());
            BigInteger b = new BigInteger(Integer.toString(n));
            BigInteger ans = new BigInteger("2");
            BigInteger mod = new BigInteger("1000000007");
            BigInteger m = new BigInteger("1");
            BigInteger p = new BigInteger("0");
            ans=ans.modPow(b, mod);
            if(ans.equals(p))
            {
                System.out.println("1000000006");
            }
            else
            {
                ans=ans.subtract(m);
                System.out.println(ans);
            }
        }
    }
}
