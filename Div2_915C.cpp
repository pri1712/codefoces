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
/*
A string a is lexicographically smaller than a string b

if and only if one of the following holds:

a is a prefix of b, but a≠b

In the first position where a
and b differ, the string a has a letter that appears earlier in
the alphabet than the corresponding letter in b.
*/
void solve()
{
    ll n;
    ci(n);
    string s;
    ci(s);
    string temp = s;
    sort(all(temp));
    if (temp == s)
    {
        co(0);
        co(nl);
        return;
    } //if already sorted
    s = '*' + s;
    vi st;
    for (int i = 1; i <= n; ++i)
    {
        while (!st.empty() && s[st.back()] < s[i])
        {
            st.pop_back();
        }
        st.push_back(i);
    }
    //finding lexcio largest subseq.
    ll res = 0;
    ll sz = (int)st.size() - 1;
    while (res <= sz && s[st[res]] == s[st[0]])
    {
        res++;//similar chars
    }
    res = sz - res + 1;
    for (int i = 0; i <= sz; ++i)
    {
        if (i < sz - i)
        {
            swap(s[st[i]], s[st[sz - i]]);
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (s[i] < s[i - 1])
        {
            co(-1); co(nl);
            return;
        }
    }
    co(res);
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