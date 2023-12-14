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
typedef std::vector<std::pair<int, int>> vp;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
const int MAXI = 1e5;
ll f[MAXI];
bool maxcountsort(pp a, pp b)
{
    if (a.second != b.second)
        return a.second > b.second;
    else
        return a.first > b.first;
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
    ci(n);
    vp arr;
    map <int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int x;
        ci(x);
        mp[x]++;
    }
    for (auto it : mp)
    {
        arr.push_back({it.first, it.second}); //num, freq.
    }
    for (int i = 0; i < (int)arr.size(); ++i)
    {
        int pr = i - 1;
        while (pr >= 0 && arr[pr].first == arr[i].first - 1)
        {
            //is the prev element
            pr--;
        }
        if (pr <= -1)
        {
            f[i] = (ll)arr[i].first * arr[i].second;
        }
        else
        {
            f[i] = (ll)f[pr] + (ll)arr[i].first * arr[i].second;
        }
        if (i > 0)
        {
            f[i] = max(f[i], f[i - 1]);
        }
    }
    ll points = f[arr.size() - 1];
    cout << points << nl;
    return 0;
}