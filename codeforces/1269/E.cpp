#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define ll long long
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
//#define int long long
#define all(c) (c).begin(),(c).end()
#define M 1000000007
#define INF LLONG_MAX
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cerr << str << " : " << t << "\n";}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cerr << str.substr(0, idx) << " : " << t << ", "; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cerr << "["; for (T i = a; i != b; ++i) {if (i != a) cerr << ", "; cerr << *i;} cerr << "]\n";}
// Use pr(a,b,c,d,e) or cerr<<anything or prc(v.begin(),v.end()) or prc(v,v+n)
//  

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set =  tree <T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
/*
     find_by_order(k): returns iterator to kth largest element (counting from 0)
     order_of_key (k): returns number of items which are strictly less than k
     remove #define int long long from template
*/

ordered_set<int> os;
// cp-algorithms
struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    ll sum(int r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    ll sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};       


int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n);
    FenwickTree ft(n+1);	
    map<int, int> m;
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        m[a[i]] = i;
    }
    ll curr_inversion = 0;
    for(int i=1;i<=n;i++)
    {
        curr_inversion += (int)os.size() - os.order_of_key(m[i]);
        //pr(curr_inversion);
        ft.add(m[i], m[i]);
        os.insert(m[i]);
        if(i%2)
        {
            ll median = *os.find_by_order(i/2);
            ll z = i/2;
            ll lsum = median*z - ft.sum(median-1) - (z*(z+1))/2;
            ll rsum = ft.sum(median+1, n-1) - median*z - (z*(z+1))/2;
            //pr(lsum, rsum, curr_inversion, median);
            cout << curr_inversion + lsum + rsum << " "; 
        }
        else
        {
            ll m1 = *os.find_by_order(i/2), m2 = *os.find_by_order((i-1)/2);
            ll curr_med = (m1 + m2)/2;
            ll additional = 0;
            if(curr_med != m2) additional = i/2;
            ll z = i/2;
            ll l = z;
            if(!additional) l--;
            ll lsum = curr_med*l - ft.sum(curr_med - 1) - (l*(l+1))/2;
            ll rsum = ft.sum(curr_med+1, n-1) - curr_med*z - (z*(z+1))/2; 
            //pr(lsum, rsum, curr_inversion, curr_med, m1, m2, additional);
            cout << curr_inversion + lsum + rsum + additional << " ";
        }
    }


    return 0;
}

