
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
typedef long long ll;
using namespace std;
#define fr first
#define sc second
vector<bool> vis;
//vector<pair<int, int>> adj[105];
void dfs(vector<vector<int>>& adj, int src)
{
	vis[src] = 1;
	for (auto it : adj[src])
	{
		if (!vis[it])
		{
			dfs(adj, it);
		}
	}
	return;
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
	vector<vector<int>> adj (n + 1, vector<int>(m + 1, 0));
	vis.resize(n, 0);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int conncomp = 0;
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			conncomp++;
			dfs(adj, i);
		}
	}
	ll res = pow(2, n - conncomp);
	cout << res << endl;
	return 0;
}