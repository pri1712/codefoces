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
bool isodd(ll x)
{
    return (x % 2);
}
int gcd(int a , int b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
int lcm( int a , int b)
{
    return a * b / gcd(a, b);
}
int lowbit(int x)
{
    int lb = 0;
    while ((x & 1) == 0 && x > 0)
    {
        lb++;
        x >>= 1;
    }
    return 1 << lb; //2^lb.
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
    int sum, lim;
    ci(sum); ci(lim);
    vp arr;
    while (lim > 0)
    {
        arr.push_back({lowbit(lim), lim});
        lim--;
    }
    sort(rall(arr));
    // for (auto it : arr)
    // {
    //     co(it.first); co(" "); co(it.second); co(nl);
    // }
    set<int> st;
    for (int i = 0; i < (int)arr.size() && sum > 0; i++)
    {
        if (sum - arr[i].first >= 0)
        {
            st.insert(arr[i].second);
            sum -= arr[i].first;
        }
    }
    if (sum > 0)
    {
        co(-1);
        co(nl);
    }
    else
    {
        co((int)st.size());
        co(nl);
        for (auto it : st)
        {
            co(it); co(" ");
        }
    }
    r0;
}