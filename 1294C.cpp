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
void solve()
{
    ll n; ci(n);
    unordered_set<ll> st;
    for (int i = 2; i * i <= n  ; ++i)
    {
        if (n % i == 0 && st.find(i) == st.end())
        {
            st.insert(i);
            n /= i;
            break;
        }
    }
    for (int i = 2; i * i <= n  ; ++i)
    {
        if (n % i == 0 && st.find(i) == st.end())
        {
            st.insert(i);
            n /= i;
            break;
        }
    }
    if (st.size() < 2 || st.find(n) != st.end() || n == 1)
    {
        co("NO");
    }
    else
    {
        st.insert(n);
        co("YES");
        co(nl);
        for (auto it : st)
        {
            co(it); co(" ");
        }
    }
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
    r0;
}