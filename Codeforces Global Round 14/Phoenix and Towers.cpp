import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Try2{
	static final int Mod = 100_000_0007;
	public static void main(String[] args) throws IOException {
		FastScanner fs = new FastScanner();
		int t= fs.nextInt();

		while(t-->0) {
			
			int n = fs.nextInt();
			int m = fs.nextInt();
			int x = fs.nextInt();
			
			System.out.println("YES");
			
			ArrayList<int[]> a = new ArrayList<int[]>();
			for(int i =0;i<n;i++) {
				a.add(new int[]{fs.nextInt(),i,-1});
			}
			
			
			Collections.sort(a,(y,z)->y[0]-z[0]);
			
			int ans[] = new int[n];
			
			for(int i =0 ;i<n;i++) {
				
				ans[a.get(i)[1]] = i%m+1; 
			}
			
			
			
			
			for(int i =0 ;i<n;i++) {
				System.out.print(ans[i]+ " ");
			}
			
			System.out.println();
		}
	}
	


static class Pair implements Comparable<Pair> {
    Integer value;
    Integer index;

    public Pair(Integer value, Integer index) {
        this.value = value;
        this.index = index;
    }

    @Override
    public int compareTo(Pair o) {
        return value - o.value;
    }
}

	
	static final Random random = new Random();

	static void ruffleSort(int[] a) {
		int n = a.length;// shuffle, then sort
		for (int i = 0; i < n; i++) {
			int oi = random.nextInt(n), temp = a[oi];
			a[oi] = a[i];
			a[i] = temp;
		}
		Arrays.sort(a);
	}

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

}
