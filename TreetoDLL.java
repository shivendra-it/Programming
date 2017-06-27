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

class TreetoDLL {
    Node root;

    TreetoDLL() {
        root = null;
    }

    public Node convertTree(Node node) {
        if (node == null)
            return null;
        if (node.left != null) {
            Node left = convertTree(node.left);
            while (left.right != null)
                left = left.right;
            left.right = node;
            node.left = left;
        }

        if (node.right != null) {
            Node right = convertTree(node.right);
            while (right.left != null)
                right = right.left;
            right.left = node;
            node.right = right;
        }
        return node;
    }

    public Node convertTreeTemp() {
        if (root == null)
            return null;
        Node n = convertTree(root);
        while (n.left != null) {
            n = n.left;
        }
        return n;
    }

    void printo(Node node) {
        if (node == null)
            return;
        while (node != null) {
            System.out.print(node.data + " ");
            node = node.right;
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        TreetoDLL tree = new TreetoDLL();
        tree.root = new Node(10);
        tree.root.left = new Node(12);
        tree.root.right = new Node(15);
        tree.root.left.left = new Node(25);
        tree.root.left.right = new Node(30);
        tree.root.right.left = new Node(36);
        Node n = tree.convertTreeTemp();
        tree.printo(n);

        TreetoDLL t1 = new TreetoDLL();
        t1.root = new Node(1);
        t1.root.left = new Node(2);
        t1.root.right = new Node(3);
        t1.root.left.left = new Node(4);
        t1.root.left.right = new Node(5);
        t1.root.right.left = new Node(6);
        t1.root.right.right = new Node(7);

        Node n1 = t1.convertTreeTemp();
        t1.printo(n1);

        TreetoDLL t2 = new TreetoDLL();
        t2.root = new Node(1);
        t2.root.left = new Node(2);
        t2.root.right = new Node(3);
        t2.root.left.left = new Node(4);
        t2.root.left.right = new Node(5);
        t2.root.right.left = new Node(6);
        t2.root.right.right = new Node(7);

        Node n2 = t2.convertTreeTemp();
        t2.printo(n2);
    }
}