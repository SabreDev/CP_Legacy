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

ll dp[5005] = {0};

void run_case() {
  int n,m;
	cin >> n >> m;
	vector<ll> w,c;
	rep(i,n){
		int f,v,p;
		cin >> f >> v >> p;
		ll sum = 0;
		ll pow = 1;
		while(sum < f) {
			sum+=pow;
			if(sum <= f) {
				w.pb(pow*v);
				c.pb(pow*p);
			} else {
				ll diff = f - sum + pow;
				w.pb(diff*v);
				c.pb(diff*p);
			}
			pow*=2;
		}
	}
	vector<vector<int>> constraints(m, vector<int>(2));
	rep(i,m){
		cin >> constraints[i][0] >> constraints[i][1];
	}

	int sz = w.size();
	w.resize(sz);
	c.resize(sz);

	rep(i,sz){
		for(ll j=5000;j>=w[i];--j){
			dp[j] = max(dp[j], dp[j-w[i]]+c[i]);
		}
	}

	ll ans = -1e18;
	rep(i,m){
		ans = max(ans, dp[constraints[i][0]] - constraints[i][1]);
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
