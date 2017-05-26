import java.util.Scanner;
class Pathgrid{

public void Path(){
return;
}

public static void main(String args[]){
    System.out.println("Happy");
    Scanner in =  new Scanner(System.in);
    int k = in.nextInt();
    String s = in.nextLine();
    System.out.println(k);
    System.out.println(s);
    int[][] matrix = new int[][];
    int m = in.nextInt();
    int n = in.nextInt();
    for(int i=0;i<m;i++){
        for(int j= 0;j<n;j++){
            matrix[i][j] = 12; 
        }
    }
for(int i=0;i<m;i++){
        for(int j= 0;j<n;j++){
            System.out.println(matrix[i][j]); 
        }
    }
}

}