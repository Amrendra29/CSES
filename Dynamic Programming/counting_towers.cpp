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
vector<vector<int>> dp(1e6+1, vector<int>(2, -1));
void solve(){
    int n; cin >> n;
    dp[n][0]=1;
    dp[n][1]=1;
    for(int i=n-1;i>=0;i--){
        dp[i][0]=(2LL*dp[i+1][0]+dp[i+1][1])%MOD;
        dp[i][1]=(4LL*dp[i+1][1]+dp[i+1][0])%MOD;
    }

    cout<<(dp[1][0]+dp[1][1])%MOD<<endl;
   
}

int main(){
    fast_io;
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}