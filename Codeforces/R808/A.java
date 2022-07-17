package R808;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 22:34:05
 * 
 * @author macinchang
 */
public class A {

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
            int n = sc.nextInt(), l = sc.nextInt(), r = sc.nextInt();
            int[] a = new int[n + 1];
            boolean f = false;
            for (int i = n; i >= 1; i--) {
                a[i] = i * ((l + i - 1) / i);
                if (a[i] > r) {
                    f = true;
                    break;
                }
            }
            if (f) {
                System.out.println("NO");
                return;
            }
            System.out.println("YES");
            for (int i = 1; i <= n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();

        }
    }
}
