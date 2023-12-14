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
typedef std::vector<std::pair<ll, ll>> vp;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
const int MAXI = 1e6;
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
    vl points(n + 2);
    vl height(n + 2);
    height[0] = 0;
    height[n + 1] = 0;
    points[0] = INT_MIN;
    points[n + 1] = INT_MAX;
    ll dp[n + 3][3];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        ci(points[i]);
        ci(height[i]);
    }
    // for (auto it : points)
    // {
    //     cout << it << nl;
    // }
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for (int i = 1; i <= n ; ++i)
    {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]}); //stay
        if (points[i] + height[i] < points[i + 1])//fell to right
        {
            dp[i][2] =  1 + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        }
        //fell to left
        if (points[i - 1] < points[i] - height[i])
        {
            dp[i][1] =  max(1 + dp[i - 1][0], 1 + dp[i - 1][1]);
            if (dp[i - 1][2] > 0) //some tree is fallen to right
            {
                if (points[i - 1] + height[i - 1] < points[i] - height[i])
                {
                    dp[i][1] = max(dp[i][1], 1 + dp[i - 1][2]);
                }
            }
        }
    }
    ll res = max({dp[n][0], dp[n][1], dp[n][2]});
    cout << res << nl;
    return 0;
}