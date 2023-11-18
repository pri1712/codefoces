#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
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
    int d;
    cin >> n >> d;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        bool ok = true;
        if (!((x - y) <= d && (x - y) >= -d))
            ok = false;
        if (!((x + y) <= n + n - d && (x + y) >= d))
            ok = false;
        if (ok)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;

}