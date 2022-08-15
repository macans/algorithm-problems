package R793;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Created on 2022-07-23 20:41:21
 * 
 * @author macinchang
 */
public class C_LISOrReverseLIS {

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

        public void solve() throws Exception {
            int n = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Arrays.sort(a);
            int ans = 0;
            int cnt = 1;
            int odd = 0;
            for (int i = 1; i <= n; i++) {
                if (i != n && a[i] == a[i - 1]) {
                    ++cnt;
                    continue;
                }
                if (cnt >= 2) {
                    ans += 1;
                }
                if (cnt == 1) {
                    odd++;
                }
                cnt = 1;
            }
            ans += (odd + 1) / 2;
            System.out.println(ans);
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
