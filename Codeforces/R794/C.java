package R794;

import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 16:50:21
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
            int[] a = new int[n];
            int[] b = new int[n + 5];
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextInt();
            }
            if (n % 2 == 1) {
                System.out.println("NO");
                return;
            }
            Collections.shuffle(Arrays.asList(a));
            Arrays.sort(a);
            int k = 0;
            for (int i = 0, j = n / 2; i < n / 2 && j < n; i++, j++) {
                b[k++] = a[i];
                b[k++] = a[j];
            }

            if (b[0] >= b[n - 1]) {
                System.out.println("NO");
                return;
            }

            for (int i = 1; i < n - 1; i++) {
                if (b[i] > b[i - 1] && b[i] > b[i + 1]) {
                    continue;
                }
                if (b[i] < b[i - 1] && b[i] < b[i + 1]) {
                    continue;
                }
                System.out.println("NO");
                return;
            }

            System.out.println("YES");
            for (int i = 0; i < n; i++) {
                System.out.print(b[i] + " ");
            }
            System.out.println();
        }
    }
}
