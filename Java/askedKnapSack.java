import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

class Solution {

 int values[];
 float weights[];
 int N;
 int W;
 int matrix[][];
 int keep[][];
 void Initialize(int N,int W)
 {
this.N=N;
this.W=W;
values = new int[N+1];
weights = new float[N+1];

     matrix=new int[N+1][W+1];
 	keep= new int[N+1][W+1];
 	for(int w=0;w<=W;w++)
{
matrix[0][w]=0;
}
 }
 void Knapsack_Modified()
 {
for(int i=1;i<=N;i++)
 	{
 	for(int w=0;w<=W;w++)
 	{
 	if(weights[i]<=w  )
 	{
 	
 	int ww= (int) Math.floor(weights[i]);
 	matrix[i][w]=Math.max(values[i]+matrix[i-1][(w-ww)],matrix[i-1][w]);
 	if(values[i]+matrix[i-1][(w-ww)]>matrix[i-1][w])
 	{
 	keep[i][w]=1;
 	}
 	//keep[i][w]=1;
 	}
 	else
 	{
 	matrix[i][w]=matrix[i-1][w];
 	keep[i][w]=0;
 	}	
 	}
 	}
 }
 void Print_Subset()
 {
int K=W;
int check=0;
    for(int i=N; i>0;i--)
    {
    if(keep[i][K]==1)
    {
    check=1;
    System.out.print(i+1);
    
    System.out.print(',');
    
    int ww= (int) Math.floor(weights[i]);
    K=K-ww;
    }
    
    
    }
    if(check!=1)
    {
    System.out.print('-');
    }
 }
    public static void main(String args[] ) throws Exception {
        
    BufferedReader br = new BufferedReader(new FileReader("D:/EclipseWS/input.txt"));
    //81 : (1,53.38,$45) (2,88.62,$98) (3,78.48,$3) (4,72.30,$76) (5,30.18,$9) (6,46.34,$48)
    
    String line = br.readLine();
    
        while (line != null) {
        line=line.replaceAll("[)($]", "");
        String table[]= line.split(" ");
        
            int W=Integer.parseInt(table[0]);
            int N= (table.length)-2;
            Solution s = new Solution();
            s.Initialize(N, W);
            
           
           
            for(int i=2;i<table.length;i++)
            {
            String entry[]=table[i].split(",");
            s.values[i-2]=Integer.parseInt(entry[2]);
            s.weights[i-2]=Float.parseFloat(entry[1]);
            }
            s.Knapsack_Modified();
            s.Print_Subset();
         
            System.out.println();
            line = br.readLine();
        }
    
    }
}