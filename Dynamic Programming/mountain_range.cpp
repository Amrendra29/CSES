#include <bits/stdc++.h>
using namespace std;

#define fast_io ios_base::sync_with_stdio(false); cin.tie(nullptr);
#define ll long long
#define pb push_back
#define all(x) (x).rbegin(), (x).rend()
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
typedef pair<int,int> P;
void solve(){
    int n; cin >> n;
    vector<P> a(n);
    loop(i,0,n) {cin >> a[i].first; a[i].second=i;}
    stack<int>st;
    vector<int> nge(n),pge(n);
    for(int i=0;i<n;i++){
        while(!st.empty() && a[st.top()].first<=a[i].first) st.pop();
        if(st.empty()) pge[i]=-1;
        else pge[i]=st.top();
        st.push(i);
    }
    while(!st.empty()) st.pop();
     for(int i=n-1;i>=0;i--){
        while(!st.empty() && a[st.top()].first<=a[i].first) st.pop();
        if(st.empty()) nge[i]=-1;
        else nge[i]=st.top();
        st.push(i);
    }
    sort(all(a));
    vector<int> dp(n);
    for(int i=0;i<n;i++){
        int idx=a[i].second;
        int ngeidx=nge[idx];
        int pgeidx=pge[idx];
        dp[idx]=1;
        if(ngeidx!=-1) dp[idx]=max(dp[idx],dp[ngeidx]+1);
        if(pgeidx!=-1) dp[idx]=max(dp[idx],dp[pgeidx]+1);

    }

    cout<<*max_element(all(dp))<<endl;

   
}

int main(){
    fast_io;
    int t=1;
    //cin >> t;
    while(t--) solve();
    return 0;
}