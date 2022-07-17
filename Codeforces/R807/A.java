package R807;

import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-15 21:25:11
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
        while (t-- > 0) {
            new Solver().solve(scanner);
        }
        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            int n = scanner.nextInt(), x = scanner.nextInt();
            int[] a = new int[n << 1];
            for (int i = 0; i < (n << 1); i++) {
                a[i] = scanner.nextInt();
            }
            Arrays.sort(a);
            boolean fault = false;
            for (int i = 0; i < n; i++) {
                if (a[i + n] - a[i] < x) {
                    fault = true;
                    break;
                }
            }
            System.out.println(fault ? "NO" : "YES");
        }
    }
}