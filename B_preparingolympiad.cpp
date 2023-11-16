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
    int n, l, r, x;
    cin >> n >> l >> r >> x;
    int arr[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    ll ans = 0;
    //next we go thru all the subsets of the array to find out valid grps since the
    //constraints are small.
    for (int i = 0; i < (1 << n); ++i)
    {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int sum = 0;
        for (int j = 0; j < n ; ++j)
        {
            if (i & (1 << j))
            {
                //j is a part of the current group
                sum += arr[j];
                maxi = max(maxi, arr[j]);
                mini = min(mini, arr[j]);
            }
        }
        if (l <= sum && r >= sum && (maxi - mini) >= x)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}