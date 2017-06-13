#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y,s=0,sxy=0,yc=0;
        cin>>x>>y;
        sxy = x+y;
        yc =(sxy%2==0)? (1 +(sxy/2)*(sxy+1)):(1+((sxy+1)/2)*sxy);
        cout<<(yc+x)<<endl;
    }
    return 0;
}