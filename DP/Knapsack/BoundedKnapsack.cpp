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
 
//problem link: https://cses.fi/problemset/task/1159
 
void run_case() {
	int n,x;
	cin >> n >> x;
	vector<int> p(n), v(n);
	rep(i,n)
		cin >> p[i];
	rep(i,n)
		cin >> v[i];
	vector<pi> pv;
	rep(i,n){
		int f;
		cin >> f;
		vector<int> vals;
		int cur = 0;
		int _p = 0;
		while(cur<f){
			if(cur + (1<<_p) <= f){
				cur+=(1<<_p);
				vals.pb((1<<_p));
				++_p;
			} else {
				vals.pb(f - cur);
				cur = f;
			}
		}
		for(int val: vals){
			pv.pb({val*p[i], val*v[i]});
		}
	}
	int _n = (int)pv.size();
	pv.resize(_n);
	vector<vector<int>> dp(_n, vector<int>(x+1, 0));
	rep(i,x+1){
		if(i>=pv[0].F)
			dp[0][i] = pv[0].S;
	}
	rng(i,1,_n){
		rep(j,x+1){
			dp[i][j] = max(dp[i-1][j], (j>=pv[i].F ? (dp[i-1][j-pv[i].F] + pv[i].S) : 0));
		}
	}
	cout << dp[_n-1][x] << "\n";
}
 
int main() {
	fast;
  int t = 1;
  while(t--){
    run_case();
  }
}