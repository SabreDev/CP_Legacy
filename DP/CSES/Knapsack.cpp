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

const int MOD = 1e9 + 7;

void run_case(){
  int n,x;
  cin >> n >> x;
  vector<int> h(n), s(n);
  rep(i,n)
    cin >> h[i];
	rep(i,n)
		cin >> s[i];

	vector<vector<int>> dp(2, vector<int>(x+1));

	rep(i,x+1){
		dp[0][i] = (i>=h[0] ? s[0] : 0);
	}

	rng(i,1,n){
		rep(j,x+1){
			dp[i%2][j] = max(dp[(i+1)%2][j], j>=h[i] ? (dp[(i+1)%2][j-h[i]]+ s[i]) : 0);
		}
	}
	cout << dp[(n-1)%2][x] << "\n";
 

}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}