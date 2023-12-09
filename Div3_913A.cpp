//AC
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
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        char ogf = s[0];
        char ogs = s[1];
        for (char i = '1'; i <= '8'; i++)
        {
            if (i == ogs)
                continue;
            s[1] = i;
            cout << s << endl;
        }
        s[1] = ogs;
        for (char c = 'a'; c <= 'h'; c++)
        {
            if (c == ogf)
                continue;
            s[0] = c;
            cout << s << endl;
        }
    }
    return 0;
}