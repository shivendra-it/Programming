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

vector<int> primesum(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
vector<int> arr;
  
    for(int i=2;i<=A;i++){
        if(isPrime(i)==1){
            int a = i;
            int b = A-i;
    if(a<=b){
        if(isPrime(b)==1)
        {
            arr.push_back(a);
            arr.push_back(b);
            return arr;
        }
    }
        }
    }
return arr;
}
int main(){
            int n;
            cin >> n;
        vector<int> Solution;
        Solution = primesum(n);
        for(int i=0;i != Solution.size();i++){
            cout<<Solution[i]<<" ";
        }
            return 0;
}