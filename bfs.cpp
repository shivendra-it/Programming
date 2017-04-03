#include<bits/stdc++.h>
using namespace std;
/*int arr[1007];
        int brr[1007];
        vector<int>vvi[1007]; */
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n,m,i,a,b,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int arr[n+1];
        int brr[n+1];
        vector<int>vvi[n+1]; 
        for(i=0;i<=n;i++)
            {
            vvi[i].clear();
        }
        for(i=1;i<=m;i++)
            {
            cin>>a>>b;
            vvi[a].push_back(b);
            vvi[b].push_back(a);
             }
        cin>>k;
        b=k;
        memset(arr,0,sizeof arr);
        memset(brr,0,sizeof brr);
        queue<int>q;
        q.push(k);
        arr[k]=0;
        brr[k]=1;
        while(!q.empty())
            {    
         //   cout<<"poop";
            k=q.front();
            q.pop();
         //   cout<<"poop"<<k;
         //   for(int j=0;j<vvi[k].size();j++)
         //       cout<<"j"<<vvi[k][j]<<" ";
            for(int j=0;j<vvi[k].size();j++)
                {
           //     cout<<"adj j "<<vvi[k][j]<<" ";
                if(brr[vvi[k][j]]==0){
                arr[vvi[k][j]]=arr[k]+6;
                
                brr[vvi[k][j]]=1;
                q.push(vvi[k][j]);
                }
                }
           }
        for(i=1;i<=n;i++)
            {
            if(i!=b){
            if(arr[i]!=0)
              cout<<arr[i]<<" ";
           else
              cout<<"-1 ";      
        }
        }
        cout<<endl;
        }
    return 0;
}
