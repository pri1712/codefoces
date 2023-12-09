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
        int x;
        int n;
        cin >> n >> x;
        //cout << n << endl;
        //int diff = INT_MIN;
        vector<int> arr;
        arr.push_back(0);
        for (int i = 0; i < n; i++)
        {
            //cin >> arr[i];
            int cur;
            cin >> cur;
            //cout << arr[i] << endl;
            arr.push_back(cur);
        }
        int diff = INT_MIN;
        arr.push_back(x);//last dest
        for (int i = 1; i < (int)arr.size() - 1; i++)
        {
            int curdif = abs(arr[i] - arr[i - 1]);
            diff = max(diff, curdif);
        }
        //cout << 2 * (arr[arr.size() - 2] - arr[arr.size() - 1]);
        diff = max(diff, abs(2 * (arr[arr.size() - 2] - arr[arr.size() - 1])));
        cout << diff << endl;
    }
    return 0;
}