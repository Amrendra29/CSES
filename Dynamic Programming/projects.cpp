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

void solve(){
    ll n; cin >> n;
    vector<vector<ll>> a(n,vector<ll>(3));
    loop(i,0,n) cin >> a[i][0]>>a[i][1]>>a[i][2];
   sort(all(a),[](auto &x,auto &y){return x[1]<y[1]; });
   vector<ll> endTimes(n);
   loop(i,0,n) endTimes[i]=a[i][1];

   vector<ll> dp(n);
   loop(i,0,n){
    ll take=a[i][2];
    ll idx=lower_bound(all(endTimes),a[i][0])-endTimes.begin();
    idx--;
    if(idx>=0) take+=dp[idx];
    ll skip=(i>0?dp[i-1]:0);
    dp[i]=max(take,skip);
   }

   cout<<dp[n-1];
   
}

int main(){
    fast_io;
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}