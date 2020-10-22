#include<bits/stdc++.h>
using namespace std;


int min(int a, int b)
{
    if(a < b)
        return a;
    return b;
}




void prims(vector<pair<int, int>> adj[], int src, int v)
{
    vector <bool> visit(v, false);
    vector <int> parent(v, INT_MAX);
    vector <int> weight(v, INT_MAX);
    priority_queue <int, vector<int>, greater<int>> pq;

    parent[src] = -1;
    weight[src] = 0;
    
    pq.push(src);
   
   
    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
        visit[u] = true;
        for(auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            if(visit[i -> first])
                continue;
            weight[i -> first] = min(weight[i -> first], i -> second);
            parent[i -> first] = u;
            pq.push(i -> first);
        }
    }
    
    for(int i = 0; i < v; i++)
    {
        
        if(i == src)
            continue;
        cout<< parent[i] << " -> " << i <<" weight " << weight[i] << endl;
    }
   
    
}

void addEdge(vector<pair<int, int>> adj[], int src, int dest, int weight)
{
    adj[src].push_back(make_pair(dest, weight));
    adj[dest].push_back(make_pair(src, weight));
}


int main()
{
    vector<pair<int, int>> adj[5];
    addEdge(adj, 0, 1, 4);
    addEdge(adj, 0, 2, 8);
    addEdge(adj, 1, 2, 2);
    addEdge(adj, 2, 3, 3);
    addEdge(adj, 2, 4, 9);
    addEdge(adj, 1, 3, 6);
    addEdge(adj, 3, 4, 6);
    prims(adj, 0, 5);
}