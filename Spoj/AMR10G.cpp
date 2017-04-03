#include<bits/stdc++.h>
using namespace std;

int arr[20005];

int main(){
    int t,n,k;
    cin>>t;
    while(t--){

        cin>>n>>k;

        for(int i=0;i<n;i++){

            cin>>arr[i];
        }

        sort(arr,arr+n);

    int min =1000000009;

    for(int i=0;i+k-1<n;i++){
        if((arr[i+k-1] - arr[i])<min){
            min = arr[i+k-1] - arr[i];
        }          
    }

    if(min == 1000000009)
    min =0;

    cout<<min<<endl;
    }


    return 0;
}

