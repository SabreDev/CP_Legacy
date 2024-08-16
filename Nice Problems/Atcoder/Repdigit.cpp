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

//Link: https://atcoder.jp/contests/arc149/tasks/arc149_a
void run_case() {
	int n,m;
	cin >> n >> m;
	int mx_d = 1;
	int mx_sz = 0;
	rng(d, 1, 10){
		int pn = 0;
		rng(sz, 1, n+1){
			int nn = (10*pn + d)%m;
			if(nn==0){
				if(sz>=mx_sz){
					mx_d = d;
					mx_sz = sz;
				}
			}
			pn = nn;
		}
	}
	if(mx_sz==0){
		cout << -1;
	} else {
		rep(i,mx_sz){
			cout << mx_d;
		}
		cout << "\n";
	}
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
