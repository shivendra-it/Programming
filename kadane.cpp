#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int max_overall = 0;
    int max_tillnow = 0;
    for(int i=0;i<n;i++){
        max_tillnow += arr[i];
        if(max_tillnow < 0)
        max_tillnow = 0;

        max_overall = max(max_overall,max_tillnow);
    }
return max_overall;
}


int main(){
    int arr[] = {-1,2,3,4,-3,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = kadane(arr,n);
    cout<<k<<endl;
    return 0;
}