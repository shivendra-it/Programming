import java.util.*;
import java.lang.*;
import java.io.*;

class Node {
    int data;
    Node left, right;

    Node(int d) {
        this.data = d;
        this.left = null;
        this.right = null;
    }
}

class IsSame {
    Node root1;
    Node root2;

    IsSame() {
        root1 = null;
        root2 = null;
    }

    boolean IsSame1(Node root1, Node root2) {
        if (root1 == null && root2 == null)
            return true;
        if (root1 != null && root2 != null) {
            return root1.data == root2.data && IsSame1(root1.left, root2.left) && IsSame1(root1.right, root2.right);
        }
        return false;
    }

    boolean IsChildrenSum(Node node) {
        if (node == null)
            return true;
        int s = 0;
        if (node.left != null)
            s += node.left.data;
        if (node.right != null)
            s += node.right.data;
        if (node.data == s)
            return true;
        return false;
    }

    Node InorderPredessor(Node head,Node node){
        if(node == null)
            return node;
        if(head.data == node.data)
            return head;
        
        
    }

    public static void main(String[] args) {
        IsSame t = new IsSame();
        t.root1 = new Node(22);
        t.root1.left = new Node(9);
        t.root1.right = new Node(13);
        t.root1.left.left = new Node(4);
        t.root1.left.right = new Node(5);
        t.root1.right.left = new Node(6);
        t.root1.right.right = new Node(7);
        t.root2 = new Node(1);
        t.root2.left = new Node(2);
        t.root2.right = new Node(3);
        t.root2.left.left = new Node(4);
        t.root2.left.right = new Node(5);
        t.root2.right.left = new Node(6);
        t.root2.right.right = new Node(7);
        //isSame1(t.root1, t.root2);
        System.out.print(t.IsSame1(t.root1, t.root2));
        System.out.print(t.IsChildrenSum(t.root1));
        System.out.println(InorderPredessor(t.root2,t.root2.right.left));
    }
}