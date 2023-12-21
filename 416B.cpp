#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define r0 return 0
#define LLMAX LLONG_MAX
#define all(x) (x).begin(), (x).end()
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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int m, n;
    ci(m); ci(n);
    int pt[m + 1][n + 1];
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int time;
            ci(time);
            pt[i][j] = time; //time taken by jth ptr for ith pic.
        }
    }
    vi res(m + 1);
    for (int i = 1; i <= n; ++i)
    {
        int free = 0;
        for (int j = 1; j <= m; j++)
        {
            int start = max(free, res[j]);
            res[j] = start + pt[j][i];
            free = res[j];
        }
    }
    for (auto it : res)
    {
        if (it == 0)continue;
        co(it); co(" ");
    }
    r0;
}