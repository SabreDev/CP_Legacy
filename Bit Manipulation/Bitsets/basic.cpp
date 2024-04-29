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
	// bitset<10> x[100];
	
	// x[0] = 30;
	// x[1] = 55;
	// cout << (x[0] ^ x[1]) << "\n";

	bitset<100000> x; // 16 bytes
	// 4*(10/W)
	// 8*(10/64) = 8 bytes
	// 8*(66/64)
	// rep(i,5){
	// 	int a;
	// 	cin >> a;
	// 	x[a]=true;
	// }
	cout << sizeof(x) << "\n";
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
