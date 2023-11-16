#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
typedef long long ll;
using namespace std;
#define fr first
#define sc second
int vis[105] = {0};
vector<pair<int, int>> adj[105];
bool dfs(int src, int col, int dst)
{
	vis[src] = 1;
	if (src == dst)
		return true;
	for (auto it : adj[src])
	{
		if (it.sc == col && vis[it.fr] == 0)
		{
			if (dfs(it.fr, it.sc, dst))
				return true;
		}
	}
	return false;
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
	cin >> n >> m; //nodes , edges.
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c; //nodea,nodeb,wt
		--a; --b; --c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	int q;
	cin >> q;

	for (int i = 0; i < q; i++)
	{
		int res = 0;
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		for (int i = 0; i <= m; i++)
		{
			memset(vis, 0, sizeof(vis));
			if (dfs(u, i, v))
				res++;
		}
		cout << res << endl;
	}
	return 0;

}