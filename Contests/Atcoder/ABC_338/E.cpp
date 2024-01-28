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
	int n;
	cin >> n;
	vector<vector<int>> start(2*n+1);
	vector<vector<int>> end(2*n+1);

	rep(i,n){
		int a,b;
		cin >> a >> b;
		if(a>b)
			swap(a,b);
		start[a].pb(i);
		end[b].pb(i);
	}

	stack<int> st;

	rng(i,1,2*n+1){
		if((int)start[i].size() > 1 || (int)end[i].size() > 1){
			cout << "Yes" << '\n';
			return;
		}
		if((int)end[i].size() == 1){
			int tp = st.top();
			if(tp != end[i][0]){
				cout << "Yes" << "\n";
				return;
			}
			st.pop();
		}
		if((int)start[i].size() == 1){
			st.push(start[i][0]);
		}
	}
	cout << "No" << "\n";

}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
