#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b>a)
    {
        int c = a;
        a = b;
        b = c;
    }
    
        int r = 1;
        while(r){
            r = a%b;
            a= b;
            b = r;
        }
    return a;
}

int main(){
    cout<<gcd(24,8);
    cout<<gcd(24,36);
}