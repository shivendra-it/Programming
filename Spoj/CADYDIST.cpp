#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long b[100005];
int main(){

    while (1)
    {
        long long n;
        cin>>n;
        if(n==0){
            return 0;
        }
        for(long long i =0;i<n;i++){
            cin>>a[i];
        }

        for(long long i =0;i<n;i++){
            cin>>b[i];
        }

        sort(a,a+n);
        sort(b,b+n);

        unsigned long long sum =0;
        for(long long i =0;i<n;i++){
            sum += a[i]*b[n-1-i];
        }
        cout<<sum<<endl;
    }


    return 0;
}