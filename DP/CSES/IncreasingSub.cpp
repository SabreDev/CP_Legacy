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

void run_case(){
  int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	
	int INF = 2e9;
	//dp[i] -> smallest element ending at LIS of length i
	vector<int> dp(n+1, INF);
	dp[0] = -INF;
	rep(i,n){
		int idx = upper_bound(all(dp), a[i]) - dp.begin();
		if(dp[idx] > a[i] && a[i] > dp[idx-1]) {
			dp[idx] = a[i];
		}
	}
	int length = 1;
	rng(i,1,n+1){
		if(dp[i] < INF){
			length = i;
		}
	}
	cout << length << "\n";


}

int main(){
	fast;
	int t=1;
	while(t--){
    run_case();
	}
}