#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
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
    cin >> s;
    int m;
    cin >> m;
    int n = (int)s.size();
    vi swp(n);
    for (int i = 0; i < m; ++i)
    {
        int x;
        cin >> x;
        swp[x - 1]++;
    }
    // for (auto it : swp)
    //     cout << it << endl;
    //swp holds the number of swaps requested at the poisiton i.
    for (int i = 0; i < (int)swp.size() / 2; i++)
    {
        if (i > 0)
        {
            swp[i] += swp[i - 1];
        }
        if (swp[i] & 1)
        {
            int r = (int)s.size() - i - 1;
            std::swap(s[i], s[r]);
        }
    }
    cout << s << endl;
    return 0;
}