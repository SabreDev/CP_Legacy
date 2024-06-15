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

//Problem link: https://atcoder.jp/contests/dp/tasks/dp_l

ll solve(int i, int j, vector<int> &a, vector<vector<ll>> &dp){
	if(i>j)
		return 0;
	if(dp[i][j]!=-1)
		return dp[i][j];
	ll ans = 0;
	
	ans = max(a[i] - solve(i+1,j,a,dp), a[j] - solve(i,j-1,a,dp));
	
	return dp[i][j] = ans;
}

void run_case() {
  int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll>(n, -1));
	cout << solve(0,n-1,a,dp) << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
