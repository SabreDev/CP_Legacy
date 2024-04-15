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

//Problem link : https://cses.fi/problemset/task/1142/

vector<int> next_smaller_right(int n, vector<int> &a){
	stack<pi> st;
	vector<int> ret(n, -1);
	rep(i,n){
		while(!st.empty() && st.top().F > a[i]){
			ret[st.top().S] = i;
			st.pop();
		}
		st.push(mp(a[i],i));
	}
	return ret;
}

vector<int> next_smaller_left(int n, vector<int> &a){
	stack<pi> st;
	vector<int> ret(n, -1);
	rrep(i,n){
		while(!st.empty() && st.top().F > a[i]){
			ret[st.top().S] = i;
			st.pop();
		}
		st.push(mp(a[i],i));
	}
	return ret;
}

void run_case() {
	int n;
	cin >> n;
	vector<int> k(n);
	rep(i,n)
		cin >> k[i];
	vector<int> nsl = next_smaller_left(n, k);
	vector<int> nsr = next_smaller_right(n, k);

	ll ans = 0;
	rep(i,n){
		int nsli = nsl[i];
		int nslr = nsr[i];
		nslr = nslr == -1 ? n : nslr;
		ans = max(ans, 1LL*k[i]*(nslr - nsli - 1));
	}
	cout << ans << "\n";
	
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
