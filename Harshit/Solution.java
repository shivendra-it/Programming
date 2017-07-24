import java.io.*;
import java.util.*;

public class Solution {
    static final int V = 10000; //Number of vertices

    // A Dynamic programming based function to count walks from u
    // to v with k edges
    int countwalks(int graph[][], int u, int v, int k) {
        // Table to be filled up using DP. The value count[i][j][e]
        // will/ store count of possible walks from i to j with
        // exactly k edges
        int count[][][] = new int[V][V][k + 1];

        // Loop for number of edges from 0 to k
        for (int e = 0; e <= k; e++) {
            for (int i = 0; i < V; i++) // for source
            {
                for (int j = 0; j < V; j++) // for destination
                {
                    // initialize value
                    count[i][j][e] = 0;

                    // from base cases
                    if (e == 0 && i == j)
                        count[i][j][e] = 1;
                    if (e == 1 && graph[i][j] != 0)
                        count[i][j][e] = 1;

                    // go to adjacent only when number of edges
                    // is more than 1
                    if (e > 1) {
                        for (int a = 0; a < V; a++) // adjacent of i
                            if (graph[i][a] != 0)
                                count[i][j][e] += count[a][j][e - 1];
                    }
                }
            }
        }
        return count[u][v][k];
    }

    public static void main(String[] args) throws IOException {

        Scanner scanner = new Scanner(new File("graph_dataset.csv"));
        int graph[][] = new int[10000][10000];

        while (scanner.hasNext()) {
            String[] str = scanner.nextLine().split(",");
            int a = Integer.parseInt(str[0]);
            int b = Integer.parseInt(str[1]);
            graph[a][b] = 1;
            graph[b][a] = 1;
        }

        int u = 300, v = 30, k = 10;
        Solution p = new Solution();
        System.out.println(p.countwalks(graph, u, v, k));
        scanner.close();

    }

}
