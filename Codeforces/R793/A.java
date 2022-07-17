package R793;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-16 20:41:21
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
            char[] s = sc.next().toCharArray();
            int ans = 0;
            int left = n % 2 == 1 ? n / 2 : n / 2 - 1;
            for (int i = left - 1; i >= 0; i--) {
                if (s[i] == s[left]) {
                    ++ans;
                } else {
                    break;
                }
            }
            int right = n / 2;
            for (int i = right + 1; i < n; i++) {
                if (s[i] == s[right]) {
                    ++ans;
                } else {
                    break;
                }
            }
            if (n % 2 == 1) {
                ++ans;
            } else {
                ans += 2;
            }

            System.out.println(ans);
        }
    }
}
