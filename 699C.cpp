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
ll dp[105][3];
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
    for (int i = 1; i <= n; ++i)
    {
        int x;
        cin >> x;
        dp[i][0] = min({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}) + 1;
        if (x == 1 || x == 3)
        {
            //choosing to give contest
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        else
        {
            dp[i][1] = dp[i - 1][1] + 1;
        }
        if (x == 2 || x == 3)
        {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
        else
        {
            dp[i][2] = 1 + dp[i - 1][2];
        }
        // cout << "hi" << i << nl;
    }
    ll res = min({dp[n][0], dp[n][1], dp[n][2]});
    cout << res << nl;

    return 0;
}