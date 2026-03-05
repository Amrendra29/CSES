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
vector<vector<int>>dp;
int f(int i,int money,vector<int>& pages,vector<int>&prices){
    if(i<0) return 0;
    int &res=dp[i][money];
    if(res!=-1) return res;
    int skip=f(i-1,money,pages,prices);
    int take=0;
    if(money>=prices[i]) take=pages[i]+f(i-1,money-prices[i],pages,prices);

    return res= max(take,skip);

}

void solve(){
    int n,x; cin >> n>>x;
    vector<int> prices(n),pages(n);
    loop(i,0,n) cin >> prices[i];
    loop(i,0,n) cin >> pages[i];
    dp.assign(n,vector<int>(x+1,0));
    loop(i,0,n){
        loop(money,0,x+1){
             int skip=(i==0?0:dp[i-1][money]);
    int take=0;
    if(money>=prices[i]) take=pages[i]+(i==0?0:dp[i-1][money-prices[i]]);

    dp[i][money]= max(take,skip);
        }
    }
    int ans=dp[n-1][x];

    cout<<ans;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}