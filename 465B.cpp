#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define r0 return 0;
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
    vi arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    ll res = 0;
    int j = 0;
    int lastind = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] == 1)
        {
            lastind = i;
            break;
        }
    }
    while (j < n)
    {
        if (arr[j] == 1)
        {
            res += 1;
            j++;
            while (j < n && arr[j] == 1)
            {
                j++;
                res++;
                // co(res); co(" ");
            }
            // co(nl);
            if (j >= lastind)
                break;
            else
                res += 1;
        }
        else
        {
            j++;
        }
    }
    co(res); co(nl);
    r0;
}