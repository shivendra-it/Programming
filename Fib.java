import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    static class Fib {
        public int Fiboss(int n) {
            final int mod = 1000000007;
            int[] fib = new int[1007];
            fib[0] = 0;
            fib[1] = 1;
            for (int i = 2; i <= n; i++) {
                fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
            }
            return fib[n];
        }
    }

    public static void main(String[] args) {
        int t;
        int n;
        Scanner sc = new Scanner(System.in);
        t = sc.nextInt();
        Fib k = new Fib();
        while (t-- != 0) {
            n = sc.nextInt();
            System.out.println(n);
            System.out.println(k.Fiboss(n));
        }
    }
}