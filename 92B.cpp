#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define r0 return 0;
#define all(x) (x).begin(), (x).end()
#define LLMAX LLONG_MAX;
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
    string s;
    ci(s);
    if (s == "1")
    {
        co(0);
        r0;
    }
    ll res = 0;
    ll i = (ll)s.size() - 1;
    for (; i > 0; i--)
    {
        if (s[i] == '0')
        {
            res++;
        }
        else if (s[i] == '1')
        {
            s[i - 1]++;
            res += 2;
        }
        else
        {
            s[i - 1]++;
            res++;
        }
    }
    if (s[0] == '2')
    {
        res++;
    }
    co(res); co(nl);
    r0;
}