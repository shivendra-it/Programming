#include<bits/stdc++.h>
using namespace std;

void findPair(vector<int> &arr,int n, int el){
if(el>n){
    for(int i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
for(int i=0;i<2*n;i++){
if((arr[i]== -1) && ((i+el+1)<2*n) &&(arr[i+el+1])==-1){
    arr[i] = el;
    arr[i+el+1] = el;
    findPair(arr,n,el+1);
     arr[i] = -1;
    arr[i+el+1] = -1;
}
}
}

int main(){
   int n;
   cin>>n;
   vector<int> arr(2*n, -1);
   int el = 1;
   findPair(arr,n,el); 
    return 0;
}