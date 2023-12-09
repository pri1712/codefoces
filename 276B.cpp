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
    string s;
    cin >> s;
    vector<int> count(28, 0);
    for (int i = 0; i < (int)s.size(); i++)
    {
        count[s[i] - 'a']++;
    }
    int odd = 0;
    for (int i = 0; i < (int)count.size(); i++)
    {
        if (count[i] % 2)
        {
            odd++;//no of odd letters in the string
        }
    }
    if (odd == 0 || (odd & 1) == 1)
    {
        cout << "First" << endl;
        return 0;
    }
    else
        cout << "Second" << endl;
    return 0;
}