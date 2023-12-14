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
    int n, k;
    ci(n);
    ci(k);
    vi arr(k + 1);
    for (int i = 0; i < n; ++i)
    {
        int x;
        ci(x);
        arr[x]++;
    }
    ll coins = 0;
    while (arr[k] < n)
    {
        coins++;
        for (int j = k - 1; j > 0; j--)
        {
            if (arr[j] > 0)
            {
                arr[j]--;
                arr[j + 1]++;
            }
        }
    }
    cout << coins << nl;
    return 0;
}