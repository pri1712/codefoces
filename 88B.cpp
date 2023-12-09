#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
typedef std::unordered_map<int, int> unmap;
typedef std::unordered_set<int> unseti;
typedef std::unordered_set<char> unsetc;
int n, m;
//int dist;
int res = 0;
unsetc st;
vector<pair<int, int>> shift;
std::map<char, bool> dist;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int x;
    cin >> n >> m >> x;
    vector<vector<char>> arr(n, vector<char>(m, '*'));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
            {
                shift.push_back({i, j});
            }
            else
                st.insert(arr[i][j]);
        }
    }
    int q;
    string s;
    cin >> q;
    cin >> s;
    for (int i = 0; i < q; i++)
    {
        if (std::isupper(s[i]) && (st.find(tolower(s[i])) == st.end() || shift.empty()))
        {
            cout << -1 << endl;
            return 0;
        }
        //return 0;
        else if (std::islower(s[i]) && st.find(s[i]) == st.end())
        {
            cout << -1 << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 'S')
            {
                for (auto it : shift)
                {
                    double a = i - it.first;
                    double b = j - it.second;
                    if (a * a + b * b <= x * x)
                        dist[arr[i][j]] = 1;
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        if (st.find(s[i]) == st.end() && !dist[tolower(s[i])])
            res++;
    }
    cout << res << endl;
    return 0;
}