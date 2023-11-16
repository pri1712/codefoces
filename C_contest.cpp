#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#include <unordered_set>
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
    int n;
    cin >> n;
    unordered_set<string> even;
    unordered_set<string> odd;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if ((s.length() & 1) == 0) //even
            even.insert(s);
        else
            odd.insert(s);
    }
    int numways = 0;
    //finding among even.
    for (const string& s1 : even) {
        for (const string& s2 : even)
        }
}