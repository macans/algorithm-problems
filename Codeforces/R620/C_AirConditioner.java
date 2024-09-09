package R620;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;


/**
 * Created on 2022-08-28 01:09:44
 * 
 * @author macinchang
 */
public class C_AirConditioner {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            scanner = new Scanner("in.txt");
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        Solver solver = new Solver(scanner);
        while (t-- > 0) {
            solver.solve();
        }
    }

    public static class Solver {
        private Scanner sc;

        Solver(Scanner sc) {
            this.sc = sc;
        }

        public void solve() throws IOException {
            int n = sc.nextInt(), m = sc.nextInt();
            long[][] t = new long[105][3];
            for (int i = 0; i < n; i++) {
                t[i][0] = sc.nextLong();
                t[i][1] = sc.nextLong();
                t[i][2] = sc.nextLong();
            }
            Arrays.sort(t, new Comparator<long[]>() {
                public int compare(long[] a, long[] b) {
                    return Long.compare(a[0], b[0]);
                }
            });

            long[][] dp = new long[105][2];
            dp[0][0] = Math.max(m - t[0][0], t[0][1]);
            dp[0][1] = Math.min(m + t[0][0], t[0][2]);
            for (int i = 1; i < n; i++) {
                long times = t[i][0] - t[i - 1][0];
                dp[i][0] = Math.max(dp[i - 1][0] - times, t[i][1]);
                dp[i][1] = Math.min(dp[i - 1][1] + times, t[i][2]);
                if(dp[i][0] > t[i][2] || dp[i][1] < t[i][1]) {
                    System.out.println(i);
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");


        }
    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(String string) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(string));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}
