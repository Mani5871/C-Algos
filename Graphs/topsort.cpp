#include <bits/stdc++.h>
using namespace std;

// vector<bool>visit;
// vector<int>ans;

void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].emplace_back(v);
 	adj[v].emplace_back(u);
}


void topo_sort(vector<int>adj[], int n, int u, vector<bool>& visit, vector<int>& ans)
{
	
	visit[u] = true;

	for(auto i = adj[u].begin(); i != adj[u].end(); i ++)
		if(visit[*i] == false)
			topo_sort(adj, n, *i, visit, ans);
	
	ans.emplace_back(u);

}

int main() {
    vector<int> graph[5];
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 2, 4);
    vector<bool>visit(5, false);
    vector<int>ans;
    
    topo_sort(graph, 5, 0, visit, ans);
    
    for(int i = ans.size() - 1; i >= 0; i --)
        cout << ans[i] << " ";
    
}