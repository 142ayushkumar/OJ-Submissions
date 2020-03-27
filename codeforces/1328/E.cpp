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

struct lca {
    vector<vector<int>> &graph;
    vector<vector<int>> par;
    vector<int> depth;
    int n, m;
    int root;

    void dfs(int cur, int prev = 0, int ht = 0) {
        par[cur][0] = prev;
        depth[cur] = ht;
        for(int u : graph[cur]) {
            if(u != prev) {
                dfs(u, cur, ht + 1);
            }
        }
        return;
    }

    lca(vector<vector<int>> &_graph, int _root = 1) : graph(_graph), root(_root) {
        n = (int)graph.size();
        m = (int)log2(n) + 2;
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i].resize(m);
        }
        depth.resize(n, 0);
        dfs(root);

        for(int i = 1; i < m; i++) {
            for(int j = 0; j < n; j++) {
                par[j][i] = par[par[j][i - 1]][i - 1];
            }
        }
    }

    int get(int u, int v) {
        if(depth[u] > depth[v]) {
            swap(u, v);
        }
        int diff = depth[v] - depth[u];
        for(int i = m - 1; i >= 0; i--) {
            if((diff >> i) & 1) {
                v = par[v][i];
            }
        }
        if(u == v) {
            return u;
        }
        for(int i = m - 1; i >= 0; i--) {
            if(par[u][i] != par[v][i]) {
                u = par[u][i];
                v = par[v][i];
            }
        }
        return par[u][0];
    }
};

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
	int n, m;
    cin >> n >> m;	
	vector<vector<int>> graph;
    graph.resize(n+1);
    for(int i=1;i<n;i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].pb(b);
        graph[b].pb(a);
    }
    struct lca lca_(graph);
    string dummy;
    getline(cin, dummy);
    while(m--)
    {
        int k;
        cin >> k;
        vector<int> query(k);

        for(int i=0;i<k;i++) 
            cin >> query[i];
        sort(all(query), [&](int a, int b) {return lca_.depth[a] < lca_.depth[b];});
        bool ans = true;
        for(int i:query)
        {
            int curr = lca_.get(query.back(), i);
            if(lca_.depth[i] - lca_.depth[curr] > 1)
                ans = false; 
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
        
    }
    return 0;
}

