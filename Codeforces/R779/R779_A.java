package R779;
import java.util.Scanner;

/**
 * @author macinchang
 *         Created on 2022-03-27 22:27:38
 */

public class R779_A {

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
            scanner.nextInt();
            String s = scanner.next();
            int ans = 0;
            for (int i = 0; i < s.length() - 2; i++) {
                if (s.charAt(i) == '0' && s.charAt(i + 1) == '1'
                        && s.charAt(i + 2) == '0') {
                    ans += 1;
                }
            }
            for (int i = 0; i < s.length() - 1; i++) {
                if (s.charAt(i) == '0' && s.charAt(i+1) == '0') {
                    ans += 2;
                }
            }
            System.out.println(ans);
        }
    }
}
