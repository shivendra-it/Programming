#include<bits/stdc++.h>
using namespace std;

int partitiondemo(int a[],int p, int q){
    int pivot;
    pivot = a[p];
    int i=p,j=q;
    while(1){
    while (a[i]!=pivot && a[i] < pivot)
    {
        i++;
    }
     while (a[j]!=pivot && a[j] > pivot)
    {
        j--;
    }
    if(i<j){
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
    else
    {
        return j;
    }
    }
}




void quicksortdemo(int a[],int p,int q){
    if(p<q){
        int t = partitiondemo(a,p,q);
        quicksortdemo(a,p,t);
        quicksortdemo(a,t+1,q);
    }
}


void display(int a[], int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<"  ";
    }
}

int main(){
    int a[] = { 1, 5 , 7 , 4, 12 ,24 ,16};
    int size = sizeof(a)/sizeof(a[0]);

    quicksortdemo(a,0,size-1);
    display(a,size);
    return 0;
}
