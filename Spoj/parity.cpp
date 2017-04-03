#include<bits/stdc++.h>
using namespace std;

int checkParity(int n){

    int result = 0;
    while(n){
        result ^= 1;
        n = n & (n-1);
    }
return result;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<checkParity(n)<<endl;
    }

    return 0;
}
