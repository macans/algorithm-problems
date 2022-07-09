package Edu131;

import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-08 22:33:24
 * 
 * @author macinchang
 */
public class ScheduleManagement {

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
            int n = scanner.nextInt(), m = scanner.nextInt();
            int[] cnt = new int[n];
            for (int i = 0; i < m; i++) {
                cnt[scanner.nextInt() - 1]++;
            }
            Arrays.sort(cnt);
            int left = 0, right = 2 * m;
            while (left < right) {
                int mid = (left + right) >> 1;

                int[] actual = new int[n];
                for (int i = 0; i < n; i++) {
                    actual[i] = cnt[n - i - 1];
                }
                boolean flag = true;
                int j = 1;
                for (int i = 0; i < n; i++) {
                    while (actual[i] > mid && j < n) {
                        if (actual[j] < mid) {
                            int tmp = Math.min((mid - actual[j]) / 2, actual[i] - mid);
                            actual[j] += tmp * 2;
                            actual[i] -= tmp;
                        }
                        if (actual[i] > mid) {
                            ++j;
                        }
                    }
                    if (actual[i] > mid) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            System.out.println(left);
        }
    }
}
