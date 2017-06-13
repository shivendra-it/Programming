#include<bits/stdc++.h>
using namespace std;

int A[200007];
int B[200007];

int main()
{
    int n;
    cin>>n;
    
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>B[i];
    }
    
    map<int,int> m;
    map<int,int> :: iterator mi;

    for(int i=0;i<n;i++){
        mi = m.find(i);
        if(mi == m.end()){
            m[i] = A[i];
        }
        else{
             m[i]
        }
    }
    return 0;
}
