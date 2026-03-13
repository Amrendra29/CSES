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
int f(int i,int j,vector<vector<char>> &a){
   if(i==0 && j==0) return a[0][0]-'A';
   int cost=a[i][j]-'A';
   int up=1e6;
   if(i-1>=0) up=f(i-1,j,a);
   int left=1e6;
   if(j-1>=0) left=f(i,j-1,a);

   return cost+min(up,left);
}
void solve(){
    int n; cin >> n;
    vector<vector<char>> a(n,vector<char>(n));
    loop(i,0,n) {
        string s;
        cin>>s;
        loop(j,0,n){
            a[i][j]=s[j];
        }
    }
    vector<vector<int>> dp(n+2,vector<int>(n+2,1e9));
     dp[n][n] = a[n-1][n-1]-'A';
    for(int i=n;i>=1;i--){
        for(int j=n;j>=1;j--){

            if(i==n && j==n) continue;

            int cost = a[i-1][j-1]-'A';

            dp[i][j] = cost + min(dp[i+1][j], dp[i][j+1]);
        }
    }
    string ans;
    ans+=a[0][0];
    int i=1,j=1;
    while(i!=n || j!=n){

        if(i==n) j++;
        else if(j==n) i++;
        else if(dp[i+1][j] < dp[i][j+1]) i++;
        else j++;

        ans += a[i-1][j-1];
    }
    
    cout<<ans;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}