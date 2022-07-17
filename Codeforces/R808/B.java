package R808;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 22:34:16
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
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }

            for (int i = 1; i < n; i++) {
                if (a[i] % a[0] != 0) {
                    System.out.println("NO");
                    return;
                }
            }
            System.out.println("YES");

        }
    }
}
