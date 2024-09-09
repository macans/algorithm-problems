package R725;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

/**
 * Created on 2022-08-26 01:51:57
 * 
 * @author macinchang
 */
public class InterestingFunction {

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
            long a = sc.nextLong(), b = sc.nextLong();
            long total_dis = b - a;
            long mod = 1000000000L, unit = 10L;
            long ans = 0;
            long cur_dis = 0;
            while(mod >= 10) {
                if(b / mod == 0) {
                    mod /= 10;
                    unit--;
                    continue;
                }
                long dis = (b / mod - a / mod) - cur_dis;
                ans += dis * unit;
                cur_dis += dis;
                mod /= 10;
                unit--;
            }
            System.out.println(ans + (total_dis - cur_dis));
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
