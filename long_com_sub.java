import java.util.*;
import java.io.*;
import java.lang.*;

public class long_com_sub {
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    public static int longestCommonSubstring(String A, String B) {
        // write your code here
        if (A == null || B == null || A.length() == 0 || B.length() == 0) {
            return 0;
        }
        int maxLen = Math.max(A.length(), B.length());
        int[][] dp = new int[maxLen+1][maxLen+1];
        int res = 0;
        for (int i = 0; i < A.length(); i++) {
            for (int j = 0; j < B.length(); j++) {
                if (A.charAt(i) == B.charAt(j)) {
                    dp[i+1][j+1] = dp[i][j] + 1;
                    res = Math.max(res, dp[i+1][j+1]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(longestCommonSubstring("APPLE","APPS"));
    }
}