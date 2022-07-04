package R306;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-17 23:11:32
 * 
 * @author macinchang
 */
public class TwoSubstrings {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            File inFile = new File("in.txt");
            scanner = new Scanner(inFile);
        } else {
            scanner = new Scanner(System.in);
        }

        new Solver().solve(scanner);

        scanner.close();
    }

    public static class Solver {
        public void solve(Scanner scanner) {
            String str = scanner.next();
            char[] s = str.toCharArray();
            int n = s.length;
            int ab1 = -1, ba1 = -1;
            for (int i = 1; i < n; i++) {
                if (ab1 < 0 && s[i - 1] == 'A' && s[i] == 'B') {
                    ab1 = i - 1;
                }
                if (ba1 < 0 && s[i - 1] == 'B' && s[i] == 'A') {
                    ba1 = i - 1;
                }
            }
            int ab2 = -1, ba2 = -1;
            for (int i = n - 2; i >= 0; i--) {
                if (ab2 < 0 && s[i] == 'A' && s[i + 1] == 'B') {
                    ab2 = i;
                }
                if (ba2 < 0 && s[i] == 'B' && s[i + 1] == 'A') {
                    ba2 = i;
                }
            }
            boolean yes = false;
            if (ab1 >= 0 && ba1 >= 0 && Math.abs(ab1 - ba1) > 1) {
                yes = true;
            }
            if (ab2 >= 0 && ba2 >= 0 && Math.abs(ab2 - ba2) > 1) {
                yes = true;
            }
            if (ab1 >= 0 && ba2 >= 0 && Math.abs(ab1 - ba2) > 1) {
                yes = true;
            }
            if (ba1 >= 0 && ab2 >= 0 && Math.abs(ba1 - ab2) > 1) {
                yes = true;
            }
            System.out.println(yes ? "YES" : "NO");
        }
    }
}
