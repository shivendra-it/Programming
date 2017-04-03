#include<bits/stdc++.h>
using namespace std;

vector<int> vi[100];
int n;

int visited[100];

void DFS(int sou){
    
    visited[sou]=1;
    
        cout<<sou<<" "; 
        for(int i=0;i!=vi[sou].size() ;i++){
            
            if(visited[vi[sou][i]]!=1) {
                DFS(vi[sou][i]);
            }
        }
    }

void DFS1(int sou){
    stack<int> s;
    s.push(sou);
    visited[sou]=1;

    while(!s.empty()){
        int k = s.top();
        cout<<k<<"   ";
        visited[sou]=1;
        s.pop();
        for(int i=0;i!=vi[k].size();i++){
            if(visited[sou]!=1){
            s.push(vi[k][i]);
            visited[vi[k][i]] = 1;
        }
        }
    }
}


int main(){
    int e,a,b;
    cin>>n;
    cin>>e;
    for(int i=0;i<e;i++){
        cin>>a>>b;
        vi[a].push_back(b);
        vi[b].push_back(a);
    }
fill(visited,visited+n,0);
    DFS(0);
    fill(visited,visited+n,0);
    DFS1(0);
    return 0;
}