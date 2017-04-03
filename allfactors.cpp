#include<bits/stdc++.h>
using namespace std;
vector<int> allFactors(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
vector<int> Solution1;
int n = sqrt(A);
for(int i=1;i<=n;i++){
    if(A%i == 0){
        Solution1.push_back(i);
        if(A/i != i){
        Solution1.push_back(A/i);
        }
    }
}
sort(Solution1.begin(),Solution1.end());
return Solution1;
}
int main(){
    int n;
    cin >> n;
vector<int> Solution;
Solution = allFactors(n);
for(int i=0;i != Solution.size();i++){
    cout<<Solution[i]<<" ";
}
    return 0;
}

