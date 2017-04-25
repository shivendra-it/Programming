#include<bits/stdc++.h>
using namespace std;

long sum(long a,long b){
    long su = 0, carryin = 0, k = 1, tempA = a, tempB = b;
    while(tempA != 0 || tempB != 0) {
        long ak = a & k, bk = b & k ;
        long carryout = (ak & bk) | (ak & carryin)|(bk & carryin);
        su |= (ak ^ bk ^ carryin);
        carryin = carryout << 1;
        k <<= 1 ;
        tempA >>= 1 ;
        tempB >>= 1 ;
    }
    return su|carryin;x
}



long mul(long a,long b){
    long s =0;
    while(a != 0){
        if(a&1)
        s = sum(s,b); 
        a >>= 1;
        b <<= 1;
        cout<<"s = "<<s<<" a = "<<a<<" b = "<<b<<endl;
    }
return s;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long a,b;

    freopen("in.txt","r",stdin);
    cin>>a>>b;
    cout<<mul(a,b)<<endl; 
    freopen("out.txt","w",stdout);   
    return 0;
}