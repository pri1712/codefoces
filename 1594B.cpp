//binary exponentiation

#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int n;
ll mod = 1e9 + 7;
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
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        ll res = 0;
        ll p = 1;
        //kth special term when n is given
        for (int j = 0; j <= 31; j++)
        {
            if (k & (1 << j))
            {
                res = (res + p) % mod;
            }
            p *= n;
            p %= mod;
        }
        cout << res << endl;
    }
    return 0;
}