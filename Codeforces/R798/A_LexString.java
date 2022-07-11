package R798;

import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-11 18:49:32
 * 
 * @author macinchang
 */
public class A_LexString {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        while (t-- > 0) {
            new Solver(scanner).solve();
        }
        scanner.close();
    }

    public static class Solver {
        private Scanner scanner;

        Solver(Scanner scanner) {
            this.scanner = scanner;
        }

        public void solve() {
            int n, m, k;
            n = scanner.nextInt();
            m = scanner.nextInt();
            k = scanner.nextInt();
            char[] a = scanner.next().toCharArray();
            char[] b = scanner.next().toCharArray();
            Arrays.sort(a);
            Arrays.sort(b);
            char[] res = new char[n + m];
            int p = 0, q = 0;
            boolean first = a[0] < b[0] ? true : false;
            int i;
            for (i = 0; i < n + m && p < n && q < m;) {
                res[i++] = first ? a[p++] : b[q++];
                for (int j = 1; j < k && p < n && q < m; j++) {
                    if (first && a[p] < b[q]) {
                        res[i++] = a[p++];
                        continue;
                    } else if (!first && b[q] < a[p]) {
                        res[i++] = b[q++];
                        continue;
                    } else {
                        break;
                    }
                }
                first = !first;
            }
            System.out.println(Arrays.copyOfRange(res, 0, i));
        }
    }

}
