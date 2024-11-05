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

//https://cses.fi/problemset/task/1690/

void run_case() {
	int n,m;
	cin >> n >> m;
	vector<vector<int>> _g(n);
	rep(i,m){
		int a,b;
		cin >> a >> b;
		--a,--b;
		_g[b].pb(a);
	}
	vector<vector<int>> dp(1<<n, vector<int>(n,0));
	dp[1][0] = 1;
	int mod = 1e9 + 7;
	rep(mask,1<<n){
		if(mask&1){
			rep(i,n){
				if(mask&(1<<i)){
					for(int j: _g[i]){
						if(mask&(1<<j)){
							(dp[mask][i]+=dp[mask^(1<<i)][j])%=mod;
						}
					}
				}
			}
		}
	}
	cout << dp[(1<<n)-1][n-1] << "\n";
}
 
int main() {
  fast;
  int t=1;
  while(t--){
    run_case();
  }
}
