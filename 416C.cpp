#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool descpay(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b)
{
    return a.second.second > b.second.second;
}
bool ascsize(pp a, pp b)
{
    return a.second < b.second;
}
bool canfit(pp b, pair<int, pair<int, int>> a)
{
    return a.second.first > b.second;
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
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> v;
    vp res;
    //store {id,{c,p}} in the vector v.
    for (int i = 0; i < n; ++i)
    {
        int c, p;
        cin >> c >> p;
        v.push_back({i + 1, {c, p}});
    }
    std::sort(v.begin(), v.end(), descpay);
    // for (auto it : v)
    // {
    //     cout << it.first << " " << it.second.first << " " << it.second.second << endl;
    // }
    int k;
    cin >> k;
    vp tables;
    for (int i = 0; i < k; ++i)
    {
        //  cin >> tables[i];
        int cur;
        cin >> cur;
        tables.push_back({i + 1, cur});
    }
    std::sort(tables.begin(), tables.end(), ascsize);
    // for (auto it : tables)
    // {
    //     cout << it.first << " " << it.second << endl;
    // }
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        auto cur = v[i];
        auto tablepossible = std::lower_bound(tables.begin(), tables.end(), cur, canfit);
        if (tablepossible == tables.end())
            continue;
        sum += cur.second.second;
        res.push_back({cur.first, tablepossible->first});
        tables.erase(tablepossible);
    }
    cout << res.size() << " " << sum << endl;
    for (auto it : res)
    {
        cout << it.first << " " << it.second << endl;
    }
    return 0;
}