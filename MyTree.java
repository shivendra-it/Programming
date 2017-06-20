import java.util.*;
import java.io.*;
import java.lang.*;

class Node {
    int data;
    Node left;
    Node right;

    Node(int d) {
        this.data = d;
        this.left = null;
        this.right = null;
    }

}

class MyTree {

    private Node head;

    public MyTree() {
        head = null;
    }

    public Node getRoot() {
        return head;
    }

    public boolean isEmpty() {
        return head == null;
    }

    public void Insert(int d) {
        Node temp = new Node(d);
        if (head == null) {
            head = temp;
            return;
        }
        Node cur = head;
        while (cur != null) {
            if (cur.data > d) {
                if (cur.left != null)
                    cur = cur.left;
                else {
                    cur.left = temp;
                    //System.out.println(cur.data);
                    return;
                }
            } else if (cur.data < d) {
                if (cur.right != null)
                    cur = cur.right;
                else {
                    cur.right = temp;
                    //System.out.println(cur.data);
                    return;
                }
            }
        }
        return;
    }

    public void Display(Node node) {
        if (node == null)
            return;
        Display(node.left);
        System.out.print(node.data + " ");
        Display(node.right);
    }

    void Display() {
        Display(head);
    }

    boolean Search(Node node, int n) {
        if(node.data == n){
            return true;
        }else if(node.data < n ){
            if(node.right != null)
            return Search(node.right , n);
            else
            return false;
        }else if(node.data > n ){
            if(node.left != null)
            return Search(node.left,n);
            else
            return false;
        }else{
            return false;
        }
    }

    boolean Search(int n) {
        return Search(head, n);
    }

    public static void main(String[] args) {
        System.out.println("I am Tree");
        MyTree mt = new MyTree();
        mt.Insert(1);
        mt.Insert(3);
        mt.Insert(5);
        mt.Insert(7);
        mt.Insert(9);
        mt.Insert(2);
        //System.out.println("apple");
        mt.Insert(4);
        mt.Display();
        boolean k = mt.Search(7);
        System.out.println(k);
        k = mt.Search(155);
        System.out.println(k);

    }
}
