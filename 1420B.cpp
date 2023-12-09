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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        // for (auto it : arr)
        //     cout << it << endl;
        //int cnt = 0;
        ll res = 0;
        for (int j = 29; j >= 0; j--)
        {
            ll cnt = 0;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] >= (1 << j) && arr[i] < (1 << (j + 1))) //if the first one is at this location j , then this evaluates to true.
                {
                    cnt++;
                }
            }
            res += (cnt) * (cnt - 1) / 2;
        }
        cout << res << endl;
    }
    return 0;
}