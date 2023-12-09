#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
#define ci(n) cin>>n;
#define nl '\n';
typedef std::pair<int, int> pp;
typedef long long ll;
typedef std::vector<ll> vl;
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
    int n;
    ci(n);
    int k1;
    ci(k1);
    queue<int> q1;
    for (int i = 0; i < k1; i++)
    {
        int x;
        ci(x);
        q1.push(x);
    }
    int k2;
    ci(k2);
    queue<int> q2;
    for (int i = 0; i < k2; i++)
    {
        int x;
        ci(x);
        q2.push(x);
    }
    ll count = 0;
    char win;
    while (true)
    {
        int top1 = q1.front();
        q1.pop();
        int top2 = q2.front();
        q2.pop();
        count++;
        if (top1 > top2)
        {
            //1 wins the cur fight
            q1.push(top2);
            q1.push(top1);
        }
        else if (top2 > top1)
        {
            //2 wins cur fight
            q2.push(top1);
            q2.push(top2);
        }
        if (q2.size() == 0)
        {
            win = '1';
            break;
        }
        else if (q1.size() == 0)
        {
            win = '2';
            break;
        }
        if (count > 1e7)
        {
            cout << -1 << nl;
            return 0;
        }

    }
    cout << count << " " << win << nl;
    return 0;
}