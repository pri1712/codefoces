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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string res = "";
    string arr[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};
    for (int i = 0; i < (int)s.size(); ++i)
    {
        res += arr[s[i] - '0'];
    }
    std::sort(res.begin(), res.end());
    std::reverse(res.begin(), res.end());
    cout << res << endl;
    return 0;
}