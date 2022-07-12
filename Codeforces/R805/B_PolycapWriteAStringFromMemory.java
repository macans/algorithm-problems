package R805;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-10 22:33:23
 * 
 * @author macinchang
 */
public class B_PolycapWriteAStringFromMemory {

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
            char[] s = scanner.next().toCharArray();
            int n = s.length;
            char[] mask = new char[3];
            int cnt = 0;
            int ans = 1;
            for (int i = 0; i < n; i++) {
                if (inMemory(mask, s[i])) {
                    continue;
                }
                if (cnt < 3) {
                    mask[cnt++] = s[i];
                } else {
                    cnt = 0;
                    ans++;
                    mask[1] = 0;
                    mask[2] = 0;
                    mask[cnt++] = s[i];
                }
            }
            System.out.println(ans);
        }

        boolean inMemory(char[] mask, char ch) {
            return mask[0] == ch || mask[1] == ch || mask[2] == ch;
        }
    }
}
