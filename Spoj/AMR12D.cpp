#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;
    cin>>t;
    while(t--){
        char s[18],s1[18];
        scanf("%s",s);
       // cout<<s<<endl;
        int l = strlen(s);
        int i,j;
        for(i=l-1,j=0; i>=0;i--,j++){
            s1[j] = s[i];
        }
        s1[j]='\0';
       // cout<<s1<<endl;
        if(!(strcmp(s1,s)))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;   
}