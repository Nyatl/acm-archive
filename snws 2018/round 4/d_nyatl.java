import java.io.*;
import java.util.*;
import java.math.*;

public class d_nyatl {

	private static final int MAX = 10;

	int n = 3;
	int[] h = new int[MAX];
	int[] m = new int[MAX];
	int k;

	int t[] = new int[MAX];
    
	public void solve(Input in, PrintWriter out) throws IOException {
		for (int i = 1; i <= n; i++) {
			h[i] = in.nextInt();
			m[i] = in.nextInt();
		}
		k = in.nextInt();
			
		for (int i = 1; i <= n; i++) {
			t[i] = h[i] * 60 + m[i];
		}
	
		BigDecimal ans = new BigDecimal(t[1] * t[2] * t[3]);
		ans = ans.divide(new BigDecimal(60 * (t[1] * t[2] + t[1] * t[3] + t[2] * t[3])), k, BigDecimal.ROUND_HALF_UP);
		out.println(ans);
	}

	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter("output.txt");
		new d_nyatl().solve(new Input(new BufferedReader(new FileReader("input.txt"))), out);
		out.close();
	}

	static class Input {

		BufferedReader in;
		StringBuilder sb = new StringBuilder();

		public Input(BufferedReader in) {
			this.in = in;
		}

		public Input(String s) {
			this.in = new BufferedReader(new StringReader(s));
		}

		public String next() throws IOException {
			sb.setLength(0);
			while (true) {
				int c = in.read();
				if (c == -1) {
					return null;
				}
				if (" \n\r\t".indexOf(c) == -1) {
					sb.append((char) c);
					break;
				}
			}
			while (true) {
				int c = in.read();
				if (c == -1 || " \n\r\t".indexOf(c) != -1) {
					break;
				}
				sb.append((char) c);
			}
			return sb.toString();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public double nextDouble() throws IOException {
			return Double.parseDouble(next());
		}
	}
}
