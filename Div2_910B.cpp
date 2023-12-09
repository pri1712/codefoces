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
typedef std::unordered_set<char> unsetc;
using namespace std;
int n;
vi arr;
bool isorted(vi& arr)
{
    vi sorts = arr;
    sort(sorts.begin(), sorts.end());
    if (sorts == arr)
        return true;
    return false;
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
        vi arr(n + 1, 0);
        ll steps = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        if (isorted(arr))
        {
            cout << 0 << endl;
            continue;
        }
        for (ll i = n - 1; i >= 1; i--)
        {
            if (arr[i] > arr[i + 1])
            {
                //cout << arr[i] << " " << arr[i + 1];
                ll x = (arr[i] + arr[i + 1] - 1) / arr[i + 1];
                steps += x - 1;
                arr[i] = arr[i] / x;
            }
        }
        cout << steps << endl;
        //arr.clear();
    }
    return 0;

}