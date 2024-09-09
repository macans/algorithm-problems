
import java.util.Scanner;
import java.util.concurrent.ThreadLocalRandom;
import java.io.File;

/**
 * Created on 2022-07-07 18:01:20
 * 
 * @author macinchang
 */
public class ARes {

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
            int[] weights = { 10, 4, 6 };
            int n = weights.length;
            int round = 10000000;
            int[] cnt = new int[n];
            for (int r = 0; r < round; r++) {
                double ans = Double.MIN_VALUE;
                int j = -1;
                for (int i = 0; i < n; i++) {
                    double rand = ThreadLocalRandom.current().nextDouble(1.0);
                    double key = Math.pow(rand, 1.0 / weights[i]);
                    if (Double.compare(key, ans) > 0) {
                        ans = key;
                        j = i;
                    }
                }
                ++cnt[j];
            }
            for (int i = 0; i < n; i++) {
                System.out.println(weights[i] + ": " + cnt[i] * 1.0 / round);
            }
        }
    }
}
