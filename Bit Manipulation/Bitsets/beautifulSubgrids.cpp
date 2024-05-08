#include <bits/stdc++.h>
#pragma GCC target("popcnt")
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

//Problem link: https://cses.fi/problemset/task/2137/
//Note: popcnt pragma replaces builtin popocount with machine instruction hence speeding up the runtime of count function of bitset.

const int maxN = 3001;

//Memory: O(ceil((maxN * sz)/W)*(W/8))

bitset<maxN> grid[maxN];

void run_case() {
	int n;
	cin >> n;
	rep(i,n)
		cin >> grid[i];
	
	ll ans = 0;
	rep(i,n){
		rng(j,i+1,n){
			if(i==j)
				continue;
			int cnt = (grid[i]&grid[j]).count();
			ans+=(cnt*(cnt-1))/2;
		}
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
