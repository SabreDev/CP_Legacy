#include <bits/stdc++.h>
using namespace std;
namespace __gnu_pbds {}
using namespace __gnu_pbds;
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
#define rng(i,a,b) for(int i=a;i<b;i++)
#define ar array

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;


// typedef tree<
// T,
// null_type,
// less<T>,
// rb_tree_tag,
// tree_order_statistics_node_update>
// ordered_set;
 
template<typename T>
struct SortedList {
    ordered_set<pair<T, int>> ost;
    map<T, int> freq;
 
    void add(T val) { ost.insert(make_pair(val, ++freq[val])); }
    void remove(T val) { ost.erase(make_pair(val, freq[val]--)); }
    int index(T val) { return ost.order_of_key(make_pair(val, -1)); }
    T operator[] (int i) const { return ost.find_by_order(i)->first; }
 
    int lower_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, -1));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }
    int upper_bound(T val) {
        auto it = ost.lower_bound(make_pair(val, 1000000000));
        return it == ost.end() ? ost.size() : ost.order_of_key(*it);
    }
 
    int size() { return ost.size(); }
    bool empty() { return ost.empty(); }
};

int main(){
    SortedList<int> sl;
    sl.add(1);
    sl.add(1);
    sl.add(2);
    sl.add(2);
    sl.add(2);
    sl.add(3);
    //1 -> 1 -> 2 -> 2 -> 2 -> 3
    cout << sl.index(2) << " " << sl.size() <<  "\n";
}
