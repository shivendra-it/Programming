import java.io.*;
import java.util.*;
import java.lang.*;

class Node {
    int data;
    Node next;

    Node(int d) {
        this.data = d;
        this.next = null;
    }
}

class MyLinkedList {

    private Node head;

    MyLinkedList() {
        head = null;
    }

    void Insert(int d) {
        Node temp = new Node(d);
        if (head == null) {
            head = temp;
            return;
        }

        Node cur = head;
        while (cur.next != null) {
            cur = cur.next;
        }

        cur.next = temp;
    }

    void Deletea(int d) {
        if (head.data == d) {
            head = head.next;
        }
        Node cur = head;
        while (cur.next != null) {
            if (cur.next.data != d)
                cur = cur.next;
            else {
                if (cur.next.next != null)
                    cur.next = cur.next.next;
                else
                    cur.next = null;
            }
        }
    }

    void Display(Node node) {
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }

    void Display() {
        Display(head);
        System.out.println("\n");
    }

    public static void main(String[] args) {
        MyLinkedList mll = new MyLinkedList();
        mll.Insert(1);
        mll.Insert(2);
        mll.Insert(3);
        mll.Insert(4);
        mll.Insert(5);
        mll.Insert(6);
        mll.Insert(7);

        mll.Display();
        mll.Deletea(4);
        mll.Display();
        mll.Deletea(7);
        mll.Display();
        mll.Deletea(1);
        mll.Display();
    }
}