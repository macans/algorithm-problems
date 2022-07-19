package R792;

import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;

/**
 * Created on 2022-07-17 15:54:01
 * 
 * @author macinchang
 */
public class B_StoneAgeProblem {

    private static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;

        public Reader() {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public Reader(String file_name) throws IOException {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }

        public String readLine() throws IOException {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }

        public int nextInt() throws IOException {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (neg)
                return -ret;
            return ret;
        }

        public long nextLong() throws IOException {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }

        public double nextDouble() throws IOException {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();

            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');

            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }

            if (neg)
                return -ret;
            return ret;
        }

        private void fillBuffer() throws IOException {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }

        private byte read() throws IOException {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }

        public void close() throws IOException {
            if (din == null)
                return;
            din.close();
        }
    }

    public static void main(String[] args) throws Exception {
        Reader scanner;
        if (System.getProperty("ONLINE_JUDGE") == null) {
            scanner = new Reader("in.txt");
        } else {
            scanner = new Reader();
        }

        Solver solver = new Solver(scanner);
        solver.solve();

        scanner.close();
    }

    public static class Solver {
        Reader sc;

        Solver(Reader sc) {
            this.sc = sc;
        }

        public void solve() throws IOException {
            int n = sc.nextInt(), q = sc.nextInt();
            long[] a = new long[n];
            long sum = 0L;
            for (int i = 0; i < n; i++) {
                a[i] = sc.nextLong();
                sum += a[i];
            }
            int[] opt = new int[n];
            int last2 = -1;
            long lastValue = 0;
            for (int i = 0; i < q; i++) {
                int type = sc.nextInt();
                if (type == 2) {
                    last2 = i;
                    lastValue = sc.nextLong();
                    sum = lastValue * n;
                } else if (type == 1) {
                    int p = sc.nextInt() - 1;
                    long x = sc.nextLong();
                    if (opt[p] > last2) {
                        sum += x - a[p];
                    } else {
                        sum += x - lastValue;
                    }
                    opt[p] = i;
                    a[p] = x;
                }
                System.out.println(sum);
            }

        }
    }
}
