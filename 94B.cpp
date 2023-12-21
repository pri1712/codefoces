#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n
#define co(n) cout<<n
#define nl '\n'
#define r0 return 0
#define LLMAX LLONG_MAX
#define all(x) (x).begin(), (x).end()
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<std::pair<int, int>> vp;
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
    int m;
    ci(m);
    int arr[6][6] = {0};
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        ci(x); ci(y);
        arr[x][y] = 1; //connected
        arr[y][x] = 1;
    }
    //1 shows connect , 0 shows not connect.
    for (int i = 1; i <= 5 ; ++i)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            for (int k = 1; k <= j - 1; k++)
            {
                if ((arr[k][j] && arr[j][i] && arr[i][k]) || (!arr[k][j] && !arr[j][i] && !arr[i][k]) )
                {
                    co("WIN");
                    r0;
                }
            }
        }
    }
    co("FAIL");
    r0;
}