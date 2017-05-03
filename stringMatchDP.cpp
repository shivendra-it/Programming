#include<bits/stdc++.h>
using namespace std;

int len(char *A, char *B,int l1,int l2){
 
    if(A.length() == 0 || B.length()==0)
        return 0;
    if(A[l1-1]==B[l2-1])
        return 1;

    unordered_map<string,string> um;

    string key = 

    return len;
}

int main(){
char A[] = "APPLE";
char B[] = "APPS";
int l1=strlen(A),l2=strlen(B);
cout<<len(A,B,l1,l2);
    return 0;
}