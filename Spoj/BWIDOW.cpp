#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    int a,b,n;
    while (t--)
    {

    int maxa= -1, maxb =-1,ia=-1,ib=-1;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a>>b;
            if(a>maxa){
                maxa =a;
                ia=i;
            }  
             else if(b>maxb){
                maxb =b;
            }
        }
       // cout<<"maxa "<<maxa<<" "<<"maxb "<<maxb<<" "<<"maxb2 "<<maxb2<<" "<<"ia "<<ia<<" "<<"ib "<<ib<<" "<<endl;
        if(maxa>maxb){
                cout<<ia<<endl;
        }
        else
        {
                    cout<<"-1"<<endl;
                }               
            
    
        
    }

    return 0;
}