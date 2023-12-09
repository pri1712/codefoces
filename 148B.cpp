#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unset;
typedef std::unordered_set<char> unsetc;
using namespace std;
//int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int bij = 0;
    double vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    if (vp > vd)
    {
        cout << 0 << endl;
        return 0;
    }
    double init = t * vp; //original coord
    if (init >= c)
    {
        cout << 0 << endl;
        return 0;
    }
    else
    {
        while (init < c)
        {
            double timetaken = init / (vd - vp); //timetaken to catch up
            init += timetaken * vp; //final coord
            if (init >= c)
            {
                cout << bij << endl;
                return 0;
            }
            bij++;
            double dragreturn = (init / (vd)) + f;
            init += vp * dragreturn;
        }
        cout << bij << endl;
    }
    return 0;
}