
#include <bits/stdc++.h>
#include <algorithm>
//#include <map>
using namespace std;
typedef long long ll;
int recur(int n, int m)
{
    if (n >= m)
        return (n - m);
    if (m % 2 == 0)
    {
        return 1 + recur(n, m / 2);
    }
    else
        return 1 + recur(n, m + 1);
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
    int n, m;
    cin >> n >> m;
    //try constructing n from n; div by 2 and add 1
    //int steps = 0;
    cout << recur(n, m) << endl;
    return 0;
}