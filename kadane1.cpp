#include<bits/stdc++.h>
using namespace std;
int kadane(int arr[],int n){
int max_sum_all = 0;
int max_sum_till = 0;
for(int i=0;i<n;i++){
max_sum_till += arr[i];
if(max_sum_all<max_sum_till){
max_sum_all = max_sum_till;
}
if(max_sum_till < 0)
max_sum_till = 0;
}
return max_sum_all;
}
int main(){
int arr[]={1,5,-6,-7,8,-5,12,-2};
cout<<kadane(arr,8)<<endl;
return 0;
}
