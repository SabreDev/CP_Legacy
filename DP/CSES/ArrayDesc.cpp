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

const ll MOD = 1e9 + 7;

void run_case() {
	int n,m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	vector<vector<ll>> dp(n, vector<ll>(m+1, 0));
	dp[0][a[0]] = 1;
	if(a[0]==0){
		rng(i,1,m+1)
			dp[0][i] = 1;
	}

	rng(i,1,n){
		if(a[i]==0){
			rng(j,1,m+1){
				dp[i][j] = ((j>1 ? dp[i-1][j-1] : 0) + dp[i-1][j] + (j<m ? dp[i-1][j+1] : 0))%MOD;
			}
		} else {
			dp[i][a[i]] = ((a[i]>1 ? dp[i-1][a[i]-1] : 0) + dp[i-1][a[i]] + (a[i]<m ? dp[i-1][a[i]+1] : 0))%MOD;
		}
	}
	ll ans = 0;
	rng(i,1,m+1){
		(ans+=dp[n-1][i])%=MOD;
	}
	cout << ans << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
