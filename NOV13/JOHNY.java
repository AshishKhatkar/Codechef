import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
 
/**
 *
 * @author ashish1610
 */
class JOHNY 
{
    public static void main(String[] args) throws Exception
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            int n = Integer.parseInt(br.readLine());
            long[] ar = new long[n];
            String[] str = br.readLine().split(" ");
            for(int i=0;i<n;++i)
            {
                ar[i]=Long.parseLong(str[i]);
            }
            int k = Integer.parseInt(br.readLine()),ans=0;
            long to_find = ar[k-1];
            Arrays.sort(ar);
            for(int i=0;i<n;++i)
            {
                if(ar[i]==to_find)
                {
                    ans=i;
                }
            }
            ans+=1;
            System.out.println(ans);
        }
    } 
}
