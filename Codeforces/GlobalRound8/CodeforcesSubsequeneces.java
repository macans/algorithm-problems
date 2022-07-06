package globalround8;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-18 01:10:49
 * 
 * @author macinchang
 */
public class CodeforcesSubsequeneces {

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
            long n = scanner.nextLong();
            long cnt = 1;
            // codeforces
            int[] d = new int[10];
            for (int i = 0; i < 10; i++) {
                d[i] = 1;
            }
            int pos = -1;
            while (cnt < n) {
                pos = pos + 1 == 10 ? 0 : pos + 1;
                cnt = cnt / d[pos] * (d[pos] + 1);
                d[pos]++;
            }
            char[] s = new String("codeforces").toCharArray();
            StringBuilder ans = new StringBuilder();
            for (int i = 0; i < 10; i++) {
                for (int j = 0; j < d[i]; j++) {
                    ans.append(s[i]);
                }
            }
            System.out.println(ans);
            ;
        }
    }
}
