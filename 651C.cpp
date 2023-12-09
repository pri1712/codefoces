#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    ci(n);
    unmap xmap;
    unmap ymap;
    map < pair<int, int>, int> mp;
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        ll x, y;
        cin >> x >> y;
        res += xmap[x];
        xmap[x]++;
        res += ymap[y];
        ymap[y]++;
        res -= mp[ {x, y}];
        mp[ {x, y}]++;
    }
    cout << res << nl;
    return 0;
}