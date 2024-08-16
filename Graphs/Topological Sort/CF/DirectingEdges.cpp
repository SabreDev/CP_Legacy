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

void run_case() {
  int n,m;
	cin >> n >> m;
	vector<set<int>> undir(n);
	vector<vector<int>> dir(n);
	vector<int> in(n, 0), out(n, 0);
	rep(i,m){
		int t,x,y;
		cin >> t >> x >> y;
		if(t==0){
			undir[x].insert(y);
			undir[y].insert(x);
		} else {
			dir[x].pb(y);
			++in[y];
			++out[x];
		}
	}
	vector<bool> vis(n, false);
	rep(i,n){
		if(in[i]==0 && !vis[i]){
			
		}
	}

}
 
int main() {
  fast;
  int t;
	cin >> t;
  while(t--){
    run_case();
  }
}
