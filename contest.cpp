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
    

    for(int i=0;i<n;i++){
        if(m.find(A[i] == m.end()){
            m[A[i]] = i;
        }
        m.insert()
    }
    return 0;
}
