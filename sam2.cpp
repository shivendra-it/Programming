#include <iostream>
using namespace std;

#define MOD 1000000007
bool isPrime[1000000];
int valid[2000][2000];
int Dir[2000][2000];
int MAT[2000][2000];
int visited[3000][3000];
int n, m;

void valueatindex ( int i, int j) {
    //cout <<i <<"^"<< j << endl;
    visited[i][j] = 1;
    if (i == 0 and j == 0 )  {
        return;
    }
    if (valid[i-1][j -1]  == 0 and !visited[i-1][j-1]) {
        valueatindex ( i - 1, j - 1) ;
    }
     if (valid[i-1][j]  == 0 and !visited[i-1][j] ) {
        valueatindex ( i - 1, j ) ;
    }
     if (valid[i][j -1] == 0 and !visited[i][j-1] ) {
        valueatindex ( i , j - 1) ;
    }
}

void generateSeive () {
    for ( int i = 2; i <= 200000; i ++ ) {
        if ( ! isPrime[i] ) {
            for ( int j = i + i; j <= 200000; j += i) {
                isPrime[j] = 1;
            }
        }
    }
}


void Solve ( int i, int j ) {
    cout << i << " "<<j << endl;
    if ( i== n and j == m ) return;
    if ( visited[i+1][j+1] and !valid[i+1][j+1] ) Solve(i+1, j+1); 
    else if ( visited[i+1][j] and !valid[i+1][j] ) Solve(i+1, j);
    else if ( visited[i][j+1] and !valid[i][j+1] ) Solve(i, j+1); 
}
int main()
{
   
    cin >> n >> m;
    for ( int i = 0; i <= n; i++ ) 
        for ( int j = 0; j <= m; j++ ) 
            valid[i][j] = 1;
    generateSeive();
    for ( int i = 1; i <= n; i ++ )
        for ( int j = 1; j <= m; j++ ) {
            int x; cin >> x;
            valid[i][j] = isPrime[x];
        }
    
   
    Dir[0][0] = 1;
    valid[0][0] = 0;
    
    
    for ( int i = 1; i <= n; i++ ) {
        for ( int j = 1; j <= m; j++ ) {
            long acc = 0;
           
            if ( valid[i][j] == 1) continue;
            if ( valid[i-1][j-1] ==  0) {
                acc += Dir[i-1][j-1]; 
            }
            if ( valid[i-1][j] == 0 ) {
                acc += Dir[i-1][j];
            }
            if ( valid[i][j-1] == 0 ) {
                acc += Dir[i][j-1]; 
            }
            acc %= MOD;
            Dir[i][j] = acc;
          
        }
    }
    cout <<Dir[n][m]<<endl;
    if (Dir[n][m] == 0 ) return 0;
    valueatindex(n,m);
    Solve(1,1);
    return 0;
    
}
