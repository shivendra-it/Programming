#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while (t--)
    {
        stack<int> ss;
        stack<char> cs;
        int n,ans=0;
        char c;
        while(scanf("%d%c",&n,&c)){
                    ss.push(n);
                    cs.push(c);
        }
        while(!ss.empty()){
        int n1 = ss.top();
        ss.pop();
        char c1= cs.top();
        cs.pop();
        cout<<n1<<"   "<<c1<<endl;
        }
cout<<ans<<endl;
    }

    return 0;
}