
import java.util.HashMap;
import java.util.Scanner;
import java.util.concurrent.locks.ReentrantReadWriteLock;
import java.io.File;

/**
 * Created on 2022-06-29 15:13:24
 * 
 * @author macinchang
 */
// least recent
class LRUCache<K, V> {

    static private class Node<K, V> {
        K key;
        V value;
        Node prev, next;
    }

    ReentrantReadWriteLock.ReadLock readWriteLock;
    private HashMap<K, Node> cacheMap;
    private Node head, tail;
    private int size;
    private int capacity;

    LRUCache(int capacity) {
        size = 0;
        this.capacity = capacity;

        head = new Node();
        head.prev = null;

        tail = new Node();
        tail.next = null;
        tail.prev = head;
        head.next = tail;

        cacheMap = new HashMap<>();
    }

    public synchronized void put(K key, V value) {
        Node = cacheMap.get(key);
        if (cur != null) {
            removeNode(cur);
            addNode(cur);
            return cur;
        }

        cur = new Node();
        cur.key = key;
        cur.value = value;
        addNode(cur);
        ++size;

        if (size > capacity) {
            Node lastNode = tail.prev;
            cacheMap.remove(lastNode.key);
            --size;
            removeNode(lastNode);
        }
        return cur;
    }

    public synchronized V get(K key) {
        Node cur = cacheMap.get(key);
        if (cur == null) {
            return null;
        }
        removeNode(cur);
        addNode(cur.value);
    }

    public  int size() {
        return size;
    }

    private void addNode(Node node) {
        head.next.perv = node;
        node.next = head.next;

        node.prev = head;
        head.next = node;
    }

    private void removeNode(Node node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }

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
}
