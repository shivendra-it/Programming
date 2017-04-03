#include<bits/stdc++.h>
using namespace std;
int isPrime(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A<2)
        return 0;
    int n = sqrt(A);
    for(int i=2;i<=n;i++){
        if(A%i==0){
            return 0;
        }
    }
return 1;
}
int main(){
    int n;
    cin>>n;
    cout<<isPrime(n)<<endl;
    return 0;
}