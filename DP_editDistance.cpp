#include<bits/stdc++.h>
using namespace std;
/*
 str1 = "sunday", str2 = "saturday"
Output:  3
*/
int mini(int a,int b,int c){
    return min(min(a,b),min(b,c));
}

int editDistanceDP(string str1,string str2,int m,int n){

int DP[m+1][n+1];

for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++){
        if(i==0)
            DP[i][j] = j;
        if(j==0)
            DP[i][j] = i;
        if(str1[i-1]==str2[j-1])
            DP[i][j] = DP[i-1][j-1];



    }
}

       
}

int editDistance(string str1,string str2,int m,int n){
if(m==0)
    return n;
if(n==0)
    return m;
if(str1[m-1]==str2[n-1])
    return editDistance(str1,str2,m-1,n-1);

return 1 + mini(
    editDistance(str1,str2,m-1,n),
    editDistance(str1,str2,m,n-1),
    editDistance(str1,str2,m-1,n-1)
);
       
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    int m = str1.length();
    int n = str2.length();
    cout<<editDistance(str1,str2,m,n)<<endl;
    return 0;
}









/*
int editDistDP(string str1, string str2, int m, int n)
{
    // Create a table to store results of subproblems
    int dp[m+1][n+1];
 
    // Fill d[][] in bottom up manner
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            // If first string is empty, only option is to
            // isnert all characters of second string
            if (i==0)
                dp[i][j] = j;  // Min. operations = j
 
            // If second string is empty, only option is to
            // remove all characters of second string
            else if (j==0)
                dp[i][j] = i; // Min. operations = i
 
            // If last characters are same, ignore last char
            // and recur for remaining string
            else if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
 
            // If last character are different, consider all
            // possibilities and find minimum
            else
                dp[i][j] = 1 + min(dp[i][j-1],  // Insert
                                   dp[i-1][j],  // Remove
                                   dp[i-1][j-1]); // Replace
        }
    }
 
    return dp[m][n];
}

*/