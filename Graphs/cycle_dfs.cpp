#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int src, int dest)
{
    adj[src].push_back(dest);
}

bool cycle1(vector<int>adj[], vector<bool>visited, vector<bool>stack, int src)
{
    visited[src] = true;
    stack[src] = true;
   
    for(auto i = adj[src].begin(); i != adj[src].end(); i++)
    {
        if(!visited[*i] && cycle1(adj, visited, stack, *i))
            return true;
           
        else if(stack[*i])
            return true;
    }
   
    stack[src] = false;
    return false;
}

bool cycle(vector<int>adj[], int v)
{
    vector<bool> visited(v, false);
    vector<bool> stack(v, false);
   
    for(auto i = 0; i < v; i++)
        if(cycle1(adj, visited, stack, i))
            return true;
   
    return false;
}

int main()
{
    vector<int>adj[3];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 0);
    addEdge(adj, 3, 3);
    addEdge(adj, 2, 3);
   
    cout<<cycle(adj, 3);
}