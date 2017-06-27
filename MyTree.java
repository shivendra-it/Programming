import java.util.*;
import java.io.*;
import java.lang.*;

class MyTree{

    class Node{
        int data;
        Node left;
        Node right;
        Node(int data){
            this.data = data;
            this.left = null;
            this.right = null;
        } 
    }
    Node root;
    MyTree(){
        root = null;
    }


    public static void main(String[] args) {
        MyTree T = new MyTree();
        T.root = new Node(1);
        
    }


}