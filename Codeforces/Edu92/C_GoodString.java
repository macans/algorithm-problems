package Edu92;

import java.util.Arrays;
import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

/**
 * Created on 2022-07-06 00:17:08
 * 
 * @author macinchang
 */
public class C_GoodString {

    public static void main(String[] args) throws Exception {
        Scanner scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            scanner = new Scanner("in.txt");
        } else {
            scanner = new Scanner(System.in);
        }
        int t = scanner.nextInt();
        while (t-- > 0) {
            System.out.println(t);
            String s = scanner.nextLine();
            System.out.println(getMinCount(s));
        }
    }

    private static int getMinCount(String s) {
        // 剩余字符串长度为奇数，计算众数的个数
        int modCount = getModCount(s);
        // 剩余字符串为偶数
        int remainCount = getRemainCount(s);
        return Math.min(s.length() - modCount, s.length() - remainCount);
    }

    private static int getRemainCount(String s) {
        char[] m = new char[2];
        int max = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j < s.length(); j++) {
                int cur = 2;
                m = new char[] { s.charAt(i), s.charAt(j) };
                for (int k = j + 1; k < s.length(); k++) {
                    if (s.charAt(k) == m[cur % 2]) {
                        cur++;
                    }
                }
                max = Math.max(max, cur);
            }
        }
        return max;
    }

    private static int getModCount(String s) {
        System.out.println(s);
        int temp = 0, res = 0;
        int count = 0;
        if (s == null) {
            return 0;
        }
        char[] sChars = s.toCharArray();
        Arrays.sort(sChars);
        char cur = sChars[0];
        for (int i = 0; i < sChars.length; i++) {
            if (sChars[i] == cur) {
                temp++;
            } else {
                temp = 1;
            }
            cur = sChars[i];
            res = Math.max(temp, res);
        }
        return res;
    }

    // public static class Solver {
    // public void solve(Scanner scanner) {
    // char[] a = scanner.next().toCharArray();
    // int len = a.length;
    // int[][] arr = new int[10][10];
    // for(int i = 0; i < len; i++) {
    // int val = a[i] - '0';
    // for(int j = 0; j < 10; j++) {
    // if(arr[j][val] % 2 == 1) {
    // arr[j][val] ++;
    // }
    // if(arr[val][j] % 2 == 0) {
    // arr[val][j] ++;
    // }
    // }
    // }
    // int maxLen = 0;
    // for(int i = 0; i < 10; i++) {
    // for(int j = 0; j < 10; j++) {
    // if(arr[i][j] > maxLen && (i != j && arr[i][j] % 2 == 0)) {
    // maxLen = arr[i][j];
    // }
    // }
    // }
    // System.out.println(len - maxLen);
    // }
    // }

static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(String string) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(string));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}
