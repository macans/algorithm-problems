package R793;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 20:41:21
 * 
 * @author macinchang
 */
public class B {

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
            int n = sc.nextInt();
            int ans = (1 << 20) - 1;
            for (int i = 0; i < n; i++) {
                int x = sc.nextInt();
                if (x == i) {
                    continue;
                }
                ans &= x;
            }

            System.out.println(ans);
        }
    }
}
