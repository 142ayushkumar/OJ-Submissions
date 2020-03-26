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
const int N = 1e5 + 5; // change n accordingly
struct ST{
    vector<int> count;
    ST(vector<int> count = vector<int>(26, 0)) : count(count) {}
};

ST operator + (const ST &A, const ST &B) {
    /**Merging Logic**/
  /*
   * for example for range sum query return (ST(A.sum + B.sum));
   */
    vector<int> ret(26);
    for(int i=0;i<26;i++) ret[i] = A.count[i] + B.count[i];
    return (ST(ret));
}

struct segtree {
    vector<ST> tree;
    vector<vector<int>> A;
    segtree(int n = N) {
        tree.resize(4 * n);
        A.resize(n, vector<int>(26, 0));
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

    void update(int node, int start, int end, int idx, vector<int>& val) {
        if(start == end) {
            for(int i=0;i<26;i++)
                tree[node].count[i] += val[i];
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
    string s;
    cin >> s;
    int n = s.length();
    int q;
    cin >> q;
    segtree st;
    for(int i=0;i<n;i++)
        st.A[i][s[i]-'a']++;
    st.build(1, 0, N-1);
    //prc(all(st.tree[1].count));
    while(q--)
    {
        int type, a;
        cin >> type >> a;
        if(type == 1)
        {
            char b;
            cin >> b;
            a--;
            vector<int> tmp(26, 0);
            tmp[s[a]-'a'] = -1;
            tmp[b-'a']++;
            st.update(1, 0, N-1, a, tmp);
            s[a] = b;
        }
        else
        {
            int b;
            cin >> b;
            a--;
            b--;
            ST ans = st.query(1, 0, N-1, a, b);
            int curr = 0;
            for(int i=0;i<26;i++) 
                if(ans.count[i]) curr++;
            cout << curr << "\n";
            //prc(all(ans.count));
        }
    }
    return 0;
}

