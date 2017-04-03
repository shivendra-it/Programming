#include<bits/stdc++.h>
using namespace std;


void merge(int a[], int p, int q, int r)
{
  int b[100];     //same size of a[]
  int i, j, k;
  k = 0;
  i = p;
  j = q+1;
  while(i <= q && j <= r)
  {
    if(a[i] < a[j])
    {
      b[k++] = a[i++];       // same as b[k]=a[i]; k++; i++;
    }
    else
    {
      b[k++] = a[j++];
    }
  }
  
  while(i <= q)
  {
    b[k++] = a[i++];
  }
  
  while(j <= r)
  {
    b[k++] = a[j++];
  }
  
  for(i=r; i >= p; i--)
  {
    a[i] = b[--k];        // copying back the sorted list to a[]
  } 

}

void mergesort(int a[], int p, int r)
{
  int q;
  if(p < r)
  {
    q = floor( (p+r) / 2);
    mergesort(a, p, q);
    mergesort(a, q+1, r);
    merge(a, p, q, r);
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

    mergesort(a,0,size-1);
    display(a,size);
    return 0;
}