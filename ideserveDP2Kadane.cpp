#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
int sum_temp=0,sum_all=0;
for(int i=0;i<n;i++){
    sum_temp += arr[i];
    if(sum_all<sum_temp)
        sum_all=sum_temp;

if(sum_temp<0)
    sum_temp = 0;
}
return sum_all;
}

int main(){
    int arr[]={2,5,-9,2,7,11,-2,4,-9,-10};
    cout<<kadane(arr,10)<<endl;
    return 0;
}