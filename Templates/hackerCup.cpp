#include <bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define all(v) v.begin(),v.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define pi pair<ll,ll>
#define pii pair<int,pi>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define cusrep(i,a,b,j) for(int i=a;i<b;i+=j)
#define rng(i,a,b) for(int i=a;i<b;i++)
#define rrng(i,a,b) for(int i=a;i>b;--i)
#define ar array

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0); 
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}

void run_case(int cn, bool islast) {
	int s,d,k;
	cin >> s >> d >> k;
	if((k > 2*d + s) || (k+1 > 2*d + 2*s)){
		cout << "Case #" << cn << ": " << "NO";
	} else {
		cout << "Case #" << cn << ": " << "YES";
	}
	if(!islast)
		cout << "\n";
}
 
int main() {
	setIO("_A");
  fast;
  int t;
	cin >> t;
	bool islast = false;
	int cn = 1;
  while(t--){
		islast = (t==0 ? true : false);
    run_case(cn, islast);
		++cn;
  }
}
