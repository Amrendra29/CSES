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

// int f(int i,int pre,vector<int>&a){
//         if(i<0){
//             return 0;
//         }
//         if(dp[i][pre]!=-1) return dp[i][pre];
//     int skip=f(i-1,pre,a);
//     int take=0;
//     if(pre==i ||  a[i]<a[pre]) take=1+f(i-1,i,a);

//     return dp[i][pre]= max(take,skip);
// }

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    loop(i,0,n) cin >> a[i];
     vector<int> temp;

    for(int x : a) {
        auto it = lower_bound(temp.begin(), temp.end(), x);
        if(it == temp.end()) temp.push_back(x);
        else *it = x;
    }

    cout<< temp.size();
    // vector<int> dp(n,1);
    // int ans=1;
    // for(int i=0;i<n;i++){
    //     for(int pre=0;pre<i;pre++){
    //          if(a[i]>a[pre]){
    //             dp[i]=max(dp[i],1+dp[pre]);
    //          }
    //     }
    //     ans=max(ans,dp[i]);
    // }

   
   //cout<<ans;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}