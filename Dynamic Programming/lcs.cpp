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
// int f(int i,int j,vector<int>&a,vector<int>&b){
//     if(i<0 || j<0) return 0;
//     int ans=0;
//     if(a[i]==b[j]){
//         ans=1+f(i-1,j-1,a,b);
//     }
//     else{
//         ans=max(f(i-1,j,a,b),f(i,j-1,a,b));
//     }

//     return ans;
// }

void solve(){
    int n,m; cin >> n>>m;
    vector<int> a(n),b(m);
    loop(i,0,n) cin >> a[i];
    loop(i,0,m) cin >> b[i];
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
             if(a[i-1]==b[j-1]){
         dp[i][j]=1+dp[i-1][j-1];
    }
    else{
       
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    }
        }
    }
    int ans=dp[n][m];
    cout<<ans<<endl;
    stack<int>st;
    int i=n,j=m;
    while(i>0 &&j>0){
        if(a[i-1]==b[j-1]){
           st.push(a[i-1]);
            i--;j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}