#include<bits/stdc++.h>
using namespace  std;

int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int c,d,l;
        cin>>c>>d>>l;
        int p = 0;
        if(l%4 != 0)
        {
            p=0;
        }else{
            if(l==0 && (c!=0 && d!=0)){
                p=0;
            }else{
                int extleg = l-4*d;
                int catsonground = extleg/4;
                int catsondog = c - catsonground;
                if(catsondog < 2*d && catsondog >= 0){
                    p=1;
                }else{
                    p=0;
                }
            }
        }
        
        if(p == 1){
            cout<<"yes"<<endl;
        }else{
            cout<<"no"<<endl;
        }
    }
    return 0;
}