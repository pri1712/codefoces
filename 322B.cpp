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
    int cur = 0;
    int r, g, b;
    int R, G, B;
    cin >> r >> g >> b;
    if (r <= 2 && g <= 2 && b <= 2)
    {
        cout << min({r, g, b}) << endl;
        return 0;
    }
    else
    {
        cur = r / 3 + g / 3 + b / 3;
        R = r % 3;
        G = g % 3;
        B = b % 3;
        cur += min({R, G, B});
    }
    if (R == 2 && G == 2 && B == 0 && b != 0 || B == 2 && G == 2 && R == 0 && r != 0 || R == 2 && B == 2 && G == 0 && g != 0)
    {
        cur += 1;
    }
    cout << cur << endl;
    return 0;
}