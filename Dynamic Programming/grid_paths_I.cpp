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
int f(int i,int j,vector<vector<char>>& a){
    
    if(i==0 && j==0 && a[0][0]=='.') return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int up=0,left=0;
    if(i>0 && a[i-1][j]=='.') up=f(i-1,j,a);
    if(j>0 && a[i][j-1]=='.') left=f(i,j-1,a);
    
    return dp[i][j]= (up+left)%MOD;
}

void solve(){
    int n; cin >> n;
    vector<vector<char>> a(n,vector<char>(n,'.'));
    loop(i,0,n)
    {
        string row;
        cin>>row;
        loop(j,0,n){
            a[i][j]=row[j];
        }
    }
    if(a[n-1][n-1]=='*') {cout <<0; return;}
    dp.assign(n+1,vector<int>(n+1,-1));
    int ans=f(n-1,n-1,a);

    cout<<ans;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}