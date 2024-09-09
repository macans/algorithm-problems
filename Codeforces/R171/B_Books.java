package R171;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Created on 2024-09-09 01:34:18
 * 
 * @author macinchang
 */
public class B_Books {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            scanner = new Scanner("in.txt");
        } else {
            scanner = new Scanner(System.in);
        }
        Solver solver = new Solver(scanner);
        solver.solve();

    }

    public static class Solver {
        private Scanner sc;

        Solver(Scanner sc) {
            this.sc = sc;
        }

        public void solve() throws IOException {
            int n = sc.nextInt(), t = sc.nextInt();
            int cur = 0;
            int ans = 0;
            int left = 0;
            int[] books = new int[n];
            for (int i = 0; i < n; i++) {
                books[i] = sc.nextInt();
                if (books[i] + cur <= t) {
                    cur += books[i];
                    continue;
                }
                ans = Math.max(ans, i - left);
                cur += books[i];
                while (cur > t) {
                    cur -= books[left];
                    ++left;
                    if (left > i) {
                        break;
                    }
                }
            }
            if(cur <= t) {
                ans = Math.max(ans, n - left);
            }
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
