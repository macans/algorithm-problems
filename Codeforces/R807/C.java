package R807;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-15 21:25:11
 * 
 * @author macinchang
 */
public class C {

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
            int n = scanner.nextInt(), c = scanner.nextInt(), t = scanner.nextInt();
            char[] s = scanner.next().toCharArray();
            long[] lens = new long[c + 1];
            long[][] copy = new long[c + 1][3];
            lens[0] = s.length;

            for (int i = 1; i <= c; i++) {
                copy[i][0] = scanner.nextLong();
                copy[i][1] = scanner.nextLong();
                lens[i] = (copy[i][1] - copy[i][0] + 1) + lens[i - 1];
            }

            while (t-- > 0) {
                long x = scanner.nextLong();
                while (x > n) {
                    int pos = search(lens, x);
                    // x 在第 pos 次 copy 时生成，找到 copy 来源的位置知道位于原字符串
                    x = copy[pos][0] + x - lens[pos - 1] - 1;
                }
                System.out.println(s[(int) (x - 1)]);
            }
        }

        int search(long[] a, long key) {
            int left = 0, right = a.length - 1;
            while (left < right) {
                int mid = (left + right) >> 1;
                if (a[mid] >= key) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        }
    }
}