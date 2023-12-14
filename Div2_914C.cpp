#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define LLMAX LLONG_MAX;
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
    ll n, k;
    ci(n); ci(k);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    if (k >= 3)
    {
        co(0);
        co(nl);
    }
    std::sort(arr.begin(), arr.end());
    vl diff(n);
    for (int i = 1; i < n; ++i)
    {
        diff[i] = abs(arr[i] - arr[i - 1]);
    }
    diff[0] = LLMAX;
    ll mini = arr[0];
    for (auto it : diff)
    {
        mini = min(it, mini);
    }

    if (k == 1)
    {
        co(mini); co(nl);
    }
    else if (k == 2)
    {
        ll res = mini;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n ; ++j)
            {
                ll cur = abs(arr[j] - arr[i]);
                ll curans = min(cur, mini);
                ll op1 = std::lower_bound(arr.begin(), arr.end(), cur) - arr.begin();
                ll op2 = op1 - 1;
                if (op1 < n)
                {
                    curans = min(curans, arr[op1] - cur);
                }
                if (op2 >= 0)
                {
                    curans = min(curans, cur - arr[op2]);
                }
                res = min(res, curans);
            }
        }
        co(res); co(nl);
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
    int t;
    ci(t);
    while (t--)
    {
        solve();
    }
}