#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
#define r0 return 0;
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
    string s;
    ci(s);
    int n = (int)s.size();
    for (int i = 0; i < n; ++i)
    {
        int num1 = s[i] - '0';
        if (num1 % 8 == 0)
        {
            cout << "YES" << nl;
            cout << num1 << nl;
            r0;
        }
        for (int j = i + 1; j < n; ++j)
        {
            int num2 = (s[i] - '0') * 10 + (s[j] - '0');
            if (num2 % 8 == 0)
            {
                cout << "YES" << nl;
                cout << num2 << nl;
                r0;
            }
            for (int k = j + 1; k < n ; ++k)
            {
                ll num = (s[i] - '0') * 100 + (s[j] - '0') * 10 + (s[k] - '0');
                if (num % 8 == 0)
                {
                    cout << "YES" << nl;
                    cout << num << nl;
                    r0;
                }
            }
        }
    }
    cout << "NO" << nl;
    r0;
}