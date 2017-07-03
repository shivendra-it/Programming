#include<bits/stdc++.h>
using namespace std;

int findsum(int arr[],int n){
    if(n==1){
    return arr[n-1];
    }
    if(n==2)
    return max(arr[n-1],arr[n-2]);

    for(int i=2;i<n;i++){
        arr[i] = max(max(arr[i-2],arr[i-2]+arr[i]),max(arr[i],arr[i-1]));
    }
    return arr[n-1];
}

int main(){
    // int arr[]={-1,-1,0,-3,-4,-4,-3};
    int arr[]={-2,-4,4,-4,-4,4};
    int n = sizeof(arr)/sizeof(int);
    cout<<findsum(arr,n)<<endl;
}