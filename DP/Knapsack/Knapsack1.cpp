#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

//problem link: https://atcoder.jp/contests/dp/tasks/dp_d

void run_case() {
	int n,b;
	cin >> n >> b;
	vector<int> w(n), v(n);
	rep(i,n)
		cin >> w[i] >> v[i];

	vector<vector<ll>> dp(n, vector<ll>(b+1, 0));
	rep(i,b+1){
		if(i>=w[0])
			dp[0][i] = v[0];
	}
	rng(i,1,n){
		rep(j,b+1){
			dp[i][j] = max(dp[i-1][j], j>=w[i]?dp[i-1][j-w[i]] + 1LL*v[i]:0);
		}
	}
	
	cout << dp[n-1][b] << "\n";
}
 
int main() {
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
