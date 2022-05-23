
import java.io.File;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

/*
<https://codeforces.com/contest/1654/problem/C>

simulate the cut process, attention the exit condition to avoid time exceeding
*/
public class R778_C_Alice_and_the_Cake {
    public static void main(String[] args) throws Exception {
        File inFile = new File("/Users/zhangji05/Code/algorithm-problems/in.txt");
        Scanner scanner = new Scanner(inFile);
        //Scanner scanner = new Scanner(System.in);
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
            long[] num = new long[n];
            long[] cnt = new long[n];
            long sum = 0;
            for (int i = 0; i < n; i++) {
                a[i] = scanner.nextLong();
                sum += a[i];
            }
            Arrays.sort(a);
            int m = 1, k = 1;
            num[0] = a[0];
            for (int i = 1; i < n; i++) {
                if (a[i] != a[i - 1]) {
                    cnt[m - 1] = k;
                    k = 1;
                    num[m] = a[i];
                    ++m;
                    continue;
                }
                ++k;
            }
            cnt[m - 1] = k;
            String ans = "YES";
            PriorityQueue<Long> pq = new PriorityQueue<>();
            int pos = Arrays.binarySearch(num, 0, m, sum);
            pq.add(-sum);
            int curPos = m-1;
            while (!pq.isEmpty()) {
                long head = -pq.poll();
                pos = Arrays.binarySearch(num, 0, m, head);
                if(pos < 0 && head < num[curPos]) {
                    ans = "NO";
                    break;
                }
                if (head == 1 && pos < 0) {
                    ans = "NO";
                    break;
                }
                if(pos >= 0 && cnt[pos] < 0) {
                    ans = "NO";
                    break;
                }
                if (pos >= 0 && cnt[pos] > 0) {
                    cnt[pos]--;
                    if(cnt[pos] == 0) {
                        curPos--;
                    }
                } else if (head != 1) {
                    long son1 = (head + 1) >> 1;
                    pq.add(-son1);
                    long son2 = head >> 1;
                    pq.add(-son2);
                }
            }
            for (int i = 0; i < m; i++) {
                if (cnt[i] > 0) {
                    ans = "NO";
                }
            }
            System.out.println(ans);

        }
    }
}
