#include <bits/stdc++.h>
using namespace std;
// using u128 = __int128;
using u64 = unsigned long long;
#define SPIDERMAN                 \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define loop(i, b, n) for (int i = b; i < n; i++)
#define rloop(i, b, n) for (int i = b; i >= n; i--)
#define p(s) cout << s << endl
#define all(x) x.begin(), x.end()
#define pb push_back 

#define map(mp) map<int, int> mp;

#define getarray(arr)\
    int arr[n];\
    loop(i, 0, n) cin >> arr[i];

#define mex(v) ([&](){ unordered_set<int> st(all(v)); int x=0; while(st.count(x)) x++; return x; }())

void just_win_today(){
    int n;cin>>n;
    vector<vector<char>>grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int>>visited(n,vector<int>(n,-1));
    string ans="";
    ans+=grid[0][0];
    queue<pair<int,int>>qq;
    qq.push({0,0});
    int temp=0;
    for(int i=1;i<2*n-1;i++){
        char best='Z';
        vector<pair<int,int>>check;
        while(!qq.empty()){
            auto q=qq.front();
            qq.pop();
            int x=q.first,y=q.second;
            if(x+1<n){
                check.pb({x+1,y});
                best=min(best,grid[x+1][y]);
            }
            if(y+1<n){
                check.pb({x,y+1});
                best=min(best,grid[x][y+1]);
            }
        }
        temp++;
        for(auto q:check){
            int x=q.first,y=q.second;
            if(grid[x][y]==best && visited[x][y]!=temp){
                visited[x][y]=temp;
                qq.push({x,y});
            }
        }
        ans+=best;
    }

    p(ans);
    
    
}



/*-------------------------------------------------------------------------------------------------------------------------------------*/

signed main()
{
    SPIDERMAN
    int t = 1;
    // cin >> t;
    // facts();
    //check prime using miller robin with isPrime()... for 
    while (t--)
    {
        just_win_today();
    }
    return 0;
}