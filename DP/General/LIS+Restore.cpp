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
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];

	//dp[i] -> smallest last element in a LIS of length i.
	//c[i] -> index of element where LIS of length i ends (index of the smallest last element calculated above)
	//p[i] -> previous index of element of an optimal subsequence ending at element i.
	vector<int> dp(n+1, INF);
	map<pi,int> p;
	vector<int> c(n+1, -1);

	dp[0] = -INF;

	rep(i,n){
		int idx = upper_bound(all(dp), a[i]) - dp.begin();
		if(dp[idx] > a[i] && a[i] > dp[idx - 1]){
			dp[idx] = a[i];
			p[{a[i],i}] = c[idx-1];
			c[idx] = i;
		}
	}

	int length;
	rrng(i,n,0){
		if(dp[i] < INF) {
			length = i;
			break;
		}
	}
	int idx = length;
	cout << length << "\n";
	pi cur = {a[c[idx]], c[idx]};
	vector<pi> lis;

	while(true) {
		lis.pb(cur);
		idx = p[cur];
		if(idx == -1)
			break;
		cur = {a[idx], idx};
	}

	for(pi x: lis)
		cout << "{" << x.F << " " << x.S  + 1 << "}" << "\n";
	cout << '\n';
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
