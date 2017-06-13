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
        int i,cp=0,cn=0;
        for(i=n-1;i>=0;i--){
           if((s+arr[i])>0)
            {
                s+=arr[i];
                cp++;
            }
            else
                break;
        }
     //   cout<<"cp "<<cp<<"   "<<"s "<<s<<endl;
        l = cp*s;
        if(cp!=n){
            i=n-cp-1;
            //cout<<"i  "<<i<<endl;
        while(i>=0){
            l+=arr[i];
            i--;
            }
        }
        cout<<l<<endl;
    }
    return 0;
}