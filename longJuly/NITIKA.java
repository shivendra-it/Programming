import java.io.*;
import java.util.*;

class NITIKA {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- != 0) {
            String str = sc.nextLine();
            //System.out.println(str);
            String[] sl = str.split(" ");
            int k = sl.length;
            if (k == 1) {
                char c = Character.toUpperCase(sl[0].charAt(0));
                System.out.print(c);
                for (int i = 1; i < sl[0].length(); i++) {
                    System.out.print(Character.toLowerCase(sl[0].charAt(i)));
                }
                System.out.print("\n");
            } else if (k == 2) {
                char c = Character.toUpperCase(sl[0].charAt(0));
                System.out.print(c);
                System.out.print(".");
                System.out.print(" ");

                c = Character.toUpperCase(sl[1].charAt(0));
                System.out.print(c);
                for (int i = 1; i < sl[1].length(); i++) {
                    System.out.print(Character.toLowerCase(sl[1].charAt(i)));
                }
                System.out.print("\n");

            } else if (k == 3) {
                char c = Character.toUpperCase(sl[0].charAt(0));
                System.out.print(c);
                System.out.print(".");
                System.out.print(" ");

                c = Character.toUpperCase(sl[1].charAt(0));
                System.out.print(c);
                System.out.print(".");
                System.out.print(" ");

                c = Character.toUpperCase(sl[2].charAt(0));
                System.out.print(c);
                for (int i = 1; i < sl[2].length(); i++) {
                    System.out.print(Character.toLowerCase(sl[2].charAt(i)));
                }
                System.out.print("\n");
            }
        }
    }

}