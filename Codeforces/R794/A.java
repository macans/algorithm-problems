package R794;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 16:12:38
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
            int n = sc.nextInt();
            int sum = 0;
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
                sum += a[i];
            }
            if (sum % n != 0) {
                System.out.println("NO");
                return;
            }
            for (int i = 0; i < n; i++) {
                if (a[i] == (sum / n)) {
                    System.out.println("YES");
                    return;
                }
            }
            System.out.println("NO");
        }
    }
}
