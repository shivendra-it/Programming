#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll A[100005];
ll B[100005];
ll C[100005];
 
ll AA[100005];
ll CC[100005];
 
ll mod = 1000000007;
int FS(ll arr[], int low, int high, ll x)
{
    if (low > high)
        return -1;
 
    if (x >= arr[high])
        return high;
 
    int mid = (low+high)/2;
 
    if (arr[mid] == x)
        return mid;
 
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;
 
    if (x < arr[mid])
        return FS(arr, low, mid-1, x);
    return FS(arr, mid+1, high, x);
}
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int p,q,r;
        cin>>p>>q>>r;
        fill(A,A+p,0);
        fill(B,B+q,0);
        fill(C,C+r,0);
        fill(AA,AA+p,0);
        fill(CC,CC+r,0);
 
        for(int i=0;i<p;i++)
            cin>>A[i];
        for(int i=0;i<q;i++)
            cin>>B[i];
        for(int i=0;i<r;i++)
            cin>>C[i];
        
         sort(A,A+p);
         sort(B,B+q);
         sort(C,C+r);
 
        // for(int i=0;i<p;i++)
        //     cout<<A[i]<<" ";
        //     cout<<endl;
        // for(int i=0;i<q;i++)
        //     cout<<B[i]<<" ";
        //     cout<<endl;
        // for(int i=0;i<r;i++)
        //     cout<<C[i]<<" ";
        //     cout<<endl;
 
 
        AA[0]=A[0];
        for(int i=1;i<p;i++)
            AA[i]=(AA[i-1]+A[i])%mod;
 
        CC[0]=C[0];
        for(int i=1;i<r;i++)
            CC[i]=(CC[i-1]+C[i])%mod;
        
        // for(int i=0;i<p;i++)
        //     cout<<AA[i]<<" ";
        //     cout<<endl;
        // for(int i=0;i<r;i++)
        //     cout<<CC[i]<<" ";
        //     cout<<endl;
 
long long s =0;
if(A[0] > B[0] || C[0] > B[0])
    s=0;
else{
        for(int i=0;i<q;i++){
 
            // int ia = FS(A, 0, p-1, B[i]);
            // int ic = FS(C, 0, r-1, B[i]);

            auto it1=upper_bound(A,A+p,B[i]);
    		auto it2=upper_bound(C,C+r,B[i]);

            int ia = *it1;
            int ic = *it2;
 
           // cout<<"ia "<<ia<<"  ic "<<ic<<endl;
           // cout<<AA[ia]<<"  "<<CC[ic]<<"  "<<B[i]<<" "<<endl;
            s = (s + ( 
                (AA[ia] * CC[ic])%mod + 
                ((B[i] * AA[ia])%mod * (ic+1))%mod +
                ((B[i] * CC[ic])%mod * (ia+1))%mod + 
                (B[i]* ((((ia+1)*(ic+1))%mod)*B[i])%mod)%mod
                )%mod
                )%mod;
        }
    }
 
 
 
 
        // for(int i=0;i<p;i++){
        //     for(int j=0;j<q;j++){
        //         for(int k=0;k<r;k++){
        //             if(B[j]>=A[i] && B[j]>=C[k])
        //                 {
        //                     s = (s+(((A[i] + B[j])%mod) * ((B[j] + C[k])%mod))%mod)%mod;
        //                 }
        //         }
        //     }
        // }
        cout<<s<<endl;
    }
    return 0;
} 