import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

static int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
static int toDeci(String str, int base)
{
	int len = str.length();
	int power = 1; // Initialize power of base
	int num = 0; // Initialize result
	int i;

	// Decimal equivalent is str[len-1]*1 +
	// str[len-1]*base + str[len-1]*(base^2) + ...
	for (i = len - 1; i >= 0; i--)
	{
		// A digit in input number must be
		// less than number's base
		if (val(str.charAt(i)) >= base)
		{
		return -1;
		}

		num += val(str.charAt(i)) * power;
		power = power * base;
	}

	return num;
}
    static int getMagicNumber(String s, int k, int b, int m){
        // Complete this function
        ArrayList<String> as = new ArrayList<String>();
        
        for(int i=0;(i+k)<=s.length();i++){
            String st = s.substring(i,i+k);
            as.add(st);
        }
        System.out.println(as);
        int sum =0;
 for (String str : as) {
    System.out.println(str);
    int kt = toDeci(str,b);
    System.out.println(kt);
    kt = kt%m;
    sum+=kt;
}
       return sum;
        
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        int k = in.nextInt();
        int b = in.nextInt();
        int m = in.nextInt();
        int result = getMagicNumber(s, k, b, m);
        System.out.println(result);
    }
}
