#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll A[100005];
ll B[100005];
ll C[100005];

ll AA[100005];
ll CC[100005];

long long s =0;
ll FS(ll arr[], ll low, ll high, ll x)
{
    if (low > high)
        return -1;

    if (x >= arr[high])
        return high;
 
    ll mid = (low+high)/2;

    if (arr[mid] == x)
        return mid;

    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;

    if (x < arr[mid])
        return FS(arr, low, mid-1, x);
    return FS(arr, mid+1, high, x);
}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll p,q,r;
        cin>>p>>q>>r;
        fill(A,A+p,0);
        fill(B,B+q,0);
        fill(C,C+r,0);
        fill(AA,AA+p,0);
        fill(CC,CC+r,0);

        for(ll i=0;i<p;i++)
            cin>>A[i];
        for(ll i=0;i<q;i++)
            cin>>B[i];
        for(ll i=0;i<r;i++)
            cin>>C[i];
        
         sort(A,A+p);
         sort(B,B+q);
         sort(C,C+r);


        AA[0]=A[0];
        for(ll i=1;i<p;i++)
            AA[i]=(AA[i-1]+A[i]);

        CC[0]=C[0];
        for(ll i=1;i<r;i++)
            CC[i]=(CC[i-1]+C[i]);
        
        // for(ll i=0;i<p;i++)
        //     cout<<AA[i]<<" ";
        //     cout<<endl;
        // for(ll i=0;i<r;i++)
        //     cout<<CC[i]<<" ";
        //     cout<<endl;

s=0;
if(A[0] > B[q-1] || C[0] > B[q-1])
    s=0;
else{
        for(ll i=0;i<q;i++){

            ll ia = FS(A, 0, p-1, B[i]);
            ll ic = FS(C, 0, r-1, B[i]);

           // cout<<"ia "<<ia<<"  ic "<<ic<<endl;
           // cout<<AA[ia]<<"  "<<CC[ic]<<"  "<<B[i]<<" "<<endl;
            long long p = (AA[ia]%mod + ((ll)(ia + 1)%mod * (ll)B[i]%mod)%mod)%mod;
            long long q = (CC[ic]%mod + ((ll)(ic + 1)%mod * (ll)B[i]%mod)%mod)%mod;
            
            s = (s + (p*q)%mod)%mod;
            
        }
    }
        cout<<s<<endl;
    }
    return 0;
}