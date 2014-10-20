import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
 
/**
 *
 * @author ashish1610
 */
class SPOTWO 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            int n=Integer.parseInt(br.readLine());
            BigInteger b = new BigInteger(Integer.toBinaryString(n));
            BigInteger ans = new BigInteger("2");
            BigInteger mod = new BigInteger("1000000007");
            BigInteger a = new BigInteger("2");
            ans=ans.modPow(b,mod);
            ans=ans.modPow(a,mod);
            System.out.println(ans);
        }
    }
}
