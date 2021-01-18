#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int> adj[], int v, int n)
{
    static vector<bool>visit(n, false);
   
    visit[v] = true;
    cout<<v<<" ";
   
    for(auto i = adj[v].begin(); i != adj[v].end(); i++)
        if(!visit[*i])
            dfs(adj, *i, n);
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