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

//Problem link: https://codeforces.com/problemset/problem/495/B

void run_case() {
	int a,b;
	cin >> a >> b;
	if(b>a)
		cout << 0 << "\n";
	else if(a==b)
		cout << "infinity" << "\n";
	else {
		a-=b;
		vector<int> divs;
		for(int i=1;i*i<=a;++i){
			if(a%i==0){
				divs.pb(i);
				if(i*i != a)
					divs.pb(a/i);
			}
		}
		sort(all(divs));
		int lb = lower_bound(all(divs), b+1) - divs.begin();
		int sz = divs.size();
		cout << sz - lb << '\n';
	}
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
