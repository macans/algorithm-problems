package R805;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.io.File;

/**
 * Created on 2022-07-10 22:33:23
 * 
 * @author macinchang
 */
public class D_NotACheapString {

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
        class Node implements Comparable<Node> {
            char ch;
            int pos;

            Node(char ch, int pos) {
                this.ch = ch;
                this.pos = pos;
            }

            public int compareTo(Node b) {
                return Integer.compare(pos, b.pos);
            }
        }

        public void solve(Scanner scanner) {
            char[] s = scanner.next().toCharArray();
            int n = s.length;
            int p = scanner.nextInt();
            int cur = 0;
            ArrayList<ArrayList<Node>> a = new ArrayList<>(30);
            for (int i = 0; i <= 26; i++) {
                a.add(new ArrayList<>());
            }

            for (int i = 0; i < n; i++) {
                int x = s[i] - 'a' + 1;
                cur += x;
                a.get(x).add(new Node(s[i], i));
            }
            for (int i = 26; i >= 1; i--) {
                if (a.get(i).size() == 0) {
                    continue;
                }
                if (cur - a.get(i).size() * i >= p) {
                    cur -= a.get(i).size() * i;
                    a.get(i).clear();
                    if (cur == p) {
                        break;
                    }
                    continue;
                }
                int tmp = (cur - p + i - 1) / i;
                if (tmp <= 0) {
                    continue;
                }
                ArrayList<Node> tempList = new ArrayList<>(a.get(i).subList(0, a.get(i).size() - tmp));
                a.set(i, tempList);
                break;
            }
            int cnt = 0;
            Node[] nodes = new Node[n];
            for (int i = 1; i <= 26; i++) {
                for (Node node : a.get(i)) {
                    nodes[cnt++] = node;
                }
            }
            Arrays.sort(nodes, 0, cnt);
            char[] res = new char[cnt];
            for (int i = 0; i < cnt; i++) {
                res[i] = nodes[i].ch;
            }
            System.out.println(res);
        }
    }
}
