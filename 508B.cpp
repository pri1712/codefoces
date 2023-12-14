#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
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
    string s;
    ci(s);
    string res;
    int last = s.size() - 1;
    int curind = last;
    for (int i = 0; i < (int)s.size(); ++i)
    {
        if ((s[i] - '0') % 2 == 0) //even
        {
            curind = i;
            if (s[last] > s[curind])
                break;
        }
    }
    if (curind == last)
    {
        cout << -1 << nl;
        return 0;
    }
    std::swap(s[curind], s[last]);
    cout << s << nl;
    return 0;
}