package R788;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Created on 2022-07-17 16:41:20
 * 
 * @author macinchang
 */
public class B {

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
        Scanner sc;

        Solver(Scanner sc) {
            this.sc = sc;
        }

        public void solve() throws IOException {
            int n = sc.nextInt();
            char[] s = sc.next().toCharArray();
            int m = sc.nextInt();
            boolean[] mask = new boolean[26];
            char[] letters = new char[2];
            for (int i = 0; i < m; i++) {
                letters = sc.next().toCharArray();
                if (letters[0] < 'a' || letters[0] > 'z') {
                    continue;
                }
                mask[letters[0] - 'a'] = true;
            }
            int ans = 0;
            int last = 0;
            for (int i = 1; i < s.length; i++) {
                if (mask[s[i] - 'a']) {
                    ans = Math.max(i - last, ans);
                    last = i;
                }
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
