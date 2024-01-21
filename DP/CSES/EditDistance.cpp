#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<int,int>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array


void run_case() {
	string a,b;
	cin >> a >> b;

	int n = a.length();
	int m = b.length();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 3*(n+m)));

	rep(i,m+1)
		dp[0][i] = i;
	rep(i,n+1)
		dp[i][0] = i;

	rng(i,1,n+1){
		rng(j,1,m+1){
			if(a[i-1]==b[j-1])
				dp[i][j] = dp[i-1][j-1];
			dp[i][j] = min({dp[i][j], dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
		}
	}

	cout << dp[n][m] << "\n";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
