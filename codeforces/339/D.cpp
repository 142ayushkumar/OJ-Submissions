#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
#define all(c) (c).begin(),(c).end()
#define M 1000000007
#define ll long long
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
struct ST{
    int sum;
    ST(int sum = 0) : sum(sum) {}
};
const int N = 1e5 + 5;
ST operator | (const ST &A, const ST &B) {
	/**Merging Logic**/
    return (ST(A.sum | B.sum));
}
ST operator ^ (const ST& A, const ST &B) {
    return (ST(A.sum ^ B.sum));
}

struct segtree {
    vector<ST> tree;
    vector<int> A;
    segtree(int n = N) {
        tree.resize(4 * n);
        A.resize(n+1);
    }

    void build(int node, int start, int end, int lev) {
        if(start == end) {
            tree[node] = ST(A[start]);
        }
        else {
            int mid = (start + end) >> 1;
            build(2 * node, start, mid, 1-lev);
            build(2 * node + 1, mid+1, end, 1-lev);
            int n = A.size();
            if(lev)
                tree[node] = (tree[2 * node] ^ tree[2 * node + 1]);
            else
                tree[node] = (tree[2 * node] | tree[2 * node + 1]);
        }
    }

    void update(int node, int start, int end, int idx, ll val, int lev) {
        if(start == end) {
            tree[node].sum = val;
        }
        else {
            int mid = (start + end) >> 1;
            if(idx <= mid) update(2 * node, start, mid, idx, val, 1-lev);
            else update(2 * node + 1, mid + 1, end, idx, val, 1-lev);
            if(lev)
                tree[node] = (tree[2 * node] ^ tree[2 * node + 1]);
            else
                tree[node] = (tree[2 * node] | tree[2 * node + 1]);
     
        }
    }

    //ST query(int node, int start, int end, int l, int r) {
    //    if(start >= l && end <= r) return tree[node];
    //    int mid = (start + end) >> 1;
    //    if(mid >= r) return query(2 * node, start, mid, l, r);
    //    if(mid < l) return query(2 * node + 1, mid + 1, end, l, r);
    //    ST P1 = query(2 * node, start, mid, l, r);
    //    ST P2 = query(2 * node + 1, mid + 1, end, l, r);
    //    return P1 + P2;
    //}
};

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> v(1<<n);
    struct segtree st((1<<n));
    for(int i=0;i<(1<<n);i++)
    {
        cin >> v[i];
        st.A[i+1] = v[i];
    }
    st.build(1, 1, (1<<n), 1-(n%2));
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        st.update(1, 1, (1<<n), a, b, 1-(n%2));
        cout << st.tree[1].sum << "\n";
    }
    return 0;
}

