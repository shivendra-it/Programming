#include<bits/stdc++.h>
using namespace std;

int common_medium(int a[],int b[],int n){

    if(a[n-1]>=b[0])
        return a[n-1];
    if(b[n-1]<=a[0])
        return b[n-1];
    
   int med1 = a[(n-1)/2]; 
   int med2 = b[(n-1)/2];


    if(med1 == med2){
        return med1;
    }else if(med1<med2){
            return common_medium(&a[(n-1)/2],b,n/2 +1);
    }else{
        
            return common_medium(a,&b[(n-1)/2] ,n/2+1);
    
    }
}

int main(){
    
    int a[]={1,3,7,9,12};
    int b[]={1,2,12,13,25};

    int m = common_medium(a,b,5);
    cout<<m<<endl;
}