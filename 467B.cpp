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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    vi findxor(m);
    vi arr(m + 1);
    for (int i = 0; i <= m; i++)
    {
        cin >> arr[i]; //fedor is the last
    }
    for (int i = 0; i <= m - 1; i++)
    {
        findxor[i] = arr[i] ^ arr[m];
    }
    // for (auto it : findxor)
    //     cout << it << endl;
    ll res = 0;
    for (int i = 0; i <= m - 1; i++)
    {
        int curones = 0;
        int cur = findxor[i];
        for (int j = 31; j >= 0; j--)
        {

            if ((1 << j)&cur)
                curones++;
        }
        if (curones <= k)
            res++;
    }
    cout << res << endl;
    return 0;
}