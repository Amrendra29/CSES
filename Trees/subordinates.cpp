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

void f(int src,int par,vector<int>&subs,vector<int> tree[]){
    int subords=0;

    for(auto child:tree[src]){

        if(child!=par){
            f(child,src,subs,tree);
            subords+=(1+subs[child]);
        }
    }
    subs[src]=subords;
}

void solve(){
    int n; cin >> n;
   // vector<int> a(n);
    vector<int> tree[200001];
     for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        tree[x].push_back(i);
        tree[i].push_back(x);
    }
    vector<int>subs(n+1,0);
    f(1,0,subs,tree);
    loop(i,1,n+1){
        cout<<subs[i]<<" ";
    }
   
}

int main(){
    fast_io;
    int t=1;
   // cin >> t;
    while(t--) solve();
    return 0;
}