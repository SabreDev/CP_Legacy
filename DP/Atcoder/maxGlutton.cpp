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

//Problem link: https://atcoder.jp/contests/abc364/tasks/abc364_e

void run_case() {
  int n,x,y;
	cin >> n >> x >> y;
	vector<pi> dish(n);
	rep(i,n)
		cin >> dish[i].F >> dish[i].S;
	const int INF = 1e9;
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n+1, vector<int>(x+1, INF)));
	dp[0][0][0] = 0;
	if(dish[0].F<=x)
		dp[0][1][dish[0].F] = dish[0].S;
	
	rng(i,1,n){
		rep(j,i+2){
			rep(k,x+1){
				dp[i][j][k] = dp[i-1][j][k];
				if(j>0 && k>=dish[i].F)
					dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-1][k - dish[i].F] + dish[i].S);
			}
		}
	}
	int ans = 0;
	rep(j,n+1){
		rep(k,x+1){
			if(dp[n-1][j][k]<=y){
				ans=max(ans, j);
			}
		}
	}
	cout << min(n, ans + 1) << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
