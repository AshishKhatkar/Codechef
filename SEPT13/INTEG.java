/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
class INTEG 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String t = br.readLine();
        int n=Integer.parseInt(t),i;
        long [] ar = new long[(int)n];
        int j,k;
        long neg_count=0,amount=0;
        String[] s = br.readLine().split(" ");
        for(i=0; i<n; ++i)
        {
            ar[i]=Long.parseLong(s[i]);
            if(ar[i]<0)
            {
                neg_count++;
            }
        }
        Arrays.sort(ar);
        int cost;
        String str = br.readLine();
        cost = Integer.parseInt(str);
        if(cost<neg_count)
        {
            for(j=0; j<cost; ++j)
            {
                amount-=ar[j];
            }
        }
        else
        {
            
            for(k=0; k<neg_count; ++k)
            {
                amount-=ar[k];
            }
        }
        System.out.println(amount);
    }  
}
