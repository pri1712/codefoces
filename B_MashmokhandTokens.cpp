#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, a, b;
    cin >> n >> a >> b;
    // ll arr[n];
    // ll res[n];
    for (int i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        cout << (x * a) % b << " ";
    }
    // int rem = (a / b);
    // for (int i = 0; i < n; ++i)
    // {
    //     int p = floor(arr[i] * rem);
    //     int t = ceil(p / rem);
    //     res[i] = arr[i] - t;
    // }
    // for (auto it : res)
    //     cout << it << " ";
    return 0;
}