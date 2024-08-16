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

int get_idx(char x){
	return (int)(x - 'a');
}
void run_case() {
  int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n){
		cin >> s[i];
	}
	vector<vector<int>> g(26);
	vector<int> in(26, 0);
	set<int> seen;
	rep(i,n-1){
		int j = 0;
		while(j<s[i].length() && j<s[i+1].length() && s[i][j]==s[i+1][j]){
			++j;
		}
		if((j==s[i].length() || j==s[i+1].length()) && s[i].length() > s[i+1].length()){
			cout << "Impossible";
			return;
		}

		if(j<s[i].length() && j<s[i+1].length() && s[i][j]!=s[i+1][j]){
			g[get_idx(s[i][j])].pb(get_idx(s[i+1][j]));
			seen.insert(get_idx(s[i][j]));
			seen.insert(get_idx(s[i+1][j]));
			++in[get_idx(s[i+1][j])];
		}
	}
	queue<int> q;
	rep(i,26){
		if(seen.count(i) > 0 && in[i]==0)
			q.push(i);
	}
	vector<int> topo_sort;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo_sort.pb(u);
		for(int v: g[u]){
			--in[v];
			if(in[v]==0){
				q.push(v);
			}
		}
	}
	
	if(topo_sort.size()!=seen.size()){
		cout << "Impossible";
		return;
	}
	vector<char> order;
	for(int x: topo_sort){
		order.pb(char(x+'a'));
	}
	for(char x='a'; x<='z'; ++x){
		if(seen.count(get_idx(x))==0)
			order.pb(x);
	}
	for(char x: order)
		cout << x;
	cout << '\n';
}
 
int main() {
  fast;
  int t = 1;
  while(t--){
    run_case();
  }
}
