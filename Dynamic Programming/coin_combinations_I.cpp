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
// vector<ll> dp;
// ll f( int sum, vector<int> &a)
// {    if(sum==0) return 1;
//     if(dp[sum]!=-1) return dp[sum];
//     ll ways=0;
//     for(int i=0;i<a.size();i++){
//         if(sum>=a[i]) ways+=f(sum-a[i],a);
//     }

//     return dp[sum]= ways;
    
// }

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    loop(i, 0, n) cin >> a[i];
     vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for(int sum = 1; sum <= x; sum++){
        for(int i = 0; i < n; i++){
            if(sum >= a[i])
                 dp[sum] = (dp[sum] + dp[sum - a[i]]) % MOD;
        }
    }

    cout << dp[x];
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