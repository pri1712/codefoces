#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
int mod = 1e9 + 7;
bool basedonnum(pp a, pp b)
{
    return a.first < b.first;
}
bool basedonind(pp a, pp b)
{
    return a.second < b.second;
}
void solve()
{
    int n;
    ci(n);
    vp arr;
    for (int i = 0; i < n; ++i)
    {
        ll cur;
        ci(cur);
        arr.push_back({cur, i});
    }
    sort(arr.begin(), arr.end(), basedonnum);
    vl pre(n);
    pre[0] = arr[0].first;
    for (int i = 1; i < (int)arr.size(); ++i)
    {
        pre[i] = pre[i - 1] + arr[i].first;
    }
    // for (auto it : pre)
    //     cout << it << " ";
    vp ans(n);
    for (int i = 0; i < n; ++i)
    {
        ans[i].first = 0;
        ans[i].second = arr[i].second;
    }
    int res = -1;
    for (int i = 0; i < (int)arr.size(); ++i)
    {
        res = max(res, i);
        while (res < n - 1 && arr[res + 1].first <= pre[res])
            res++;
        ans[i].first = res;
    }
    sort(ans.begin(), ans.end(), basedonind);
    for (auto it : ans)
    {
        cout << it.first << " ";
    }
    co(nl);


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
    ci(t);
    while (t--)
    {
        solve();
    }
}