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

//Problem link : https://codeforces.com/contest/547/problem/B

vector<int> next_smaller_right(int n, vector<int> &a){
	stack<pi> st;
	vector<int> ret(n, n);
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
	vector<int> a(n);
	rep(i,n)
		cin >> a[i];
	vector<int> nsr = next_smaller_right(n, a);
	vector<int> nsl = next_smaller_left(n, a);

	vector<int> ans(n+1, 0);

	rep(i,n){
		int len = nsr[i] - nsl[i] - 1;
		ans[len] = max(ans[len], a[i]);
	}

	rrep(i,n+1){
		ans[i] = max(ans[i], (i<n ? ans[i+1] : 0));
	}

	rng(i,1,n+1)
		cout << ans[i] << " ";

	
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
