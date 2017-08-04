import java.io.*;
import java.util.*;
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8

// Input: (2 -> 4 -> 9) + (3 -> 6 -> 11)
// Output: 7 -> 0 -> 8
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

class Solution {

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode current1 = l1;
        ListNode current2 = l2;

        ListNode head = new ListNode(0);
        ListNode currentHead = head;

        int sum = 0;

        while (current1 != null || current2 != null) {

            sum /= 10;

            if (current1 != null) {

                sum += current1.val;
                current1 = current1.next;

            }

            if (current2 != null) {

                sum += current2.val;
                current2 = current2.next;

            }

            currentHead.next = new ListNode(sum % 10);
            currentHead = currentHead.next;

        }

        if (sum / 10 == 1) {

            currentHead.next = new ListNode(1);

        }

        return head.next;

    }

    public ListNode mergeKLists(ListNode[] lists) {

        if (lists == null || lists.length == 0)
            return null;

        PriorityQueue<ListNode> queue = new PriorityQueue<ListNode>(lists.length, new Comparator<ListNode>() {
            @Override
            public int compare(ListNode o1, ListNode o2) {
                if (o1.val >= o2.val)
                    return 1;
                else
                    return -1;
            }
        });

        ListNode dummy = new ListNode(0);
        ListNode tail = dummy;

        for (ListNode node : lists)
            if (node != null)
                queue.add(node);

        while (!queue.isEmpty()) {
            tail.next = queue.poll();
            tail = tail.next;

            if (tail.next != null)
                queue.add(tail.next);
        }
        return dummy.next;
    }

    public void Display(ListNode n) {
        while (n != null) {
            System.out.print(n.val + " ");
            n = n.next;
        }
        System.out.println();
    }

}

public class LinkedListAdd {
    public static void main(String[] args) {
        ListNode head3 = null;
        // ListNode head1 = new ListNode(2);
        // head1.next = new ListNode(4);
        // head1.next.next = new ListNode(3);

        // ListNode head2 = new ListNode(5);
        // head2.next = new ListNode(6);
        // head2.next.next = new ListNode(4);

        ListNode head1 = new ListNode(2);
        head1.next = new ListNode(4);
        head1.next.next = new ListNode(9);

        ListNode head2 = new ListNode(3);
        head2.next = new ListNode(6);
        head2.next.next = new ListNode(9);

        Solution sl = new Solution();
        head3 = null;
        head3 = sl.addTwoNumbers(head1, head2);
        System.out.println("Add Two Numbers");
        sl.Display(head3);

        ListNode[] list = new ListNode[2];
        list[0] = head1;
        list[1] = head2;
        head3 = null;
        head3 = sl.mergeKLists(list);
        System.out.println("Merge K Lists");
        sl.Display(head3);
    }
}