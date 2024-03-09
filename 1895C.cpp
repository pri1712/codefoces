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
ll modpow(ll x, ll n, ll m) {
    if (n == 0) return 1 % m;
    long long u = modpow(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1) u = (u * x) % m;
    return u;
}
// void sieve()
// {
//    for (int i = 2; i * i <= 10000000 ; i++)
//    {
//        if (isprime[i] == 0)
//        {
//            for (int j = 2 * i; j <= (int)isprime.size(); j += i)
//                isprime[j] = 1;
//        }
//    }
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // unordered_map<ll, ll> mp;
    // mp.reserve(1024);
    // mp.max_load_factor(0.25);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n;
    ci(n);
    // vector<string> even, odd;
    // for (int i = 0; i < n; ++i)
    // {
    //     string s;
    //     ci(s);
    //     if (isodd((int)s.size()))
    //         odd.push_back(s);
    //     else
    //         even.push_back(s);
    // }
    // // for (auto it : even)
    // // {
    // //     co(it); co(" ");
    // // }
    // //separate them into even and odd.

    // ll evenres = 0, oddres = 0;
    // for (int i = 0; i < (int)even.size(); ++i)
    // {
    //     for (int j = i; j < (int)even.size(); ++j)
    //     {
    //         string cur1 = even[i] + even[j];
    //         string cur2 = even[j] + even[i];
    //         ll ptr1 = 0, ptr2 = 0;
    //         int checker1 = 0, checker2 = 0;
    //         while (ptr1 < (int)cur1.size())
    //         {
    //             if (ptr1 < ((int)cur1.size() / 2))
    //                 checker1 += (cur1[ptr1] - '0');
    //             else
    //                 checker1 -= (cur1[ptr1] - '0');
    //             ptr1++;
    //         }
    //         if (checker1 == 0)
    //             evenres++;
    //         if (i != j)
    //         {
    //             while (ptr2 < (int)cur2.size())
    //             {
    //                 if (ptr2 < ((int)cur2.size() / 2))
    //                     checker2 += (cur2[ptr2] - '0');
    //                 else
    //                     checker2 -= (cur2[ptr2] - '0');
    //                 ptr2++;
    //             }
    //             if (checker2 == 0)
    //             {
    //                evenres++;
    //             }
    //         }

    //     }
    // }
    // for (int i = 0; i < (int)odd.size(); ++i)
    // {
    //     for (int j = i; j < (int)odd.size(); ++j)
    //     {
    //         string cur1 = odd[i] + odd[j];
    //         string cur2 = odd[j] + odd[i];
    //         ll ptr1 = 0, ptr2 = 0;
    //         int checker1 = 0, checker2 = 0;
    //         while (ptr1 < (int)cur1.size())
    //         {
    //             if (ptr1 < ((int)cur1.size() / 2))
    //                 checker1 += (cur1[ptr1] - '0');
    //             else
    //                 checker1 -= (cur1[ptr1] - '0');
    //             ptr1++;
    //         }
    //         if (checker1 == 0)
    //         {
    //             oddres++;
    //             // co(odd[i]); co(" "); co(odd[j]); co(nl);
    //         }
    //         if (i != j)
    //         {
    //             while (ptr2 < (int)cur2.size())
    //             {
    //                 if (ptr2 < ((int)cur2.size() / 2))
    //                     checker2 += (cur2[ptr2] - '0');
    //                 else
    //                     checker2 -= (cur2[ptr2] - '0');
    //                 ptr2++;
    //             }
    //             if (checker2 == 0)
    //             {
    //                 oddres++;
    //             }
    //         }
    //     }
    // }
    // co(evenres + oddres); co(nl);
    // r0;


}