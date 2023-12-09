#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x1, y1, x0, y0;
    cin >> x0 >> y0;
    cin >> x1 >> y1;
    int x, y = 0;
    queue<pp> q;
    map<pp, ll> dist; //distances of points
    map<pp, bool> allow;
    map<pp, bool> vis;
    allow[ {x0, y0}] = 1;
    allow[ {x1, y1}] = 1;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int r, a, b;
        cin >> r >> a >> b;
        for (int j = a; j <= b; j++)
        {
            allow[ {r, j}] = 1;
        }
    }
    dist[ {x0, y0}] = 0;
    q.push({x0, y0});
    int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1};
    int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    while (!q.empty())
    {
        pp cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            x = cur.first + dx[i];
            y = cur.second + dy[i];
            if (allow[ {x, y}] && !vis[ {x, y}])
            {
                if (!dist[ {x, y}] || dist[ {x, y}] > dist[ {cur.first, cur.second}] + 1)
                {
                    dist[ {x, y}] = dist[ {cur.first, cur.second}] + 1;
                    q.push({x, y});
                }
            }
        }
        vis[ {cur.first, cur.second}] = 1;

    }
    if (vis[ {x1, y1}])
    {
        cout << dist[ {x1, y1}];
        return 0;
    }
    cout << -1 << endl;
    return 0;

}