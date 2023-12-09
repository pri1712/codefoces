#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
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
    ll a, b;
    ci(a);
    ci(b);
    if (a == b)
    {
        cout << 0 << nl;
        return 0;
    }
    ll res = 0;
    ll hcf = std::__gcd(a, b);
    a /= hcf;
    b /= hcf;
    while (a % 2 == 0 && a)
    {
        a /= 2;
        res++;
    }
    while (a % 3 == 0 && a)
    {
        a /= 3;
        res++;
    }
    while (a % 5 == 0 && a)
    {
        a /= 5;
        res++;
    }
    while (b % 2 == 0 && b)
    {
        b /= 2;
        res++;
    }
    while (b % 3 == 0 && b)
    {
        b /= 3;
        res++;
    }
    while (b % 5 == 0 && a)
    {
        b /= 5;
        res++;
    }
    if (a != b)
    {
        cout << -1 << nl;
        return 0;
    }
    cout << res << nl;
    return 0;
}