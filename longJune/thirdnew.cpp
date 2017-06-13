#include<bits/stdc++.h>
using namespace std;

int arr[100005];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        fill(arr,arr+n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        sort(arr,arr+n);
        long long s=0,l=0,c=0;
        int i,cp=0,cz=0,cn=0;
        for(i=n-1;i>=0;i--){
           if((arr[i])>=0)
               { cp++; s+=arr[i]; }
            else
                cn++;
        }
     //   cout<<"cp "<<cp<<"   "<<"s "<<s<<endl;
        
        if(cp!=n){
            i=n-cp-1;
            //cout<<"i  "<<i<<endl;
        while(i>=0){


        if((cp+1)*(s+arr[i])>(cp*s + arr[i])){
            s+=arr[i];
           cp++;
        }else{
            l+=arr[i];
        }
 
            i--;
            }
        }
l = cp*s + l;

        cout<<l<<endl;
    }
    return 0;
}