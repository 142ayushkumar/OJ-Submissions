#include <bits/stdc++.h>

using namespace std;

const double PI = 3.141592653589;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define int long long
#define ll long long
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
/*
 * 1 based index, define N (max length of array possible)
 * Point update, increment of a[i] by b
 */
const int N = 1e6 + 5; // change n accordingly
struct ST{
    int sum;
    ST(int sum = 0) : sum(sum) {}
};

ST operator + (const ST &A, const ST &B) {
    /**Merging Logic**/
  /*
   * for example for range sum query return (ST(A.sum + B.sum));
   */
    return (ST(A.sum + B.sum));
}

struct segtree {
    vector<ST> tree;
    vector<int> A;
    segtree(int n = N) {
        tree.resize(4 * n);
        A.resize(n, 0);
    }

    void build(int node, int start, int end) {
        if(start == end) {
            tree[node] = ST(A[start]);
        }
        else {
            int mid = (start + end) >> 1;
            build(2 * node, start, mid);
            build(2 * node + 1, mid+1, end);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, ll val) {
        if(start == end) {
            tree[node].sum += val;
        }
        else {
            int mid = (start + end) >> 1;
            if(idx <= mid) update(2 * node, start, mid, idx, val);
            else update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = tree[2 * node] + tree[2 * node + 1];
        }
    }

    ST query(int node, int start, int end, int l, int r) {
        if(start >= l && end <= r) return tree[node];
        int mid = (start + end) >> 1;
        if(mid >= r) return query(2 * node, start, mid, l, r);
        if(mid < l) return query(2 * node + 1, mid + 1, end, l, r);
        ST P1 = query(2 * node, start, mid, l, r);
        ST P2 = query(2 * node + 1, mid + 1, end, l, r);
        return P1 + P2;
    }
};

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        cin >> v[i];
    // compress
    vector<int> b(n), c(v);
    iota(all(b), 0);
    sort(all(b), [&](int x, int y) {return v[x] < v[y];});
    int t = 1;
    for(int i=0;i<n;i++)
    {
        if(i && c[b[i]] != c[b[i-1]]) t++;
        v[b[i]] = t;
    }
    struct segtree st;
    vector<int> temp(n);
    st.build(1, 0, N-1);
    for(int i=n-1;i>=0;i--)
    {
        st.update(1, 1, N, v[i], 1);
        if(v[i] != 1)
            temp[i] = st.query(1, 1, N, 1, v[i]-1).sum;
        else temp[i] = 0;
    }
    int ans = 0;
    st.build(1, 0, N-1);
    for(int i=n-1;i>=0;i--)
    {
        st.update(1, 1, N, v[i], temp[i]);
        if(v[i] != 1)
            ans += st.query(1, 1, N, 1, v[i] - 1).sum;
        
    }
    cout << ans << "\n";


    return 0;
}

