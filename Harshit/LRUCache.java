import java.io.*;
import java.util.*;

class Node {
    int key;
    int value;
    Node pre;
    Node next;

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
    }
}

public class LRUCache {
    int capacity;
    HashMap<Integer, Node> map = new HashMap<Integer, Node>();
    Node head = null;
    Node end = null;

    public LRUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        if (map.containsKey(key)) {
            Node n = map.get(key);
            remove(n);
            setHead(n);
            return n.value;
        }

        return -1;
    }

    public boolean del(int key) {
        if (map.containsKey(key)) {
            Node n = map.get(key);
            remove(n);
            return true;
        }

        return false;
    }

    public void remove(Node n) {
        if (n.pre != null) {
            n.pre.next = n.next;
        } else {
            head = n.next;
        }

        if (n.next != null) {
            n.next.pre = n.pre;
        } else {
            end = n.pre;
        }

    }

    public void setHead(Node n) {
        n.next = head;
        n.pre = null;

        if (head != null)
            head.pre = n;

        head = n;

        if (end == null)
            end = head;
    }

    public void set(int key, int value) {
        if (map.containsKey(key)) {
            Node old = map.get(key);
            old.value = value;
            remove(old);
            setHead(old);
        } else {
            Node created = new Node(key, value);
            if (map.size() >= capacity) {
                map.remove(end.key);
                remove(end);
                setHead(created);

            } else {
                setHead(created);
            }

            map.put(key, created);
        }
    }

    public static void main(String[] args) {
        LRUCache lc = new LRUCache(2);
        Scanner sc = new Scanner(System.in);
        int Q = Integer.parseInt(sc.nextLine());
        while (Q-- != 0) {
            String[] s = sc.nextLine().split(" ");
            if (s[0] == "1") {
                lc.set(Integer.parseInt(s[2]), Integer.parseInt(s[1]));
            } else if (s[0] == "2") {
                boolean p = lc.del(Integer.parseInt(s[1]));
            } else if (s[0] == "3") {
                System.out.println(lc.head.value);
            } else if (s[0] == "4") {
                System.out.println(lc.end.value);
            }else if (s[0] == "5") {
                System.out.println(lc.get(Integer.parseInt(s[1])));
            }
        }
    }
}