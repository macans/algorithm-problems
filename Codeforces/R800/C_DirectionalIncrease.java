package R800;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-16 22:30:30
 * 
 * @author macinchang
 */
public class C_DirectionalIncrease {

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
            int x;
            long rightTimes = 0L;
            String ans = "YES";
            for (int i = 0; i < n; i++) {
                x = scanner.nextInt();
                if (i != 0 && rightTimes == 0 && x != 0) {
                    ans = "NO";
                }
                rightTimes += x;
                if (rightTimes < 0) {
                    ans = "NO";
                }

            }
            if (rightTimes != 0) {
                ans = "NO";
            }
            System.out.println(ans);
        }
    }
}
