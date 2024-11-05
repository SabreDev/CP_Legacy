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

//problem link: https://atcoder.jp/contests/dp/tasks/dp_e

void run_case() {
	int n,b;
	cin >> n >> b;
	vector<int> w(n), v(n);
	rep(i,n)
		cin >> w[i] >> v[i];
	int MX_VAL = 1e5 + 1;
	ll LIM = 1e12;
	vector<vector<ll>> dp(n, vector<ll>(MX_VAL, LIM));
	dp[0][0] = 0;
	dp[0][v[0]] = w[0];
	rng(i,1,n){
		rep(j,MX_VAL){
			dp[i][j] = min(dp[i-1][j], j>=v[i]?dp[i-1][j-v[i]]+w[i]:LIM);
		}
	}
	int ans = 0;
	rep(i,n){
		rep(j,MX_VAL){
			if(dp[i][j]<=b){
				ans=max(ans, j);
			}
		}
	}
	cout << ans << '\n';
}
 
int main() {
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
