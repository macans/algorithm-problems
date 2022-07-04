package R796;

import java.io.File;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Created on 2022-06-03 22:58:42
 * 
 * @author macinchang
 */
public class B {

    public static void main(String[] args) throws Exception {
        File inFile = new File("/Users/zhangji05/Code/algorithm-problems/in.txt");
        Scanner scanner = new Scanner(inFile);
        // Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        while (t-- > 0) {
            new Solver().solve(scanner);
        }
        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            int n = scanner.nextInt();
            int a[] = new int[n];
            int x, k;
            for (int i = 0; i < n; i++) {
                x = scanner.nextInt();
                k = 0;
                while (x % 2 == 0) {
                    k++;
                    x >>= 1;
                }
                a[i] = k;
                System.out.println(a[i]);
            }

            Arrays.sort(a);
            long ans = 0;
            int left = 0, right = n - 1;
            while (left <= right) {
                if (a[right] == 0) {
                    --right;
                    continue;
                }
                if (a[left] == 0) {
                    ++ans;
                    ++left;
                    --right;
                }
                if (a[left] > 0) {
                    ans += (1 << a[left]) - 1;
                    int originRight = right;
                    right = Math.max(left, right - (1 << a[left]));
                    ans += originRight - right;
                    ++left;
                }
            }

            System.out.println(ans);
        }
    }
}
