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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string m;
    string t;
    ci(m);
    ci(t);
    map<char, int> mp;
    for (auto it : t)
    {
        mp[it]++;
    }
    ll yay = 0;
    ll whoops = 0;
    for (int i = 0; i < (int)m.size(); ++i)
    {
        if (mp[m[i]] > 0)
        {
            yay++;
            mp[m[i]]--;
            m[i] = '*';
        }
    }//counting yay.
    for (int i = 0; i < (int)m.size(); ++i)
    {
        if (m[i] != '*')
        {
            if (islower(m[i]) && mp[toupper(m[i])] > 0)
            {
                mp[toupper(m[i])]--;
                whoops++;
            }
            else if (isupper(m[i]) && mp[tolower(m[i])] > 0)
            {
                mp[tolower(m[i])]--;
                whoops++;
            }
        }
    }
    co(yay); co(" "); co(whoops);
    r0;
}