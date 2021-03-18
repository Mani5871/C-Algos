#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int>heru;
unordered_map<char, int>path;
vector<char>order;
typedef pair<int, char>pi;
int cost;

void addheru(char src, int cost)
{
    heru[src] = cost;
}

void addEdge(vector<pi> adj[], char src, char des, int wt)
{
    adj[src].push_back(make_pair(wt, des));
}

void Astar(vector<pi> adj[], char src, char goal)
{
    priority_queue<pi, vector<pi>, greater<pi>>pq;

    pq.push(make_pair(0, src));

    while(!pq.empty())

    {
        pi node = pq.top();
        order.push_back(node.second);
        pq.pop();

        if(node.second == goal)
        {
            cost = node.first;
            return;
            if(node.first < pq.top().first)
                return;
        }
        
        src = node.second;
        int i = 0, j, k, n = adj[src].size();
        
        for(auto it = adj[src].begin(); it ++)
        {
            int cost1 = it -> first + heru[it -> second] - heru[src] + node.first;
            i ++;
            
            pq.push(make_pair(cost1, it -> second));
            
            if(i >= n)
                break;
        }
    }

    
}

int main()
{
    vector<pair<int, char>> adj[10];
    addEdge(adj, 'A', 'B', 11);
    addEdge(adj, 'A', 'C', 14);
    addEdge(adj, 'A', 'D', 7);
    addEdge(adj, 'B', 'E', 15);
    addEdge(adj, 'C', 'E', 8);
    addEdge(adj, 'C', 'F', 10);
    addEdge(adj, 'C', 'D', 8);
    addEdge(adj, 'D', 'F', 25);
    addEdge(adj, 'E', 'H', 9);
    addEdge(adj, 'F', 'G', 20);
    addEdge(adj, 'H', 'G', 10);

    addheru('A', 0);
    addheru('B', 32);
    addheru('C', 25);
    addheru('D', 35);
    addheru('E', 19);
    addheru('F', 19);
    addheru('G', 0);
    addheru('H', 10);
    
    
    

    Astar(adj, 'A', 'G');

    cout << cost << endl;
    
    for(int i = 0; i != order.size(); i ++)
        cout << order[i] <<" ";
}
