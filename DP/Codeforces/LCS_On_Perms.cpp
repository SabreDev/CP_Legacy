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
const int INF = 2e9;

void run_case() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	vector<int> pos(n+1);

	rep(i,n)
		cin >> a[i];
	rep(i,n){
		cin >> b[i];
		pos[b[i]] = i;
	}

	vector<int> dp(n+1, 1);
	set<int> seen;

	rep(i,n){
		int idx = pos[a[i]];
		seen.insert(idx);
		auto j = seen.lower_bound(idx);
		auto en = --seen.end();
		if(j!=seen.begin()){
			--j;
			dp[b[idx]] = max({dp[b[idx]], dp[b[*j]] + 1, i>0 ? dp[a[i-1]] : 0, dp[b[*en]]});
		} else {
			dp[b[idx]] = max({1, i>0 ? dp[a[i-1]] : 0, dp[b[*en]]});
		}
	}
	cout << *max_element(all(dp)) << "\n";

}

int main(){
	fast;
  int t = 1;
  while(t--)
		run_case();
}