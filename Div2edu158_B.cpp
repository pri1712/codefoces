#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
//typedef std::map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
//int n;
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
        int n;
        cin >> n;
        vl arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
        }
        ll res = 0;
        res += arr[0] - 1;
        for (int i = 1; i < n; ++i)
        {
            if (arr[i] > arr[i - 1])
            {
                res += (arr[i] - arr[i - 1]);
            }
        }
        cout << res << endl;
    }
    return 0;

}