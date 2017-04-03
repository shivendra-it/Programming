#include<bits/stdc++.h>
using namespace std;

void bubblesort(int arr[],int n){
    for(int i=0;i<n;i++){
        for(int j= 0 ; j< n-i-1 ;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void display(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}
int main(){
    int arr[] = { 1, 5 , 7 , 4, 12 ,24 ,16};
    int size = sizeof(arr)/sizeof(arr[0]);

    bubblesort(arr,size);
    display(arr,size);
    return 0;
}
