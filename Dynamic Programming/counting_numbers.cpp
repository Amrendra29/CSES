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

ll dp[20][11][2][2];
ll f(string &s,int n,int prev,int leading,int tight){
    if(n==0){
        return 1;
    }
    ll &res=dp[n][prev][leading][tight];
    if(res!=-1) return res;
    ll ans=0;
    int ub=tight?s[s.length()-n]-'0':9;
    for(int dig=0;dig<=ub;dig++){
        int new_leading = leading && (dig == 0);
        // only check prev constraint if number has started
        if (new_leading || prev != dig) {
             int next_prev = new_leading ? 10 : dig;
            ans += f(s, n - 1, next_prev, new_leading, tight && (dig == ub));
        }
    }

    return res= ans;

}

void solve(){
    ll a,b; cin >> a>>b;
    a--;
    string l=to_string(a);
    string r=to_string(b);
    memset(dp,-1,sizeof(dp));

    ll f1=f(r,r.length(),10,1,1);

    memset(dp,-1,sizeof(dp));
    ll f2=0;
    if(a>=0) f2=f(l,l.length(),10,1,1);
    cout<<f1-f2;
    
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}