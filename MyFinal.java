import java.util.*;
import java.io.*;
import java.lang.*;

class MyFinal {

    public static int BS(int arr[], int l, int h, int elm) {

        while (l <= h) {
            int m = (h - l) / 2 + 1;
            if (arr[m] == elm)
                return m;
            if (arr[m] > elm) {
                h = m - 1;
            } else if (arr[m] < elm) {
                l = m + 1;
            } else {
                return -1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("Happy");
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        long b = sc.nextLong();
        sc.nextLine();
        String s = sc.nextLine();
        System.out.println(a);
        System.out.println(b);
        String[] ap = s.split(" ");
        for (String var : ap) {
            System.out.println(var);
        }
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            System.out.println(arr[i]);
        }
        while (true) {
            int elm = sc.nextInt();
            int k = BS(arr, 0, n, elm);
            System.out.println(k);
        }
    }
}
