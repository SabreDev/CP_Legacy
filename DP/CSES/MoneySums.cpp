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
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i,n)
    cin >> x[i];
	int MAX_S = accumulate(all(x), 1);

	bool dp[MAX_S];
	
	rep(i, MAX_S)
		dp[i]=false;
	
	dp[0]=true;

	rep(i,n){
		for(int j=MAX_S; j>=x[i]; --j){
			dp[j] = dp[j] | dp[j-x[i]];
		}
	}

	vector<int> ans;
	rng(i,1,MAX_S){
		if(dp[i]){
			ans.pb(i);
		}
	}
	cout << ans.size() << '\n';
	for(int x: ans)
		cout << x << " ";
	cout << "\n";

}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}