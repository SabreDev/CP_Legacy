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
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

vector<ll> dp(200010, -1);

ll solve(int idx, vector<vector<int>> &p) {
	if(idx == (int)p.size()){
		return 0;
	}
	if(dp[idx]!=-1)
		return dp[idx];
	
	ll ans = 0;

	int n_idx = upper_bound(all(p), vector<int>{p[idx][1], -1, -1}, [](const vector<int> &a, const vector<int> &b){
		return a[0] < b[0]; //a is supplied vector and b is other vectors in p.
	}) - p.begin();

	ans = solve(n_idx, p) + p[idx][2];
	ans = max(ans, solve(idx + 1, p));
	return dp[idx] = ans;
}

void run_case(){
	int n;
	cin >> n;
	vector<vector<int>> p(n, vector<int>(3));
	rep(i,n){
		cin >> p[i][0] >> p[i][1] >> p[i][2];
	}
	sort(all(p), [](const vector<int> &a, const vector<int> &b){
		return a[0] < b[0];
	});

	cout << solve(0, p) << "\n";
}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}