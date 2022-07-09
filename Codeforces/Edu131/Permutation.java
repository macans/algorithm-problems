package Edu131;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-08 22:33:24
 * 
 * @author macinchang
 */
public class Permutation {

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
            int n = scanner.nextInt();
            int[] a = new int[n];
            boolean[] mark = new boolean[n + 1];
            int j = 0;
            for (int i = 1; i <= n; i++) {
                if (mark[i]) {
                    continue;
                }
                a[j++] = i;
                int k = i;
                while (k * 2 <= n) {
                    a[j++] = k * 2;
                    mark[k * 2] = true;
                    k <<= 1;
                }
                if (j >= n) {
                    break;
                }
            }
            System.out.println(2);
            for (int i = 0; i < n; i++) {
                System.out.print(a[i] + " ");
            }
            System.out.println();

        }
    }
}
