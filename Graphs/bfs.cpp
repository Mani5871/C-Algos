#include<bits/stdc++.h>
using namespace std;

void bfs(vector<int> adj[], int v, int n)
{
    queue<int> q;
    vector<bool>visit(n, false);
   
    visit[v] = true;
    q.push(v);
   
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        cout<<node<<" ";
       
        for(auto i = adj[node].begin(); i != adj[node].end(); i++)
            if(!visit[*i])
            {
                visit[*i] = true;
                q.push(*i);
            }
    }
   
}

int main() {
    vector<int> adj[4];
    addEdge(adj, 0, 1, 10);
    addEdge(adj, 0, 4, 20);
    addEdge(adj, 1, 2, 30);
    addEdge(adj, 1, 3, 40);
    addEdge(adj, 1, 4, 50);
    addEdge(adj, 2, 3, 60);
    addEdge(adj, 3, 4, 70);
    print(adj, 4);
    dfs(adj, 2, 4);
    cout<<endl;
    bfs(adj, 2, 4);
}