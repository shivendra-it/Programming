import java.io.*;
import java.util.*;

class CHEFSIGN {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine();
        while (t-- != 0) {
            String str = sc.nextLine();
            int n = str.length();
            char[] ch = str.toCharArray();
            Stack<Character> s = new Stack<Character>();
            int count = 1;
            int maxcount = -1;
            char cur,prev='-';
            for (int i = 0; i < n; i++) {
                if (ch[i] != '=') {
                    if (!s.empty()) {
                         prev = s.peek();
                         cur = ch[i];
                        if (cur == prev) {
                            count++;
                            s.push(ch[i]);
                        } else {
                            s.pop();
                            count--;
                        }
                        prev = cur;
                    } else {
                        cur = ch[i];
                        s.push(cur);
                        // if(prev == cur)
                        //     count = maxcount;
                         if(prev == cur && count == 1)
                            count = maxcount;
                        count++;
                    }
                }
                if (maxcount < Math.abs(count)) {
                    maxcount = count;
                }
            }
            System.out.println(maxcount);
        }
    }

}