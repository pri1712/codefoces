#include <bits/stdc++.h>
#include <algorithm>
#include <set>
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
    int n, x0, y0; //number of troopers and guns coords
    cin >> n >> x0 >> y0;
    set<double> slopes;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        ll xslope = (x - x0);
        if (xslope == 0)
        {
            slopes.insert(1e9);
            continue;
        }
        double curslope = static_cast<double>(y - y0) / (x - x0);
        //cout << curslope << x << y << endl;
        slopes.insert(curslope);
    }
    cout << slopes.size() << endl;
    return 0;
}
