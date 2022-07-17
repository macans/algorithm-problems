package R808;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 22:34:23
 * 
 * @author macinchang
 */
public class C {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        Solver solver = new Solver(scanner);
        while (t-- > 0) {
            solver.solve();
        }
        scanner.close();
    }

    public static class Solver {
        private Scanner sc;

        Solver(Scanner scanner) {
            this.sc = scanner;
        }

        public void solve() {
            int n = sc.nextInt(), q = sc.nextInt();
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            int cur = 0, ans = 0;
            StringBuffer res = new StringBuffer();
            for (int i = n - 1; i >= 0; i--) {
                if (a[i] <= cur) {
                    ++ans;
                    res.append("1");
                } else if (cur < q) {
                    ++ans;
                    ++cur;
                    res.append("1");
                } else {
                    res.append("0");
                }
            }
            System.out.println(res.reverse().toString());
        }
    }
}
