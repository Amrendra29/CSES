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
    int n,m,k; cin >> n>>m>>k;
    vector<int> a(n),b(m);
    loop(i,0,n) cin >> a[i];
    loop(i,0,m) cin >> b[i];
    sort(all(a));
    sort(all(b));
    int ans=0;
    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]-k<=b[j] && a[i]+k>=b[j]){
            ans++;i++;j++;
        }
        else if(a[i]>b[j]) j++;
        else i++;
    }
    cout<<ans;
}

int main(){
    fast_io;
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}