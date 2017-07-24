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
            int count=1,maxcount =1;
            int f=1;
            for(int i=0;i<n;i++){
                if(ch[i]=='=')
                    continue;
                else{
                    if(ch[i]=='>'){
                        if(count>1){
                            count--;
                        }else{
                            maxcount++;
                        }
                        f =1;
                    }else if(ch[i]=='<'){
                        if(f==1){
                            count =1;
                        }
                            count++;
                            f = 2;
                    }
                }
                maxcount = Math.max(count,maxcount);
            }
            System.out.println(maxcount);
        }
    }
}