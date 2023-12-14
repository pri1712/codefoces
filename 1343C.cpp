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
int sign(ll& x)
{
    if (x >= 0)
    {
        return 1;
    }
    else
        return -1;
}
void solve()
{
    int n;
    ci(n);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    ll res = 0;
    for (int i = 0; i < n; ++i)
    {
        ll maxi = arr[i];
        int j = i;
        while (j < n && sign(arr[j]) == sign(arr[i]))
        {
            maxi = max(maxi, arr[j]);
            j++;
        }
        i = j - 1;
        res += maxi;
    }
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