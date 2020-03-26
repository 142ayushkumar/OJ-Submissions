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
 * check if N needs to be changed
 * change pushdown and pushup function accordingly
 */

const int N = (int)1e6 + 5;
struct node {
    int l, r, lazy, sum;
    node(int _l = 0, int _r = 0, int _lazy = 0, int _sum = 0) :
        l(_l), r(_r), lazy(_lazy), sum(_sum) {}
};

struct STLazy {
    vector<node> T;
    vector<int> A;

    STLazy(int n = N) {
        T.resize(4 * n);
        A.resize(n);
    }

    void pushdown(int node) {
    	/** Lazy Logic **/
        if(T[node].lazy) {
            T[node].sum += T[node].lazy;
            if(T[node].l < T[node].r) {
                T[2 * node].lazy += T[node].lazy;
                T[2 * node + 1].lazy += T[node].lazy;
            }
            T[node].lazy = 0;
        }
    }

    void pushup(int node) {
    	/** Merging Logic **/
        T[node].sum = min(T[2 * node].sum, T[2 * node + 1].sum);
    }

    void build(int node, int start, int end) {
        T[node].l = start; T[node].r = end; T[node].lazy = 0;
        if(start == end) {
            T[node].sum = A[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, end);
        pushup(node);
    }

    void update(int node, int start, int end, int l, int r, int val) {
        pushdown(node);
        if(start > r || end < l) {
            return;
        }
        if(start >= l && end <= r) {
            T[node].lazy += val;
            pushdown(node);
            return;
        }
        int mid = (start + end) >> 1;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        pushup(node);
    }

    int query(int node, int start, int end, int l, int r) {
        if(start > r || end < l) {
            return (int)1e9;
        }
        pushdown(node);
        if(start >= l && end <= r) {
            return T[node].sum;
        }
        int mid = (start + end) >> 1;
        return min(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
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
    for(int i=0;i<n;i++) 
        cin >> a[i];
    STLazy st(n);
    for(int i=0;i<n;i++) st.A[i] = a[i];
    st.build(1, 0, n-1);
    int q;
    cin >> q;
    string T;
    getline(cin, T);
    while(q--)
    {
        string tmp;
        getline(cin, tmp);
        stringstream ss(tmp);
        int x, y, z;
        ss >> x >> y;
        if(ss >> z)
        {
            if(x > y)
            {
                st.update(1, 0, n-1, x, n-1, z);
                st.update(1, 0, n-1, 0, y, z);
            }
            else 
            {
                st.update(1, 0, n-1, x, y, z);
            }
        }
        else
        {
            if(x > y)
            {
                cout << min(st.query(1, 0, n-1, x, n-1), st.query(1, 0, n-1, 0, y)) << "\n";
            }
            else
            {
                cout << st.query(1, 0, n-1, x, y)<< "\n";
            }
        }
    }



    return 0;
}

