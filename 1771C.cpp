#include <bits/stdc++.h>
using namespace std;

#define ci(n) cin>>n
#define co(n) cout<<n
#define ll          long long int
#define f(i,x,n)    for(ll i=x;i<n;i++)
#define rf(i,x,n)   for(ll i=x;i>=n;i--)
#define endl        "\n"
#define cy          cout<<"YES"<<endl;
#define cn          cout<<"NO"<<endl;
#define ai          ll a[n]; f(i,0,n)cin>>a[i];
#define ao          f(i,0,n)cout<<a[i]<<" ";cout<<endl;

const ll N = 32001;
vector<bool> is_prime(N, true);
vector<ll> v;

void sieve() {
    for (ll i = 2; i * i < N; i++) {
        if (is_prime[i]) {
            for (ll j = i * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

void func() {
    sieve();

    f(i, 2, N) {
        if (is_prime[i]) v.push_back(i);
    }
}

void solve() {
    ll n;
    cin >> n;

    ll a[n];
    f(i, 0, n) cin >> a[i];
    func();
    unordered_set<ll> s;
    f(i, 0, (ll)v.size()) {
        ll c = 0;
        f(j, 0, n) {
            if (a[j] % v[i] == 0) c++;
            while (a[j] % v[i] == 0) a[j] /= v[i];
        }
        if (c > 1) {

            cy
            return;
        }
    }

    f(i, 0, n) {
        if (s.find(a[i]) != s.end() && a[i] > 1) {
            cy
            return;
        } else {
            s.insert(a[i]);
        }
    }

    cn
}


int main ()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    ci(t);
    while (t--)
    {
        solve();
    }
    return 0;
}