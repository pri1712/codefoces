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
ll n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> n;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    unordered_map<int, ll> count;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        count[x]++;
        maxi = max(maxi, x);
        mini = min(mini, x);
    }
    if (maxi == mini)
    {
        cout << 0 << " " << n*(n - 1) / 2 << endl;
        return 0;
    }
    else
    {
        ll maxc = count[maxi];
        ll minc = count[mini];
        ll res = maxc * minc;
        cout << maxi - mini << " " << res  << endl;
        return 0;
    }
    return 0;
}