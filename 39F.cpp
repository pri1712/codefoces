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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, m, k;
    ci(n); ci(m); ci(k);
    vl frog(m + 1);
    frog[0] = LLMAX;
    for (int i = 1; i <= m ; ++i)
    {
        ci(frog[i]);//jump of frog.
    }
    //mosq[0] = 1;
    vp hits(m + 1, {0, 0});
    for (int i = 1; i <= m ; ++i)
    {
        hits[i].second = i;
    }
    for (int i = 1; i <= k; ++i)
    {
        ll x;
        ci(x);
        for (int j = 1; j <= m; j++)
        {
            if (x % frog[j] == 0)
            {
                hits[j].first++;
            }
        }
    }
    ll res = 0;
    sort(all(hits));
    ll mini = hits[1].first;
    ll j = 1;
    while (j <= m && hits[j].first == mini)
    {
        res++;
        j++;
        //co("hi");
    }
    co(res); co(nl);
    for (int i = 1; i <= m; i++)
    {
        if (hits[i].first == mini)
        {
            co(hits[i].second); co(" ");
        }
    }
    r0;

}