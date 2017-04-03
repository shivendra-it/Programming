#include<bits/stdc++.h>
using namespace std;

int BS(int arr[],int lb,int ub,int x){
    while(ub>=lb){
        int mid = (lb+ub)/2;
        if(arr[mid]==x)
            return mid;
        if(x<arr[mid]){
            if(x < arr[lb] && arr[mid]>arr[ub]){
                lb = mid+1;
            }else{
                ub = mid-1;
            }
        }else if(x > arr[mid]){
            if(x > arr[lb] && arr[mid]<arr[ub]){
                lb = mid+1;
            }else{
                ub = mid-1;
            }
        }
    }
}

int main(){
    
    int arr[] = {3,4,5,6,7,8,1,2};
    cout<<BS(arr,0,8,1);
    return 0;
}