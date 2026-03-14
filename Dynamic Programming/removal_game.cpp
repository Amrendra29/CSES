#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  long long sum = 0;
  for (int&v : x) {
    cin >> v;
    sum += v;
  }

  vector<vector<long long>> dp(n,vector<long long>(n));
  for (int l = n-1; l >= 0; l--) {
    for (int r = l; r < n; r++) {
      if (l == r) {
	dp[l][r] = x[l];
      } else {
	dp[l][r] = max(x[l]-dp[l+1][r],
		       x[r]-dp[l][r-1]);
      }
    }
  }
 // dp[0][n-1] = player1_score − player2_score
    //  P1 = player1 score
    // P2 = player2 score
    //dp[0][n-1] = P1 − P2
    //sum = P1 + P2
    // 2*P1=sum+diff
    //P1=(sum+diff)/2
  cout << (sum+dp[0][n-1])/2 << endl;
}