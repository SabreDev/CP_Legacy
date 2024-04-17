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

//Problem link : https://cses.fi/problemset/task/1147

vector<int> nearest_smaller_left(int m, vector<int> &heights){
	stack<pi> st;
	vector<int> ans(m, -1);
	rrep(i,m){
		while(!st.empty() && st.top().F > heights[i]){
			ans[st.top().S] = i;
			st.pop();
		}
		st.push(mp(heights[i], i));
	}
	return ans;
}

vector<int> nearest_smaller_right(int m, vector<int> &heights){
	stack<pi> st;
	vector<int> ans(m, m);
	rep(i,m){
		while(!st.empty() && st.top().F > heights[i]){
			ans[st.top().S] = i;
			st.pop();
		}
		st.push(mp(heights[i], i));
	}
	return ans;
}


int calc_max_rect(int m, vector<int> &heights){
	vector<int> nsl = nearest_smaller_left(m, heights);
	vector<int> nsr = nearest_smaller_right(m, heights);
	int ans = 0;
	rep(i,m){
		ans = max(ans, heights[i]*(nsr[i] - nsl[i] - 1));
	}
	return ans;
}

void run_case() {
	int n,m;
	cin >> n >> m;
	char g[n][m];
	rep(i,n)
		rep(j,m)
			cin >> g[i][j];
	
	vector<queue<pi>> q(m);
	rep(i,m){
		rrep(j,n){
			if(g[j][i]=='*')
				q[i].push(mp(j,i));
		}
	}

	int ans = 0;
	rrep(i,n){
		vector<int> heights(m);
		rep(j,m){
			int nearest_tree_idx;

			if(!q[j].empty())
				nearest_tree_idx = q[j].front().F;
			else
				nearest_tree_idx = -1;
			
			if(g[i][j]=='*'){
				heights[j]=0;
				q[j].pop();
			}
			else
				heights[j] = i - nearest_tree_idx;
		}
		ans = max(ans, calc_max_rect(m, heights));
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
