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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ll n, k;
    ci(n); ci(k);
    vl arr(n);
    ll maxi = -1;
    ll mini = LLMAX;
    int maxind;
    int minind;
    for (int i = 0; i < n; ++i)
    {
        ci(arr[i]);
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            maxind = i;
        }
        if (arr[i] < mini)
        {
            mini = arr[i];
            minind = i;
        }
    }
    ll inst = maxi - mini;
    ll time = 0;
    vp moves;
    while (inst >= 0 && k > 0)
    {
        if (maxind == minind)
            break;
        arr[maxind]--;
        arr[minind]++;
        time++;
        k--;
        moves.push_back({maxind + 1, minind + 1});
        ll curmaxi = -1;
        ll curmini = LLMAX;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > curmaxi)
            {
                curmaxi = arr[i];
                maxind = i;
            }
            if (arr[i] < curmini)
            {
                curmini = arr[i];
                minind = i;
            }

        }
        ll curinst = curmaxi - curmini;
        if (curinst <= inst)
        {
            inst = curinst;
        }
        else
            break;
    }
    co(inst); co(" "); co(time);
    co(nl);
    for (auto it : moves)
    {
        co(it.first); co(" "); co(it.second); co(nl);
    }
}