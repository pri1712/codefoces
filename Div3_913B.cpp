//AC
#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<char> vc;
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
        string str;
        string res = "";
        cin >> str;
        vi upper;//store uppercase chars
        vi lower;//store lowercase chars
        string la = "qwertyuiopasdfghjklzxcvbnm";
        string ua = "QWERTYUIOPASDFGHJKLZXCVBNM";
        vc ans;
        int c = 0;
        for (int i = 0; i < (int)str.size(); i++) {
            if (str[i] == 'B' && upper.size() > 0) {
                ans[upper.back()] = '_';
                upper.pop_back();
            } else if (str[i] == 'b' && lower.size() > 0) {
                ans[lower.back()] = '_';
                lower.pop_back();
            } else if (str[i] != 'b' && str[i] != 'B') {
                if (la.find(str[i]) != std::string::npos)
                    lower.push_back(c);
                else
                    upper.push_back(c);
                ans.push_back(str[i]);
                c++;
            }
        }
        for (auto it : ans) {
            if (it != '_')
                res += it;
        }

        cout << res << endl;
    }
    return 0;
}