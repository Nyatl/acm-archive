import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.util.StringTokenizer;

public class Main {

    public static boolean DEBUG = false;
    public static String FILE_NAME = "nocow";
    public static String IN_FILE_NAME = FILE_NAME + ".in";
    public static String OUT_FILE_NAME = FILE_NAME + ".out";
    public static String DEBUG_IN_FILE_NAME = "input.txt";
    public static String DEBUG_OUT_FILE_NAME = "output.txt";
    public static PrintWriter out = new PrintWriter(System.out);
    public static InputReader in = new InputReader(System.in);

    public static void main(String[] args) throws IOException {
//        if (args.length > 0 && "DEBUG".equals(args[0])) {
//            DEBUG = true;
//        }

//        if (DEBUG) {
//            try {
//                in = new InputReader(new FileInputStream(DEBUG_IN_FILE_NAME));
//                out = new PrintWriter(new File(DEBUG_OUT_FILE_NAME));
//            } catch (FileNotFoundException ex) {
//                throw new RuntimeException(ex);
//            }
//        } else {
//            try {
//                in = new InputReader(new FileInputStream(IN_FILE_NAME));
//                out = new PrintWriter(new File(OUT_FILE_NAME));
//            } catch (FileNotFoundException ex) {
//                throw new RuntimeException(ex);
//            }
//        }

        new Solver().solve(in, out);
        out.flush();
    }

    static class Solver {

        public void solve(InputReader in, PrintWriter out) {
            int m1 = in.nextInt() * 60 + in.nextInt();
            int m2 = in.nextInt() * 60 + in.nextInt();
            int m3 = in.nextInt() * 60 + in.nextInt();

            int n = in.nextInt();

            int a = m1 * m2 + m2 * m3 + m3 * m1;
            int b = m1 * m2 * m3;
            BigDecimal p = BigDecimal.valueOf(a * 60);
            BigDecimal q = BigDecimal.valueOf(b);

            BigDecimal ans = q.divide(p, n, BigDecimal.ROUND_HALF_UP);
            out.println(ans.toPlainString());
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
    }

}
