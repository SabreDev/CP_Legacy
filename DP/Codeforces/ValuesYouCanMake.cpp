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
  int n,s;
  cin >> n >> s;
  vector<int> c(n);
  rep(i,n)
    cin >> c[i];
  
	vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(s+1, vector<bool>(s+1, false)));
	//dp[i][j][k] -> can we make subset of subset sum j with total subset sum k using coins till index i
	//dp[-][0][0] -> true
	rep(i,n)
		dp[i][0][0] = true;
	if(c[0]<=s){
		dp[0][0][c[0]] = true;
		dp[0][c[0]][c[0]] = true;
	}


	rng(i,1,n){
		rep(j,s+1){
			rng(k,j,s+1){
				bool ans = dp[i-1][j][k];
				if(k>=c[i]){
					ans = ans | dp[i-1][j][k-c[i]];
					if(j>=c[i])
						ans = ans | dp[i-1][j-c[i]][k-c[i]];
				}
				dp[i][j][k] =  ans;
			}
		}
	}
	vector<int> ans;
	rep(j,s+1){
		if(dp[n-1][j][s])
			ans.pb(j);
	}

	cout << ans.size() << "\n";
	for(int x: ans)
		cout << x << " ";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}