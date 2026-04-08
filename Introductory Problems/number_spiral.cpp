#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll  unsigned long long
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
    ll x,y; cin >> x>>y;
    ll  ans=0;
    if(x>y){
       if(x%2==0){
        ll  st=(x*x)+1;
        ans=st-y;

       }
       else{
        x--;
        ll  st=(x*x);
        ans=st+y;
       }
    }
    else{
        if(y%2){
        ll  st=(y*y)+1;
        ans=st-x;

       }
       else{
        y--;
        x--;
        ll  st=(y*y)+1;
        ans=st+x;
       }
    }
   cout<<ans<<endl;
}

int main(){
    fast_io;
    int t=1;
    cin >> t;
    while(t--) solve();
    return 0;
}