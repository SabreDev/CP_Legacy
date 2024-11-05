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

//https://codeforces.com/contest/1316/problem/E

void run_case() {
	int n,p,k;
	cin >> n >> p >> k;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	vector<vector<int>> s(n, vector<int>(p));
	rep(i,n){
		rep(j,p){
			cin >> s[i][j];
			s[i][j]-=a[i];
		}
	}
	vector<vector<ll>> dp(1<<p, vector<ll>(n+1, 0));
	
	rep(mask,1<<p){
		int h = __builtin_popcount(mask);
		rep(i,p){
			if(mask&(1<<i)){
				int picked = -1;
				rng(j,1,n+1){
					if(j>h){
						if(dp[mask][j-1]>=dp[mask][j]){
							dp[mask][j] = dp[mask][j-1];
						}
					}
					if(dp[mask^(1<<i)][j-1]+s[j-1][i]>=dp[mask][j]){
						dp[mask][j] = dp[mask^(1<<i)][j-1]+s[j-1][i];
					}
				}
			}
		}
	}
	vector<pi> take;
	int cur_mask = (1<<p)-1;
	int cur_idx = n;
	while(cur_idx>0){
		pii cur_par = par[cur_mask][cur_idx];
		if(cur_par.S.S==-1){
			//skip cur_idx;
			cur_idx = cur_par.S.F;
		} else {
			//take cur_idx
			take.pb({cur_idx, cur_par.S.S});
			cur_mask = cur_par.F;
			cur_idx = cur_par.S.F;
		}
	}
}
 
int main() {
  fast;
  int t=1;
  while(t--){
    run_case();
  }
}
