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

//Problem link: https://www.codechef.com/AABH2020/problems/ODTPIC

const int maxN = 4001;
const int sz = 100001;

//Memory: O(ceil((maxN * sz)/W)*(W/8))

bitset<maxN> cnta[sz];
bitset<maxN> cntb[sz];	


void run_case() {
  int n,m,q,x;
	cin >> n >> m >> q;

	//O(maxN/W)

	rng(i,1,n+1){
		cin >> x;
		cnta[i] = cnta[i] ^ cnta[i-1];
		cnta[i][x] = cnta[i][x] ^ 1;
	}
	
	rng(i,1,m+1){
		cin >> x;
		cntb[i] = cntb[i] ^ cntb[i-1];
		cntb[i][x] = cntb[i][x] ^ 1;
	}

	//O(q*(maxN/W))
	while(q--){
		int l1,r1,l2,r2;
		cin >> l1 >> r1 >> l2 >> r2;
		int ans = ((cnta[l1-1]^cnta[r1])^(cntb[l2-1]^cntb[r2])).count();
		cout << ans << "\n";
	}
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
