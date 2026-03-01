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
vector<int> dp;
void s(int n, vector<int> &digits)
{
    while (n > 0)
    {
        digits[n % 10]++;
        n /= 10;
    }
}
int f(int n)
{
    if (n <= 0)
        return 0;
        if(dp[n]!=-1) return dp[n];
    vector<int> digits(10, 0);
    s(n, digits);
    int steps = INT_MAX;
    for (int i = 1; i <= 9; i++)
    {
        if (digits[i] > 0)
        {
            int cur = n - i;
            int step = 1 + f(cur);
            steps = min(step, steps);
        }
    }

    return dp[n]= steps;
}

void solve()
{
    int n;
    cin >> n;
    dp.assign(n+1,-1);
    int ans = f(n);
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