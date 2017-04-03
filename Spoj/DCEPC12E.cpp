#include<bits/stdc++.h>
using namespace std;

int a[100][100];
int b[100][100];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                 cin>>b[i][j];

      unsigned long long q;
      while(q--){
          char ch;
          int r,c;
            int val;
          cin>>ch>>r>>c>>val;
          if(ch == 'A'){
              a[r][c] = val;
          }
          if(ch == 'B'){
              b[r][c] = val;
          }
           long long sum =0;

          for(int i = 0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    sum += (a[i][k]*b[k][j]);
                }
            }
          }
        cout<<sum<<endl;
      }          

    return 0;
}