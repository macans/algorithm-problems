package R802;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-19 23:36:41
 * 
 * @author macinchang
 */
public class HelpingTheNature {

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
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
            }
            long ans = 0;
            for(int i = 1; i < n; i++) {
                ans += Math.abs(a[i] - a[i - 1]);
            }
            long r = (ans + a[n - 1] - a[0]) / 2;
            
            System.out.println(ans + Math.abs(a[n - 1] - r));
        }
    }
}
