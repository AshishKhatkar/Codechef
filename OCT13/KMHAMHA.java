/*
*@author: ashish1610
*/
import java.util.ArrayList;
import java.util.HashMap;
import java.io.BufferedReader;
import java.io.InputStreamReader;
 
class KMHAMHA
{	
	private static final int MAXN1 = 1000002;
	private static final int MAXN2 = 1000002;
	private static final int MAXM = 1000002;
 
	private static ArrayList<Integer> x=new ArrayList<Integer>();
	private static ArrayList<Integer> y=new ArrayList<Integer>();
	private static HashMap<Integer,Integer> last=new HashMap<Integer,Integer>();
	private static HashMap<Integer,Integer> matching=new HashMap<Integer,Integer>();
	private static HashMap<Integer,Integer> dist=new HashMap<Integer,Integer>();
	private static HashMap<Integer,Boolean> used=new HashMap<Integer,Boolean>();
	private static HashMap<Integer,Boolean> vis=new HashMap<Integer,Boolean>();
	private static int n1, n2;
	private static int edges;
	private static int[] prev=new int[MAXM];
	private static int[] head=new int[MAXM];
	private static int[] Q=new int[MAXN1];
	public static void init(int _n1, int _n2) 
	{
		n1 = _n1;
		n2 = _n2;
		edges = 0;
		x.clear();
		y.clear();
		last.clear();
		matching.clear();
		dist.clear();
		used.clear();
		vis.clear();
	}
 
	public static void addEdge(int u, int v) 
	{
		if(!x.contains(u))
		x.add(u);
		if(!y.contains(v))
		y.add(v);
		head[edges] = v;
		if(!last.containsKey(u))
		last.put(u,-1);
		prev[edges] = last.get(u);
		last.put(u,edges++);
	}
 
	public static void bfs() 
	{
		for(Integer it:x)
		dist.put(it,-1);
		int sizeQ = 0;
		for (Integer it:x) 
		{
			if (!used.get(it)) 
			{
				Q[sizeQ++] = it;
				dist.put(it, 0);
			}
		}
		for (int i = 0; i < sizeQ; i++) 
		{
			int u1 = Q[i];
			for (int e = last.get(u1); e >= 0; e = prev[e]) 
			{
				int u2 = matching.get(head[e]);
				if (u2 >= 0 && dist.get(u2) < 0) 
				{
					dist.put(u2, (dist.get(u1)+1));
					Q[sizeQ++] = u2;
				}
			}
		}
	}	 
	public static boolean dfs(int u1) 
	{
		vis.put(u1, true);
		for (int e = last.get(u1); e >= 0; e = prev[e]) 
		{
			int v = head[e];
			int u2 = matching.get(v);
			if (u2 < 0 || !vis.get(u2) && dist.get(u2) == (dist.get(u1) + 1) && dfs(u2)) 
			{
				matching.put(v, u1);
				used.put(u1,true);
				return true;
			}
		}
		return false;
	}
	public static int maxMatching() 
	{
		for(Integer it:x)
			used.put(it, false);
		for(Integer it:y)
			matching.put(it, -1);
		for (int res = 0;;) 
		{
			bfs();
			for(Integer it:x)
				vis.put(it, false);
			int f = 0;
			for(Integer it:x)
				if (!used.get(it) && dfs(it))
					++f;
			if (f==0)
				return res;
			res += f;
		}
	}
	public static void main(String[] args) throws Exception
	{
		int t;
		int a,b,n,i;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		t=Integer.parseInt(br.readLine());
		while(t--!=0)
		{
			n=Integer.parseInt(br.readLine());
			init(n,n);
			for(i=0;i<n;++i)
			{
				String [] str=br.readLine().split(" ");
				a=Integer.parseInt(str[0]);
				b=Integer.parseInt(str[1]);
				addEdge(a,b);
			}
			System.out.println(maxMatching());
		}
	}
}
