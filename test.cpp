#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cstdio>
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
ll gcd(ll a , ll b)
{
    if (b == 0) return a;
    else return gcd(b , a % b);
}
ll lcm( ll a , ll b)
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
ll modinv(ll a, ll mod)
{
    return a <= 1 ? a : mod - (long long)(mod / a) * modinv(mod % a, mod) % mod;
}
// void sieve()
// {
//     for (int i = 2; i * i <= 10000000 ; i++)
//     {
//         if (isprime[i] == 0)
//         {
//             for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                 isprime[j] = 1;
//         }
//     }
// }
void solve()
{
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
    int n;
    cin >> n;

    // Array to store the elements
    int a[n];

    // Map to store the frequency of each element in the array
    unordered_map<int, int> m;

    // Input array elements and update the frequency map
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }

    // Initialize variables
    int j = 0;
    set<int> s, ss;

    // Build two sets, 's' and 'ss', to track elements that occur at least twice
    while (m[j] >= 2) {
        s.insert(j);
        ss.insert(j);
        j++;
    }

    // If there is an element with exactly one occurrence, continue processing
    if (m[j] > 0) {
        cout << -1 << endl;
    } else {
        int r = 0;

        // Find the index 'r' where all elements in set 's' are encountered at least once
        for (int i = 0; i < n; i++) {
            if (s.find(a[i]) != s.end()) {
                s.erase(a[i]);
            }
            if (s.size() == 0) {
                r = i + 1;
                break;
            }
        }

        // Remove elements from set 'ss' occurring after index 'r'
        for (int i = r; i < n; i++) {
            if (ss.find(a[i]) != ss.end()) {
                ss.erase(a[i]);
            }
        }

        // Check if set 'ss' is empty
        if (ss.size() == 0) {
            // If 'ss' is empty, print the division into two subarrays
            cout << 2 << endl;
            cout << 1 << " " << r << endl;
            cout << r + 1 << " " << n << endl;
        } else {
            // If 'ss' is not empty, it's not possible to create the required subarrays
            cout << -1 << endl;
        }
    }
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