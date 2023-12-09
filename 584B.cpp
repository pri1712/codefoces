#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
ll mod = 1e9 + 7;
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
    ll n;
    cin >> n;
    ll all = 1;
    ll cond = 1;
    for (ll i = 0; i < 3 * n; i++)
    {
        all *= 3;
        all %= mod;
    }
    for (ll i = 0; i < n; i++)
    {
        cond *= 7;
        cond %= mod;
    }
    ll res = (all - cond + mod) % mod;
    cout << res << endl;

    return 0;
}