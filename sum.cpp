#include<bits/stdc++.h>
using namespace std;

int add(int a, int b){
    cout<<" a = "<<a<<" b = "<<b<<endl;
    return b==0?a:add(a^b, (a&b)<<1);
}

int main(){
    cout<<add(208,909)<<endl;
    return 0;
}
