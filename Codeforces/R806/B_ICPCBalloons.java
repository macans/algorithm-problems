package R806;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-12 21:28:34
 * 
 * @author macinchang
 */
public class B_ICPCBalloons {

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
            char[] s = scanner.next().toCharArray();
            boolean[] mask = new boolean[26];
            int res = 0;
            for (int i = 0; i < s.length; i++) {
                if (mask[s[i] - 'A']) {
                    res++;
                } else {
                    res += 2;
                    mask[s[i] - 'A'] = true;
                }
            }
            System.out.println(res);
        }
    }
}
