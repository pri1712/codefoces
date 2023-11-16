#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
const int maxi = 150123;
//#include <map>
using namespace std;
vector<bool> vis(maxi, 0);
vector<int> adj[maxi];
typedef long long ll;
void dfs(int& edges, int& numnodes, int node)
{
    vis[node] = 1;
    numnodes += 1;
    edges += adj[node].size();
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(edges, numnodes, it);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }//making the adjacency matrix.
    //vis.resize(n + 2, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int cur_nodes = 0;
            int cur_edges = 0;
            dfs(cur_edges, cur_nodes, i);
            if (cur_edges != (ll)cur_nodes * (cur_nodes - 1))
            {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    return 0;
}