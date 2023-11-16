#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<int> vi;
//#include <map>
using namespace std;
int n;
const int maxi = 200000;
int freq[maxi][2];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a;
    cin >> b;
    for (int i = 1; i <= (int)b.size(); i++)
    {
        for (int j = 0; j < 2; j++)
        {
            freq[i][j] = freq[i - 1][j];
        }
        freq[i][b[i - 1] - '0']++;
    }
    ll sum = 0;
    int c = 0;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        c = a[i] - '0';
        for (int j = 0; j < 2; j++)
        {
            sum += abs(c - j) * (freq[(int)b.size() - (int)a.size() + i + 1][j] - freq[i][j]);
        }
    }
    cout << sum << endl;
    return 0;
}