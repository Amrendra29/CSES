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
set<int> st;
vector<vector<int>> dp;
void f(int i, int sum, vector<int>& a){
    if(i < 0){
        st.insert(sum);
        return;
    }
    if(dp[i][sum]) return;
    dp[i][sum]=1;

    // take
    f(i-1, sum + a[i], a);

    // not take
    f(i-1, sum, a);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    int sum=0;
    loop(i,0,n) {cin >> a[i]; sum+=a[i];}
    dp.assign(n+1,vector<int>(sum+1,0));
   f(n-1,0,a);
   cout<<st.size()-1<<endl;
   bool once=false;
   for(auto i:st){
    if(!once){
        once=true;
        continue;
        
    }
    cout<<i<<" ";
   }
}

int main(){
    fast_io;
    int t=1;
 //   cin >> t;
    while(t--) solve();
    return 0;
}