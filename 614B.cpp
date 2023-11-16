#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
//#include <map>
using namespace std;
typedef long long ll;
int findones(string& s)
{
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '1')
            cnt++;
    }
    return cnt;
}
int findzeros(string& s)
{
    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++)
    {
        if (s[i] == '0')
            cnt++;
    }
    return cnt;
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
    int n;
    string cur = "1";
    cin >> n;
    string s;
    int totzero = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "0")
        {
            cout << "0";
            return 0;
        }
        int ones = findones(s);
        int zeros = findzeros(s);
        if (ones == 1 && zeros == (int)s.size() - 1 )
        {
            //is a beautiful number
            totzero += zeros;
        }
        else
        {
            cur = s;
        }
    }
    while (totzero--)
    {
        cur += '0';
    }
    cout << cur << endl;
    return 0;

}