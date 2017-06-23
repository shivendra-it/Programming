import java.util.*;
import java.lang.*;
import java.io.*;

class Node {
    int data;
    Node left, right;

    public Node(int d) {
        data = d;
        left = right = null;
    }
}

class TreeAll {

    private Node root;

    TreeAll() {
        root = null;
    }

    public void inorder(Node node) {
        if (node == null)
            return;
        inorder(node.left);
        System.out.print(node.data + " ");
        inorder(node.right);
    }

public Node parent(Node node){
    if(root == node)
        return null;
    if(root.left == node || root.right == node)
        return root;
    if(root.left != null)
     return parent(root.left);
    if(root.right != null)
        return parent(root.right);
    return null;
}
    public Node inorderSuccessor(Node node) {

        if (node.right != null) {
            node = node.right;
            if (node.left != null) {
                while (node.left != null) {
                    node = node.left;
                }
            }
            return node;
        }
        Node temp = parent(node);
        while(temp != null && temp.right == node){
            node = temp;
            temp = parent(node);
        }
 return temp.right;
    }

    void inorder() {
        inorder(root);
    }

  

    public static void main(String[] args) {
        TreeAll T = new TreeAll();
        T.root = new Node(1);
        T.root.left = new Node(2);
        T.root.right = new Node(3);
        T.root.left.left = new Node(4);
        T.root.left.right = new Node(5);
        T.root.right.left = new Node(6);
        T.root.right.right = new Node(7);
        T.root.left.left.left = new Node(8);
        T.root.left.left.right = new Node(9);
        T.root.right.left.right = new Node(10);
        T.root.right.right.right = new Node(11);
        T.root.right.right.left = new Node(12);
        T.inorder();
        Node n = T.inorderSuccessor(T.root.left.left.right);
        System.out.println(n.data);
    }
}