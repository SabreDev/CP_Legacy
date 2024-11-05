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

//https://atcoder.jp/contests/dp/tasks/dp_o?lang=en

void run_case() {
	int n;
	cin >> n;
	vector<vector<int>> g(n, vector<int>(n));
	rep(i,n){
		rep(j,n){
			cin >> g[i][j];
		}
	}
	vector<vector<int>> dp(1<<n, vector<int>(n+1,0));
	int mod = 1e9 + 7;
	dp[0][0] = 1;
	rng(mask,1,1<<n){
		int p = __builtin_popcount(mask);
		rng(i,p,n+1){
			rep(j,n){
				if(mask&(1<<j)){
					if(i>p){
						(dp[mask][i]+=dp[mask^(1<<j)][i]);
						if(dp[mask][i]>=mod)
							dp[mask][i]-=mod;
					}
					if(g[j][i-1]==1){
						(dp[mask][i]+=dp[mask^(1<<j)][i-1]);
						if(dp[mask][i]>=mod)
							dp[mask][i]-=mod;	
					}
				}
			}
		}
	}
	cout << dp[(1<<n)-1][n] << "\n";
}
 
int main() {
  fast;
  int t=1;
  while(t--){
    run_case();
  }
}
