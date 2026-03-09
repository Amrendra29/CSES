#include <bits/stdc++.h>
using namespace std;

#define fast_io                       \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define loop(i, a, b) for (int i = (a); i < (b); i++)
#define rloop(i, a, b) for (int i = (a); i >= (b); i--)

const int MOD = 1e9 + 7;
const int INF = 1e8;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll modpow(ll a, ll b, ll mod = MOD)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a, ll mod = MOD)
{
    return modpow(a, mod - 2, mod);
}
vector<vector<ll>> dp;
ll f(int i, int val, vector<int> &a, int m)
{
    if (val < 1 || val > m)
        return 0;

    if (i == 0)
    {
        if (a[0] == 0 || a[0] == val)
            return 1;
        return 0;
    }

    ll &res = dp[i][val];
    if (res != -1)
        return res;

    if (a[i] != 0 && a[i] != val)
        return res = 0;

    res = (f(i - 1, val, a, m) +
           f(i - 1, val - 1, a, m) +
           f(i - 1, val + 1, a, m)) %
          MOD;

    return res;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    loop(i, 0, n) cin >> a[i];
    dp.assign(n, vector<ll>(m + 2, -1));

    ll ans = 0;

    if (a[n - 1] == 0)
    {
        for (int v = 1; v <= m; v++)
            ans = (ans + f(n - 1, v, a, m)) % MOD;
    }
    else
    {
        ans = f(n - 1, a[n - 1], a, m);
    }

    cout << ans;
}

int main()
{
    fast_io;
    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}