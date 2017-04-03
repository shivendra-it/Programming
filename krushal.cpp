#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
vector<pii>G[100001];
bool finished[100001];
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,m,s,u,v,wt;
    cin>>n>>m;
    while(m--)
    {
        cin>>u>>v>>wt;
        G[u].push_back(make_pair(v,wt));
        G[v].push_back(make_pair(u,wt));
    }
    cin>>s;
    priority_queue< pii ,vector< pii >,greater < pii > >Q;
    Q.push(make_pair(0,s));
    m=0;
    while(!Q.empty())
    {
        pii top = Q.top();
        Q.pop();
        if(!finished[top.second])
            {
            m+=top.first;
            finished[top.second]=true;
        }
        for(vector<pii>::iterator it=G[top.second].begin();it!=G[top.second].end();it++)
            if(!finished[it->first])
            Q.push(make_pair(it->second,it->first));
    }
    cout<<m<<endl;
    return 0;
}
