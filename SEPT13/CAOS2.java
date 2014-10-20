/**
 *
 * @author ashish1610
 */
import java.io.BufferedReader;
import java.io.InputStreamReader;
class CAOS2
{
    public static void main(String[] args) throws Exception
    {
        int ar[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499};
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String c = br.readLine();
        int t = Integer.parseInt(c);
        int i;
        for(i=0;i<t;++i)
        {
            String [] d = br.readLine().split(" ");
            int R = Integer.parseInt(d[0]);
            int C = Integer.parseInt(d[1]);
            char [][] ch = new char[R][C];
            int j,k,count=0;
            for(j=0; j<R; ++j)
            {
                String str = br.readLine();
                
                //for(k=0; k<C; ++k)
                //{
                    ch[j] = str.toCharArray();
                //}
            }
            int l,m,p;
            for(l=2; l<R-2;++l)
            {
                for(m=2; m<C-2; ++m)
                {
                    int min=0;
                    if(ch[l][m]=='^')
                    {
   			for(p=1; p<=500; ++p)
   			{
                            if(m-p>=0 && l-p>=0 && l+p<R && m+p<C && ch[l][m-p]=='^' && ch[l-p][m]=='^' && ch[l+p][m]=='^' && ch[l][m+p]=='^')
                            {
                                min++;
                            }
                            else
                                break;
   			}
   			int bc = 0;
                        while(ar[bc]<=min)
   			{
                            count++;
                            bc++;
                        }
                    }
                    else
                    {
   			m+=2;
                    }
                }
            }
            System.out.println(count);
        }
    }  
}
