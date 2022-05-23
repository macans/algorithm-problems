

import java.util.Scanner;

/**
 * @author macinchang
 *         Created on 2022-03-27 23:26:05
 */
public class R779_C {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
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
            int oneCnt = 0;
            int j = -1;
            for(int i = 0; i < n; i++) {
                a[i] = scanner.nextInt();
                if(a[i] == 1) {
                    oneCnt++;
                    j = i;
                }
            }
            if(oneCnt != 1) {
                System.out.println("NO");
                return;
            }
            String ans = "YES";
            int last = j, k = j;
            while(true) {
                k = k + 1 >= n ? 0 : k + 1;
                System.out.println(k + ", " + j);
                if(k == j) {
                    break;
                }
                if(a[k] - a[last] == 1 || a[k] < a[last]){
                    last = k;
                    continue;
                }
                ans = "NO";
                break;
            }
            System.out.println(ans);

        }
    }
}
