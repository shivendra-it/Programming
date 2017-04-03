#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={1,0,-1,2,3,4,-500,6,4,0,2};
    int tsum=0,tstart=0,tend=0;
    int sum=0,start=0,end=0;
    for(int i=0;i<11;i++)
    {
        tsum += arr[i];
        tend++;
        if(tsum>sum){
            sum = tsum;
            start = tstart;
            end = tend;
        }else if(tsum<0){
            tstart=tend=i+1;
            tsum =0;
        }
    }
    for(int i=start;i<end;i++){
        cout<<arr[i]<<"  ";
    }
    return 0; 
}