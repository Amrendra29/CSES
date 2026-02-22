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
vector<vector<int>> dp;
int f(int i, int sum, vector<int> &a)
{
    if (i < 0)
        return sum == 0 ? 0 : 1e9;
    if (sum == 0)
        return 0;
    if (sum < 0)
        return 1e9;
    if (dp[i][sum] != -1)
        return dp[i][sum];
    int skip = f(i - 1, sum, a);
    int take = 1e9;
    if (sum >= a[i])
        take = 1 + f(i, sum - a[i], a);

    return dp[i][sum] = min(take, skip);
}

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    loop(i, 0, n) cin >> a[i];
    dp.assign(n + 1, vector<int>(x + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int sum = 1; sum <= x; sum++)
        {
            int skip = (i == 0 ? 1e9 : dp[i - 1][sum]);
            int take = 1e9;
            if (sum >= a[i])
                take = 1 + dp[i][sum - a[i]];

            dp[i][sum] = min(take, skip);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        ans = -1;
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