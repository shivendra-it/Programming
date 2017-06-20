
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Problem2 {
	public static void main(String[] args){
		FastScanner sc = new FastScanner();
		int n = sc.nextInt();
		int t = sc.nextInt();
		
		int maxBooks = 0;
		long time = 0;
		int[] a = new int[n];
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
		}
		
		int curRightBook = 0;
		int curLeftBook = 0;
		//inv: start of loop, read til curLeftBook..curBook-1
		//total time = curLeftBook ... curRightBook-1
		while(curRightBook < n){
			time += a[curRightBook];
			while(time > t){
				time -= a[curLeftBook];
				curLeftBook++;
			}
			
			maxBooks = Math.max(maxBooks, (curRightBook-curLeftBook+1));
			
			curRightBook++;
		}
		
		System.out.println(maxBooks);
	}
	
	public static class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(String s) {
			try {
				br = new BufferedReader(new FileReader(s));
			} catch (FileNotFoundException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}
}