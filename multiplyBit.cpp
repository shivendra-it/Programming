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
return su|carryin;
}

long sum1(long a,long b){
    return a+b;
}

long mul(long a,long b){
    long s =0;
    while(a != 0){
        if((a & 1)!= 0){
        s += sum1(s,b); 
        }
        a = a >> 1;
        b = b << 1;
    }
return s;
}

int main(){
    long a,b;
    cin>>a>>b;
    cout<<mul(a,b)<<endl;    
    return 0;
}