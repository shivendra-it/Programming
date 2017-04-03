#include<bits/stdc++.h>
using namespace std;
string findDigitsInBinary(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
string s="";
while(A){
    if(A%2)
    s="1"+s;
    else
    s="0"+s;
    A/=2;
}
return s;
}
int main(){
    int n;
    cin >> n;
string Solution;
Solution = findDigitsInBinary(n);
cout<<Solution<<" ";
    return 0;
}

