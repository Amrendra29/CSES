#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define loop(i,a,b) for(int i=(a); i<(b); i++)
#define rloop(i,a,b) for(int i=(a); i>=(b); i--)

const int MOD = 1e9 + 7;
const int INF = 1e8;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll modpow(ll a, ll b, ll mod=MOD) {
    ll res = 1;
    while(b){
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
ll modinv(ll a, ll mod = MOD) {
return modpow(a, mod - 2, mod);
}
// ll f(int i,int sum){
//     if(sum==0) return 1;
//     if(i==0 || sum<0) return 0;
//     ll take=f(i-1,sum-i);
//     ll skip=f(i-1,sum);

//     return (take+skip)%MOD;

// }
void solve(){
    ll n; cin >> n;
    if(n<=2 || (n*(n+1))%4){
        cout<<0;
        return;
    }
   ll sum=(n*(n+1))/4;
   vector<vector<ll>> dp(n+1,vector<ll>(sum+1,0));
   for(int i=0;i<=n;i++) dp[i][0]=1;
    for(int i=1;i<=n;i++){
        for(int s=1;s<=sum;s++){
             ll take=0;
             if(s-i>=0) take=dp[i-1][s-i];
    ll skip=dp[i-1][s];

    dp[i][s] =(take+skip)%MOD;

        }
    }
   ll ans=dp[n][sum]%MOD;
   cout<<(ans*modinv(2))%MOD;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}