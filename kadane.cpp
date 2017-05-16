#include<bits/stdc++.h>
using namespace std;

int kadane(int arr[],int n){
    int max_overall = 0;
    int max_tillnow = 0;
    for(int i=0;i<n;i++){
        max_tillnow += arr[i];
        if(max_tillnow < 0)
        max_tillnow = 0;

        max_overall = max(max_overall,max_tillnow);
    }
return max_overall;
}

int maxSubArray(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int s_tn=0,m_s=0,f=0;
    
    for(int i=0;i<A.size();i++)
    {
        s_tn+=A[i];
        if(s_tn>m_s){
            m_s=s_tn;
        }
        if(s_tn<0)
            s_tn = 0;
        if(A[i]>0)
            f = 1;
    }
    if(f==0){
         m_s = -99999;
        for(int i=0;i<A.size();i++){
            m_s = max(m_s,A[i]);
        }
    }
    return m_s;
}

int main(){
    int arr[] = {-1,2,3,4,-3,1,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = kadane(arr,n);
    cout<<k<<endl;

    vector<int> A;
    A.push_back(-3); A.push_back(-4); A.push_back(-7); A.push_back(-10); A.push_back(-15);
cout<<maxSubArray(A)<<"   "<<"dfdsfd"<<endl;
    return 0;
}