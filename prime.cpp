#include<bits/stdc++.h>
using namespace std;
vector<int> allPrimes(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
int n = sqrt(A);
    vector<int>arr;
    if(A<2)
        return arr;
    int arr1[A+1];
    fill(arr1,arr1+A+1,0);
    for(int i=2;i<=sqrt(A);i++){
        for(int j=2;j*i<=A;j++){
            arr1[i*j] = 1;
            
        }
    }
  
    for(int i=2;i<=A;i++){
        if(arr1[i]==0){
            arr.push_back(i);
    
        }
    }
return arr;
}
int main(){
    int n;
    cin >> n;
vector<int> Solution;
Solution = allPrimes(n);
for(int i=0;i != Solution.size();i++){
    cout<<Solution[i]<<" ";
}
    return 0;
}

