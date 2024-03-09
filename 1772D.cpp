#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define LLMAX LLONG_MAX
#define r0 return 0
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) (x).begin(), (x).end()
#define printstr(s) for(int i=0;i<(int)s.size();i++) { cout<<s[i];}
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
ll n;
ll extendedeuclidalgo(ll a, ll b, ll& x, ll& y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = extendedeuclidalgo(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
bool isodd(ll x)
{
    return (x % 2);
}
int gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( ll a , ll b)
{
    return a * b / gcd(a, b);
}
ll modpow(ll x, ll n, ll m)
{
    if (n == 0) return 1 % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}
bool issorted(vl& arr)
{
    for (int i = 1; i < n; ++i)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}
ll modinv(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * modinv(mod % a, mod) % mod;
}
void solve()
{
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    ci(n);
    vl arr(n);
    ll mini = LLMAX, maxi = -1;
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    vl temp = arr;
    sort(all(temp));
    if (temp == arr)
    {
        co(0); co(nl);
        return;
    }
    ll l = mini;
    ll r = maxi;
    ll mid;
    bool there = false;
    ll curans = 0;
    while (l <= r)
    {
        mid = (l + r) / 2;
        // vl temp = arr;
        // for (int i = 0; i < n; ++i)
        // {
        //     temp[i] = abs(temp[i] - mid);
        // }
        // if (issorted(temp))
        // {
        //     r = mid - 1;
        //     curans = mid;
        //     there = true;
        //     break;
        // }
        // else
        // {
        //     l = mid + 1;
        // }
        bool movel = false, mover = false;
        bool ok = true;
        for (int i = 1; i < n; ++i)
        {
            if (abs(arr[i] - mid) < abs(arr[i - 1] - mid)) //unsorted
            {
                ok = false;
                if (arr[i] > arr[i - 1])
                {
                    //move m closer to arr[i-1]
                    mover = true;
                }
                else if (arr[i] < arr[i - 1])
                {
                    movel = true;
                }
            }
        }
        if (ok)
        {
            there = true;
            curans = mid; break;
        }
        if (movel)
        {
            l = mid + 1;
        }
        else if (mover)
        {
            r = mid - 1;
        }
    }
    if (there)
    {
        co(curans);
    }
    else
    {
        co(-1);
    }
    co(nl); return;

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
    r0;
}