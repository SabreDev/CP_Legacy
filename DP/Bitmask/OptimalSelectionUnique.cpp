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

class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<unordered_set<int>> h(r);
        rep(i,r){
            rep(j,c){
                h[i].insert(grid[i][j]);
            }
        }
        vector<vector<int>> dp(1<<r, vector<int>(101, 0));
        rep(i,r){
            rng(j,1,101){
                dp[1<<i][j] = (h[i].contains(j) ? j : 0);
            }
        }
        rep(mask,1<<r){
            rep(i,r){
                if(mask&(1<<i)){
                    rng(j,1,101){
                        if(h[i].contains(j)){
                            rng(k,1,j){
                                dp[mask][j] = max(dp[mask][j], dp[mask^(1<<i)][k] + j);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        rep(mask,1<<r){
            rng(j,1,101){
                ans=max(ans, dp[mask][j]);
            }
        }
        return ans;
    }
};