#include<bits/stdc++.h>
using namespace std;

int arr[2501][2501];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,e;
        cin>>n>>k;
        memset(arr,0,sizeof(arr));
        for(int i=0;i<n;i++){
            cin>>e;
            for(int j=0;j<e;j++){
                int s;
                cin>>s;
                arr[i][s-1]=1;
            }
        }

int count =0;

        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){

                int z=1,l;

                for(int c=0;c<k;c++){
                   l = arr[i][c] | arr[j][c];
                   z = z & l;
                   if(l==0)
                        break;
                }
                if(z==1)
                    count++;             
            }
        }
     cout<<count<<endl;

    }
    return 0;
}