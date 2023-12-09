//AC

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
using namespace std;
int n;
vl arr;
ll res;
ll fms(int l, int r)
{
    ll cursum = 0;
    ll val = INT_MIN;
    for (int i = l; i <= r; i++)
    {
        cursum += arr[i];
        val = max(val, cursum);
        if (cursum < 0)
            cursum = 0;
    }
    return val;
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
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        res = 0;
        arr.resize(n, 0);
        ll maxi = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
        }
        if (maxi < 0)
        {
            cout << maxi << endl;
            continue; //for the case when we have all the array numbers to be<0
        }
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (abs(arr[i] % 2) == abs((arr[i - 1] % 2)))
            {
                ll cur = fms(prev, i - 1);
                res = max(res, cur);
                prev = i;
            }
        }
        res = max(res, fms(prev, n - 1));
        cout << res << endl;
    }
    return 0;
}