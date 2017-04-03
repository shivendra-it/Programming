#include<bits/stdc++.h>
using namespace std;

class Graph{
    
    int V;
    list<pair<int,int> > *adj;

    public:
    Graph(int V);
    
    void addEdge(int u,int v,int w);

    vector<int> shortestPath(int s);

};


Graph::Graph(int V){
    this->V = V;
    adj = new list<pair<int,int> >[V];
}

void Graph::addEdge(int u,int v,int w){
    adj[u].push_back(make_pair(v,w));
}

vector<int> Graph::shortestPath(int s)