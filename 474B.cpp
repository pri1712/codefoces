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
#define rall(x) (x).rbegin(), (x).rend()
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
bool isodd(ll x)
{
    return (x % 2);
}
ll nextlarger(vl& arr, ll& x)
{
    int l = 0;
    int r = (int)arr.size() - 1;
    ll res = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] >= x)
        {
            res = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
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
    ll n;
    ci(n);
    vl arr(n);
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
    }
    vl pile(n + 1, 0);
    pile[0] = 1;
    pile[1] = arr[0];
    for (int i = 2; i < n + 1; ++i)
    {
        pile[i] = pile[i - 1] + arr[i - 1];
    }
    // for (auto it : pile)
    // {
    //     co(it); co(" ");
    // }
    // co(nl);
    //the separation for the piles.
    ll m;
    ci(m);
    vl res;
    while (m--)
    {
        ll x;
        ci(x);
        ll ind = nextlarger(pile, x);
        res.push_back(ind);
    }
    for (auto it : res)
    {
        if (it == 0)
            it++;
        co(it); co(" ");
    }
    r0;
}