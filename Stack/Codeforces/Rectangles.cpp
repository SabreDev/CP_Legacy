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
//Easier version of above problem where we want to calculate area of max rectangle of same digits.

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


int calc_max_area(int m, vector<pi> &heights){
	vector<int> nsl = nearest_smaller_left(m, heights);
	vector<int> nsr = nearest_smaller_right(m, heights);

	int ans = 0;
	rep(i,m){
		ans = max(ans, heights[i].S*(nsr[i] - nsl[i] - 1));
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

	int ans = 0;
	rrep(i,n){
		vector<pi> heights(m); //elem being processed, its height
		rep(j,m){
			heights[j] = mp(g[i][j], i - idx[j][i]);
		}
		ans = max(ans, calc_max_area(m, heights));
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
