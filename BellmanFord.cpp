#include<bits/stdc++.h>
using namespace std;

int N;
int E;

struct edge{
    int u;
    int v;
    int wt;
};

void printPath(int parent[], int v)
{
	if (v < 0)
		return;

	printPath(parent, parent[v]);
	cout << v << " ";
}

void BellmanFord(vector<edge> &edges,int source){
    int distance[N];
    int parent[N];
    
    for(int i=0;i<N;i++){
        parent[i] = -1;
        distance[i] = INT_MAX;
    }

    distance[source] = 0;

    int k = N;

    while(--k){
        for(int i=0;i<N;i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int wt = edges[i].wt;
            if(distance[u]!=INT_MAX && distance[u] + wt < distance[v]){
                distance[v] = distance[u] + wt;
                parent[v] = u;
            }
        }
    }
            for(int i=0;i<N;i++){
            int u = edges[i].u;
            int v = edges[i].v;
            int wt = edges[i].wt;
            if(distance[u]!=INT_MAX && distance[u] + wt < distance[v]){
               cout<<"Negative Cycle"<<endl;
               return;
            }
         }

    for (int i = 0; i < N; i++)
        {
            cout << "Distance of vertex " << i << " from the source is " 
                << setw(2) << distance[i] << ". It's path is \" ";
                printPath(parent, i); cout << "\"" << endl;
        }

}

int main(){
    cin>>N;
    vector<edge> edges;
    struct edge ed;
    cin>>E;
    for(int i=1;i<=E;i++){
    scanf("%d%d%d",&ed.u,&ed.v,&ed.wt);
    edges.push_back(ed);
    }

    // for(int i=1;i<=E;i++){
    // printf("%d %d %d",edges[i-1].u,edges[i-1].v,edges[i-1].wt);
    // }

    int start = 0;

    BellmanFord(edges,start);

    return 0;
}




// { 0, 1, -1 }, { 0, 2, 4 }, { 1, 2, 3 }, { 1, 3, 2 },
// 		{ 1, 4, 2 }, { 3, 2, 5 }, { 3, 1, 1 }, { 4, 3, -3 }