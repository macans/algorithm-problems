package R668;

import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-06-18 01:33:05
 * 
 * @author macinchang
 */
public class BalancedString {

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
            int k = scanner.nextInt();
            char[] s = scanner.next().toCharArray();
            int cnt0 = 0, cnt1 = 0, cntw = 0;
            int[] nextw = new int[n + 10];
            nextw[n] = -1;
            for (int i = n - 1; i >= 0; i--) {
                if (s[i] == '?') {
                    nextw[i] = i;
                } else {
                    nextw[i] = i == n - 1 ? -1 : nextw[i + 1];
                }
            }
            for (int i = 0; i < k; i++) {
                if (s[i] == '0') {
                    ++cnt0;
                } else if (s[i] == '1') {
                    ++cnt1;
                } else {
                    ++cntw;
                }
            }
            if (Math.abs(cnt0 - cnt1) > cntw) {
                System.out.println("NO");
                return;
            }

            if (cntw == Math.abs(cnt1 - cnt0)) {
                for (int i = nextw[0]; i < k && i != -1; i = nextw[i + 1]) {
                    if (s[i] != '?') {
                        continue;
                    }
                    if (cnt1 > cnt0) {
                        s[i] = '0';
                        ++cnt0;
                    } else {
                        s[i] = '1';
                        ++cnt1;
                    }
                }
                cntw = 0;
            }

            for (int i = k; i < n; i++) {
                if (s[i - k] == '0') {
                    --cnt0;
                } else if (s[i - k] == '1') {
                    --cnt1;
                } else {
                    --cntw;
                }
                if (s[i] == '0') {
                    ++cnt0;
                } else if (s[i] == '1') {
                    ++cnt1;
                } else {
                    ++cntw;
                }
                if (Math.abs(cnt1 - cnt0) > cntw) {
                    System.out.println("NO");
                    return;
                }
                if (cntw == Math.abs(cnt1 - cnt0)) {
                    for (int j = nextw[i - k + 1]; j <= i && j != -1; j = nextw[j + 1]) {
                        if (s[j] != '?') {
                            continue;
                        }
                        if (cnt1 > cnt0) {
                            s[j] = '0';
                            ++cnt0;
                        } else {
                            s[j] = '1';
                            ++cnt1;
                        }
                    }
                    cntw = 0;
                }
            }
            System.out.println("YES");
        }
    }
}
