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
int n,m;
// LOVE MOVIE
int dp[5001][5001];
int f(int i,int j,string &s1,string &s2){
    if(i<0 && j<0) return 0;
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    int steps=0;
    if(s1[i]==s2[j]) steps+=f(i-1,j-1,s1,s2);
    else{
        int one=1+min(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
        int two=1+f(i-1,j-1,s1,s2);
        steps+=min(one,two);
    }

    return dp[i][j]= steps;

}
void solve(){
    string s1,s2;
    cin>>s1>>s2;
    n=s1.length(),m=s2.length();
    memset(dp,-1,sizeof(dp));
    int ans=f(n-1,m-1,s1,s2);

    cout<<ans;
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}