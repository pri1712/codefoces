#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
bool isodd(int n)
{
    return n % 2 == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, x, y;
    ll ans = 0;
    cin >> a >> x >> y;
    if (abs(x) >= abs(a) || y % a == 0 || y <= 0)
    {
        //cout << "hi";
        cout << -1 << endl;
        return 0;
    }
    int level = (y / a) + 1;
    if (level == 1)
    {
        //cout << "hi";
        if (abs(x) >= ((a + 1) / 2))
            cout << -1;
        else
            cout << 1;
        return 0;
    }
    else if (isodd(level))
    {
        //   cout << "arey bc";
        //odd levels have 2 blocks in them.
        int oddlevels = level / 2; //number of oddleveles before this.
        ans = 2 * oddlevels + (oddlevels - 1) + 2;
        if (x == 0)
        {
            cout << -1;
            return 0;
        }
        if (x < 0)
            ans--;
        cout << ans;
        return 0;
    }
    else
    {
        int oddlevels = (level - 1) / 2 ;
        ans = 2 * oddlevels + (oddlevels) + 2;
        if (abs(x) >= (a + 1) / 2)
            ans = -1;
        cout << ans;
        return 0;
    }

    return 0;
}