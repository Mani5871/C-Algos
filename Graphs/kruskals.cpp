#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int src, dest, wt;
};


bool compare(Graph g1, Graph g2)
{
    return g1.wt < g2.wt;
}

int findparent(int *parent, int v)
{
    if(parent[v] == v)
        return v;
    return findparent(parent, parent[v]);
}


void kruskals(Graph *adj, int v, int e)
{
    sort(adj, adj + v, compare);
    Graph *final = new Graph[v - 1];
    int *parent = new int[v];
   
    for(int i =0; i < v; i++)
        parent[i] = i;
   
    int cnt = 0, i = 0;
   
    while(cnt != v - 1)
    {
        Graph edge = adj[i];
       
        int srcparent = findparent(parent, edge.src);
        int destparent = findparent(parent, edge.dest);
       
        if(srcparent != destparent)
        {
            final[cnt++] = edge;
            parent[srcparent] = destparent;
        }
        i++;
    }
   
    for(i = 0; i < v-1; i++)
    {
        if(final[i].src < final[i].dest)
            cout << final[i].src << " " << final[i].dest << " " << final[i].wt << endl;
        else
            cout << final[i].dest << " " << final[i].src << " " << final[i].wt << endl;
    }
   
   
}