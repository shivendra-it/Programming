#include<bits/stdc++.h>
using namespace std;

void selectionsort(int arr[],int n){
    for(int i=0;i<n;i++){
        int min = i;
        for(int j= i+1 ; j< n ;j++){
            if(arr[min]>arr[j]){
                int temp = arr[min];
                arr[min] = arr[j];
                arr[j] = temp;
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

    selectionsort(arr,size);
    display(arr,size);
    return 0;
}
