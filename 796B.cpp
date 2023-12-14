#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define co(n) cout<<n;
#define nl '\n';
#define r0 return 0;
#define LLMAX LLONG_MAX;
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
    unset holes;
    while (m--)
    {
        int x;
        ci(x);
        holes.insert(x);
    }
    // for (auto it : holes)
    //     cout << it << " ";
    vi bone(n + 1);
    bone[1] = 1;
    if (holes.find(1) != holes.end())
    {
        co(1);
        co(nl);
        r0;
    }
    while (k--)
    {
        int ini, fini;
        ci(ini); ci(fini);
        if (bone[ini] == 1)
        {
            if (holes.find(fini) != holes.end())
            {
                co(fini); co(nl);
                r0;
            }
            else
            {
                bone[fini] = 1;
                bone[ini] = 0;
            }
        }
        else if (bone[fini] == 1)
        {
            if (holes.find(ini) != holes.end())
            {
                co(ini); co(nl);
                r0;
            }
            else
            {
                bone[ini] = 1;
                bone[fini] = 0;
            }
        }
    }
    for (int i = 1; i < (int)bone.size(); ++i)
    {
        if (bone[i] == 1)
        {
            co(i);
            co(nl);
            break;
        }
    }
    r0;

}