
public class Sample {

    private static class PriorityQueue {

        private final int[] heap;
        private int size;

        public PriorityQueue(int size) {
            this.size = 0;
            this.heap = new int[size];
        }

        public void insert(int value) {
            heap[size++] = value;
            up(size - 1);
        }

        public int top() {
            return heap[0];
        }

        public int pop() {
            int result = heap[0];
            heap[0] = heap[size - 1];
            size--;
            down(0);
            return result;
        }

        private void up(int i) {
            while (i >= 1 && heap[i] > heap[i / 2]) {
                int t = heap[i];
                heap[i] = heap[i >> 1];
                heap[i >> 1] = t;
                i >>= 1;
            }
        }

        void down(int i) {
            while (i * 2 < size) {
                int j = i * 2;
                if (j + 1 <= size && heap[j + 1] > heap[j]) {
                    j++;
                }
                if (heap[j] <= heap[i]) {
                    break;
                }
                // swap
                int t = heap[i];
                heap[i] = heap[j];
                heap[j] = t;

                i = j;
            }
        }
    }

    public static void main(String[] args) {
        PriorityQueue pq = new PriorityQueue(100);
        int[] array = new int[] {1, 3, -1, -3, 5, 3, 6, 7};
        for (int i = 0; i < array.length; i++) {
            pq.insert(array[i]);
        }
        System.out.println(pq.top());
    }
}