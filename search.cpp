#include<bits/stdc++.h>
using namespace std;
int search_do(int arr[],int l,int h,int e){
    int mid = l + (h-l)/2;
    if(arr[mid]==e)
        return mid;
    else if(arr[mid]>e && e>=arr[0])
        return search_do(arr,l,mid,e);
    else
        return search_do(arr,mid,h,e);
}
int main(){
    int arr[] = {1,2,3,4,5,6,7,8,-6,-9,-10,-11,-25};
    int n = sizeof(arr)/sizeof(int);
    cout<<search_do(arr,0,n,-11)<<endl;
    return 0;
}