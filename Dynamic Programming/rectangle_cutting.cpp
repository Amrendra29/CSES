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
ll gcd(ll a, ll b) {  return b ? gcd(b, a % b) : a; }
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
vector<vector<int>> dp;
// int f(int i,int j){
//     if(i==j) return 0;
//     if(i<=0 || j<=0) return 1e6;
//     if(dp[i][j]!=-1) return dp[i][j];
//     int ans=1e6;
//     //vertical cut
//     for(int v=1;v<i;v++){
//         int cur=1+f(v,j)+f(i-v,j);
//         ans=min(ans,cur);
//     }
//     //horizontal cut
//     for(int h=1;h<j;h++){
//          int cur=1+f(i,h)+f(i,j-h);
//         ans=min(ans,cur);
//     }

//     return dp[i][j]= ans;

// }
void solve(){
    int a,b;
    cin>>a>>b;
   dp.assign(a+1,vector<int>(b+1,1e6));
   loop(i,1,a+1){
    loop(j,1,b+1){

        if(i==j){
            dp[i][j]=0;
            continue;
        }
         int ans=1e6;
    //vertical cut
    for(int v=1;v<i;v++){
        int cur=1+dp[v][j]+dp[i-v][j];
        ans=min(ans,cur);
    }
    //horizontal cut
    for(int h=1;h<j;h++){
         int cur=1+dp[i][h]+dp[i][j-h];
        ans=min(ans,cur);
    }

     dp[i][j]= ans;
    }
   }
   int ans=dp[a][b];
   cout<<ans;
   
}

int main(){
    fast_io;
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}