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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int b;
    ci(b);
    vi boys(b);
    for (int i = 0; i < b; ++i)
    {
        cin >> boys[i];
    }
    int g;
    ci(g);
    vi girls(g);
    for (int i = 0; i < g; ++i)
    {
        cin >> girls[i];
    }
    sort(boys.begin(), boys.end());
    sort(girls.begin(), girls.end());
    ll res = 0;
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < g; ++j)
        {
            if (abs(boys[i] - girls[j]) <= 1)
            {
                girls[j] = -100; //taken.
                res++;
                break;
            }
        }
    }
    cout << res << nl;
    return 0;
}