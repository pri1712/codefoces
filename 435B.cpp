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
int n;
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
    ll k;
    string s;
    cin >> s >> k;
    for (int i = 0; i < (int)s.size(); i++)
    {
        ll maxi = 0;
        int curind = i;
        //cout << i << endl;
        for (int j = i ; j < (int)s.size() && j <= k + i; j++)
        {
            if (maxi < s[j] - '0')
            {
                maxi = s[j] - '0';
                curind = j;
                //     cout << "hi";
            }
        }
        k -= (curind - i);
        for (int k = i + 1; k <= curind; k++)
        {
            std::swap(s[i], s[k]);
        }
        //cout << k << endl;
    }

    cout << s << endl;
    return 0;
}