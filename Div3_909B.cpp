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
ll solve(int k, vl& arr)
{
    ll cur = 0;
    int j = 0;
    int i = 0;
    ll curmax = -1;
    ll curmin = LLONG_MAX ;
    while (j < n)
    {
        cur = 0;
        while (j - i + 1 <= k)
        {
            cur += arr[j];
            j++; //window of size k
            //cout << j - i + 1 << " " << k << endl;
        }
        //cout << cur << " " << k << endl;
        curmax = max(cur, curmax);
        curmin = min(cur, curmin);
        //cur = 0;
        i = j;
    }
    return abs(curmax - curmin);
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
        vl arr(n, 0);
        ll maxi = -1;
        ll mini = 1e9;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            maxi = max(maxi, arr[i]);
            mini = min(mini, arr[i]);
        }
        ll res = abs(maxi - mini); //for case when n=k.
        ll sum = 0;
        for (int k = 2; k <= n; k++)
        {
            if ((n % k) == 0)
            {
                sum = solve(k, arr);
                res = max(res, sum);
            }
        }
        cout << res << endl;
    }
    return 0;
}