#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
bool vis[51][51] = {0};
char adj[51][51];
bool ok = 0;
int delx[] = { -1, 1, 0, 0};
int dely[] = {0, 0, -1, 1};
int n, m;
//vector<int> vis()
void dfs(int i, int j, char& col, int parentx, int parenty)
{
    if (adj[i][j] != col)
    {
        return;
    }
    if (vis[i][j])
    {
        ok = 1;
        return;
    }
    vis[i][j] = 1;
    for (int cur = 0; cur < 4; cur++)
    {
        int nextx = delx[cur] + i;
        int nexty = dely[cur] + j;
        if (nextx == parentx && nexty == parenty)
            continue;
        if (nextx >= 1 && nexty >= 1 && nexty <= m && nextx <= n) //within valid boundary
        {
            dfs(nextx, nexty, col, i, j);
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
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> adj[i][j];
        }
    }
    int parentx = -1;
    int parenty = -1;
    char col;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            col = adj[i][j]; //storing the colour.
            if (!vis[i][j])
            {
                dfs(i, j, col, parentx, parenty);
                if (ok)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
    return 0;

}