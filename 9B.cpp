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
    ll n, vb, vs;
    ci(n); ci(vb); ci(vs);
    vl a(n);
    for (int i = 0; i < n; ++i)
    {
        ci(a[i]);
    }
    ll xu, yu;
    ci(xu); ci(yu);
    double res = LLMAX;
    double id = -1;
    for (int i = 1; i < n; ++i)
    {
        double tb =  (double)a[i] / (double)vb;
        // co(tb); co(" "); co(a[i]); co(nl);
        double ds = sqrt((a[i] - xu) * (a[i] - xu) + (ll)yu * yu);
        double ts = ds / vs;
        if (ts + tb <= res)
        {
            res = ts + tb;
            id = i + 1;
        }
    }
    co(id);
    r0;
}