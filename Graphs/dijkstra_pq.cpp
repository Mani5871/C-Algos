#include <iostream>
#include <bits/stdc++.h>
#include <utility>
using namespace std;


void addEdge(vector <pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
}

void dijkstra(vector <pair<int, int>> adj[], int s, int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector <int> dist(n, INT_MAX);
    dist[s] = 0;
    pq.push(s);
   
    while(!pq.empty())
    {
        int u = pq.top();
        pq.pop();
       
        for(auto i = adj[u].begin(); i != adj[u].end(); i++)
        {
            int vertex = i -> first;
            int weight = i -> second;
           
            if(dist[vertex] > dist[u] + weight)
            {
                dist[vertex] = dist[u] + weight;
                pq.push(vertex);
            }
        }
    }
   
    for(int i = 0; i < n; i++)
        cout<<s<<" -> vertex "<<i<<" distance "<<dist[i]<<endl;
}

int main() {
    vector <pair<int, int>> adj[5];
    addEdge(adj, 0, 1, 2);
    addEdge(adj, 0, 2, 4);
    addEdge(adj, 1, 2, 1);
    addEdge(adj, 1, 3, 4);
    addEdge(adj, 1, 4, 5);
    addEdge(adj, 2, 1, 5);
    addEdge(adj, 2, 3, 2);
    addEdge(adj, 2, 4, 3);
    addEdge(adj, 3, 4, 1);
   
    dijkstra(adj, 0, 5);
}

