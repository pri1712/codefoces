#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool ascorderbybi(pp a, pp b)
{
    return a.second < b.second;
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
    ll n, r, avg;
    cin >> n >> r >> avg;
    vp v;
    ll res = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        int curmark, numessay;
        cin >> curmark >> numessay;
        sum += curmark;
        v.push_back({curmark, numessay});
    }
    if (sum >= n * avg)
        cout << "0" << endl;
    else
    {
        std::sort(v.begin(), v.end(), ascorderbybi);
        int i = 0;
        while (sum < avg * n)
        {
            ll tmp;
            if (n * avg - sum > r - v[i].first) //get the max allowed grade here
            {
                tmp = r - v[i].first;
            }
            else
                tmp = n * avg - sum;
            res += tmp * v[i].second;
            sum += tmp;
            i++;
        }
        cout << res << endl;
    }

    return 0;
}