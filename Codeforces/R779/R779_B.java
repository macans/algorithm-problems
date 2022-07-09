package R779;

 
import java.util.Scanner;

/**
 * @author macinchang
 * Created on  2022-03-27 22:49:14 
 */
public class R779_B {

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
            if(n % 2 == 1) {
                System.out.println(0);
                return;
            }
            long mod = 998244353L;
            long ans = 1;
            for(int i = 2; i <= n/2; i++ ) {
                ans = (ans * i) % mod;
            }
            System.out.println((ans * ans) % mod);
        }
    }
}
