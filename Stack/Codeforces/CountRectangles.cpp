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

//Problem link : https://codeforces.com/gym/101102/problem/D

vector<int> nearest_smaller_right(int m, vector<pi> &heights){
	stack<pair<pi, int>> st; //elem being processed, its index
	vector<int> ret(m, m);
	rep(i,m){
		if(st.empty()){
			st.push(mp(heights[i],i));
			continue;
		}

		if(st.top().F.F == heights[i].F) {
			while(!st.empty() && (st.top().F.S > heights[i].S)){
				ret[st.top().S] = i;
				st.pop();
			}
		} else {
			while(!st.empty()){
				ret[st.top().S] = i;
				st.pop();
			}
		}
		st.push(mp(heights[i], i));
	}
	return ret;
}

vector<int> nearest_smaller_left(int m, vector<pi> &heights){
	stack<pair<pi, int>> st; //elem being processed, its index
	vector<int> ret(m, -1);
	rrep(i,m){
		if(st.empty()){
			st.push(mp(heights[i],i));
			continue;
		}

		if(st.top().F.F == heights[i].F) {
			while(!st.empty() && (st.top().F.S > heights[i].S)){
				ret[st.top().S] = i;
				st.pop();
			}
		} else {
			while(!st.empty()){
				ret[st.top().S] = i;
				st.pop();
			}
		}
		st.push(mp(heights[i], i));
	}
	return ret;
}


ll calc_max_area(int m, vector<pi> &heights){
	vector<int> nsl = nearest_smaller_left(m, heights);
	vector<int> nsr = nearest_smaller_right(m, heights);

	ll ans = 0;
	rep(i,m){
		int l = nsl[i];
		int r = nsr[i];
		int len = (r - l - 1);
    int surrounding = max(l == -1 ? 0 : heights[l].S, r == (int)heights.size() ? 0 : heights[r].S);
    ans+=(1LL)*(heights[i].S - surrounding) * len * (len + 1) / 2;
	}
	return ans;
}

void run_case() {
	int n,m;
  cin >> n >> m;
	int g[n][m];
	rep(i,n)
		rep(j,m)
			cin >> g[i][j];

	//Find nearest element not equal to current element idx[m][n] in that column
	vector<vector<int>> idx(m, vector<int>(n, -1));
	
	rep(i,m){
		stack<pi> st;
		rrep(j,n){
			while(!st.empty() && st.top().F != g[j][i]){
				idx[i][st.top().S] = j ;
				st.pop();
			}
			st.push(mp(g[j][i], j));
		}
	}

	ll ans = 0;
	rrep(i,n){
		vector<pi> heights(m); //elem being processed, its height
		rep(j,m){
			heights[j] = mp(g[i][j], i - idx[j][i]);
		}
		ans+=calc_max_area(m, heights);
	}

	cout << ans << '\n';
}
 
int main() {
  fast;
  int t;
  cin >> t;
  while(t--){
    run_case();
  }
}
