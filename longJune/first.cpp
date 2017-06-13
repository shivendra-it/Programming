#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long c=1;
        for(long long i=1;i<=n;i++){
            cout<<c<<" ";
            c+=2;
        }
        cout<<endl;
    }
    return 0;
}