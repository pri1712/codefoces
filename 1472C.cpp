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
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
void solve()
{
    int n;
    ci(n);
    vi arr(n);
    vl dp(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        // int cur = arr[i];
        int j = i + arr[i];
        if (j < n)
        {
            dp[i] += dp[j];
        }
    }
    // for (auto it : dp)
    // {
    //     cout << it << " ";
    // }
    auto it = std::max_element(dp.begin(), dp.end());
    ll res = *it;
    cout << res << nl;
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
    int t;
    ci(t);
    while (t--)
    {
        solve();
    }
}