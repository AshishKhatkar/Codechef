/**
 *
 * @author ashish1610
 */
import java.io.*;
import java.math.*;
import java.util.*;
class MTRICK 
{
    public static void main(String[] args)throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int t=Integer.parseInt(br.readLine());
        while(t--!=0)
        {
            int n=Integer.parseInt(br.readLine());
            ArrayList<BigInteger> ar=new ArrayList();
            String[] str=br.readLine().split(" ");
            for(int i=0;i<n;++i)
            {
                ar.add(new BigInteger(str[i]));
            }
            String[] str1=br.readLine().split(" ");
            BigInteger a=new BigInteger(str1[0]);
            BigInteger b=new BigInteger(str1[1]);
            BigInteger c=new BigInteger(str1[2]);
            String inp=br.readLine();
            BigInteger add=new BigInteger("0");
            BigInteger mult=new BigInteger("1");
            int rev=0;
            boolean flag=true;
            BigInteger ans_to_print;
            for(int i=0;i<inp.length();++i)
            {
                if(inp.charAt(i)=='A')
                {
                    add=add.add(a).mod(c);
                    flag=true;
                }
                else if(inp.charAt(i)=='M')
                {
                    mult=mult.multiply(b).mod(c);
                    add=add.multiply(b).mod(c);
                    flag=true;
                }
                else if(inp.charAt(i)=='R')
                {
                    rev++;
                }
                if(rev%2==1)
                {
                    ans_to_print=ar.get(ar.size()-1);
                    ar.remove(ar.size()-1);
                }
                else
                {
                    ans_to_print=ar.get(0);
                    ar.remove(0);
                }
                if(flag)
                {
                    ans_to_print=ans_to_print.multiply(mult).mod(c);
                    ans_to_print=ans_to_print.add(add).mod(c);
                }
                System.out.print(ans_to_print+" ");
            }
            System.out.println();
        }
    }
}
