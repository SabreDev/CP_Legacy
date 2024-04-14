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

void coordinate_compress(vector<int> &inp, vector<int> &op, int orig_size){
	sort(all(inp));
	inp.resize(distance(inp.begin(), unique(all(inp))));

	map<int,int> compressed;

	rep(i,(int)inp.size()){
		compressed[inp[i]] = i+1;
	}
	rep(i,orig_size){
		op[i] = compressed[op[i]];
	}
}

void run_case(){
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n){
		cin >> a[i];
	}
	vector<int> b = a;
	coordinate_compress(a, b, n);
	
	//Element x comes
	//LCS ending at x-1. dp[x] = dp[x-1] + 1;
	//dp[x] -> LCS ending at x
	//p[x] -> parent of LCS ending at x (idx).
	//p[x] = idx of (x - 1);

	vector<pi> dp(n+1, {0, -1});
	vector<int> p(n);

	rep(i,n){
		if(dp[b[i] - 1].F > 0 && dp[b[i] - 1].F + 1 >= dp[b[i]].F) {
			dp[b[i]].F = dp[b[i] - 1].F + 1;
			dp[b[i]].S = i;
			p[i] = dp[b[i] - 1].S;
		} else {
			if(dp[b[i]].F==0){
				dp[b[i]].F = 1;
				dp[b[i]].S = i;
				p[i] = i;
			}
		}
	}

	int mx = 1;
	int start = 0;
	rep(i,n){
		if(dp[b[i]].F >= mx){
			mx = dp[b[i]].F;
			start = dp[b[i]].S;
		}
	}

	cout << mx << "\n";
	vector<int> pars;
	while(true){
		pars.pb(start);
		start = p[start];
		if(start == -1 || start == pars.back())
			break;
	}

	reverse(all(pars));
	for(int x : pars)
		cout << x+1 << " ";
	cout << "\n";

}

int main(){
	fast;
  int t = 1;
  while(t--)
		run_case();
}