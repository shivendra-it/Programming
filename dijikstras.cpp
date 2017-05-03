#include<bits/stdc++.h>
using namespace std;

//  Dijkstra is good for graphs non-negative edges.

// O(Vlog(E)) (?)


void dijkstra(int s) {
    map<int, queue<int>> m;
    dist[s] = 0;
    m[0].push(s);
    while (m.size()) {
        if (!m.begin()->second.size()) {
            m.erase(m.begin());
            continue;
        }
        int cur = m.begin()->second.front();
        m.begin()->second.pop();
        if (done[cur]) continue;
        done[cur] = true;
        SHOW(cur, dist[cur])
        for (int next : children[cur]) {
            if (!done[next] && dist[next] > dist[cur] + edge[cur][next]) {
                dist[next] = dist[cur] + edge[cur][next];
                prev[next] = cur;
                m[dist[next]].push(next);
            }
        }
    }
    cout << endl;
}

struct cmp {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
};

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    q.push(make_pair(0, s));
    dist[s] = 0;
    while (q.size()) {
        int cur = q.top().second;
        q.pop();
        if (done[cur]) continue;
        done[cur] = true;
        SHOW(cur, dist[cur])
        for (int next : children[cur]) {
            if (!done[next] && dist[next] > dist[cur] + edge[cur][next]) {
                dist[next] = dist[cur] + edge[cur][next];
                q.push(make_pair(dist[next], next));
                prev[next] = cur;
            }
        }
    }
}