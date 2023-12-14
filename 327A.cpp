#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define r0 return 0;
typedef std::string st;
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
    vi cur(n);
    ll count = 0;
    for (int i = 0; i < n; ++i)
    {
        ci(cur[i]);
        if (cur[i] == 1)
            count++;
    }
    ll res = -1;
    ll sum = 0;
    for (int i = 0; i < n; ++i)
    {
        if (cur[i] == 0)
        {
            sum++;
        }
        else
            sum--;
        res = max(res, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << res + count << nl;
    r0;
}