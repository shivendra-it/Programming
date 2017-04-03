#include<bits/stdc++.h>
using namespace std;

long long next_possible_square_no(long long area){
   
    for(long long i = area; ;i++){
        long long sq = sqrt(i);
        if(sq * sq == i){
            if(!(i%area))
                return sq;
        }
    }

}



long long gcd(long long a,long long b){
    if(b==0)
    return a;
    else
    return gcd(b,a%b);
}

int main(){
    while(1){
        long long l,b;
        cin>>l>>b;
        if(l==0 || b==0)
            return 0;

        long long gc = gcd(l,b);
       long long lc = abs(l * b) / gc; 
      
       cout<<((lc/l)*(lc/b))<<endl;

    }
    return 0;
}