package R793;

import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 20:41:21
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
            int n = sc.nextInt();
            int[] a = new int[n], b = new int[n];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            Arrays.sort(a);
            for (int i = 0, j = 0; j < n - 1; i++) {
                b[i] = a[j++];
                b[n - i - 1] = a[j++];
            }
            if (n % 2 != 0) {
                b[n / 2] = a[n - 1];
            }
            int last = Integer.MIN_VALUE, cnt1 = 0;
            for (int i = 0; i <= (n - 1) / 2; i++) {
                if (b[i] > last) {
                    ++cnt1;
                    last = b[i];
                }
            }
            last = Integer.MIN_VALUE;
            int cnt2 = 0;
            for (int i = n - 1; i > (n - 1) / 2; i--) {
                if (b[i] > last) {
                    ++cnt2;
                    last = b[i];
                }
            }
            System.out.println(Math.min(cnt1, cnt2));
        }
    }
}
