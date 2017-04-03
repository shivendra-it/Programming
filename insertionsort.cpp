#include<bits/stdc++.h>
using namespace std;

void insertionsort(int arr[],int n){

    for(int i=1;i<n;i++){
        int temp,j;
        j=i;
        while (j>0 && arr[j-1]>arr[j])
        {
            temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
            j--;
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

    insertionsort(arr,size);
    display(arr,size);
    return 0;
}
