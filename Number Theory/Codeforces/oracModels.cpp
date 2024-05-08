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

//Problem link: https://codeforces.com/problemset/problem/1350/B

void run_case() {
	int n;
	cin >> n;
	vector<int> sz(n+1);
	rep(i,n){
		cin >> sz[i+1];
	}

	vector<vector<int>> divs(n+1);
	rng(i,1,n+1){
		for(int j=1;j*j<=i;++j){
			if((i%j)==0){
				divs[i].pb(j);
				if((i/j) != j)
					divs[i].pb(i/j);
			}
		}
	}

	vector<int> dp(n+1, 1);
	for(int i=2;i<=n;i++){
		for(int x: divs[i]){
			if(sz[x] < sz[i])
				dp[i] = max(dp[i], dp[x] + 1);
		}
	}

	int ans = 1;	
	rng(i,2,n+1){
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
