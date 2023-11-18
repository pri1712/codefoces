#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
using namespace std;
int n;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin >> s;
    string res = "";
    int onecount = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '1')
        {
            onecount++;
        }
        else
            res += s[i];
    }
    int firsttwo = -1;
    for (int i = 0; i < (int)res.size(); i++)
    {
        if (res[i] == '2')
        {
            firsttwo = i; //first instance of digit 2.
            break;
        }
    }
    if (firsttwo == -1)
    {
        while (onecount--)
        {
            res += '1';
        }
    }
    else
    {
        for (int i = 0; i < (int)res.size(); i++)
        {
            if (i == firsttwo)
            {
                res.insert(i, onecount, '1');
            }
        }
    }
    cout << res << endl;
    return 0;
}