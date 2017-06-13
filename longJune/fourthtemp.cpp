#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[100005];
ll B[100005];
ll C[100005];

ll mod = 1000000007;

int main(){
    int t;
    cin>>t;
    while(t--){
        int p,q,r;
        cin>>p>>q>>r;
        fill(A,A+p,0);
        fill(B,B+q,0);
        fill(C,C+r,0);
       

        for(int i=0;i<p;i++)
            cin>>A[i];
        for(int i=0;i<q;i++)
            cin>>B[i];
        for(int i=0;i<r;i++)
            cin>>C[i];
        

long long s =0,s1 =0,s2 =0;

for(int i=0;i<q;i++){
    s1=0;
    s2=0;
    for(int j=0;j<p;j++){
        if(B[i]>=A[j]){
            s1 =  (s1 +(B[i]+A[j])%mod)%mod;
        }
}
    for(int j=0;j<r;j++){
        if(B[i]>=C[j]){
            s2 =  (s2 +(B[i]+C[j])%mod)%mod;
        }
}

s = (s+(s1*s2)%mod)%mod;

}

        cout<<s<<endl;
    }
    return 0;
}