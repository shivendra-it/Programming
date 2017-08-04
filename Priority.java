import java.io.*;
import java.util.*;

class Priority {
    public static void main(String[] args) {
        System.out.println("PriorityQueues");
        PriorityQueue<Integer> queue = new PriorityQueue<Integer>();
        // queue.add("Apple");
        // queue.add("DOg");
        // queue.add("Appstore");
        // queue.add("cat");
        // queue.add("Shivendra");
        queue.add(5);
        queue.add(7);
        queue.add(11);
        queue.add(4);
        queue.add(9);
        Iterator it = queue.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + "  ");
        }
    }
}