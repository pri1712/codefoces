#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
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
        int chest , key , energy ;
        cin >> chest >> key >> energy;
        if (key < chest)
        {
            cout << chest << endl;
            continue;
        }
        if (abs(chest - key) <= energy)
        {
            cout << key << endl;
            continue;
        }
        else
        {
            int dist = chest + energy;
            int remdest = key - dist;
            cout << 2 * remdest + dist << endl;
            continue;
        }
    }
    return 0;
}
