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

vector<vector<int>> level_order;
vector<int> pos; // maps i with its level order index

struct lca {
    vector<vector<int>> &graph;
    vector<int>& parents;
    vector<vector<int>> par;
    vector<int> depth;
    int n, m;
    int root;

    void dfs(int cur, int prev = 0, int ht = 0) {
        par[cur][0] = prev;
        depth[cur] = ht;
        pos[cur] = level_order[ht].size();
        level_order[ht].pb(cur);
        for(int u : graph[cur]) {
            if(u != prev) {
                dfs(u, cur, ht + 1);
            }
        }
        return;
    }

    lca(vector<vector<int>> &_graph, vector<int>& _parents, int _root = 1) : graph(_graph), parents(_parents), root(_root) {
        n = (int)graph.size();
        m = (int)log2(n) + 2;
        par.resize(n);
        for(int i = 0; i < n; i++) {
            par[i].resize(m);
        }
        depth.resize(n, 0);
        for(int i:parents)
            dfs(i, i);

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
    
    int lift(int u, int v)
    {
        // lift u by b levels
        for(int i=m-1;i>=0;i--)
        {
            if((v >> i)& 1)
            {
                u = par[u][i];
            }
        }
        return u;
    }
};

int32_t main()
{
    fastio;
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
	int n;
    cin >> n;
    vector<vector<int>> tree;
    vector<int> parents;
    pos.resize(n+1);
    tree.resize(n+1);
    level_order.resize(n+1);
    for(int i=1;i<=n;i++)
    {
        int t;
        cin >> t;
        if(t == 0)
            parents.pb(i);
        else
        {
            tree[i].pb(t);
            tree[t].pb(i);
        }
    }
    struct lca lca_(tree, parents);
    int m;
    cin >> m;
    vector<int> ans(m, -1);
    for(int i=0;i<m;i++)
    {
        int a, b;
        cin >> a >> b;
        int parent = lca_.lift(a, b), child = lca_.lift(a, b-1);
        if(parent == child) ans[i] = 0;
        else
        {
            int idx = pos[a], depth = lca_.depth[a], curr = 0;
            // now binary search left and right in the level_order vector to get
            // the ans
            int l = idx, r = (int)level_order[depth].size() - 1;
            while(l < r)
            {
                int mid = (l + r + 1)/2;
                if(lca_.lift(level_order[depth][mid], b) != parent)
                    r = mid-1;
                else 
                    l = mid;
            }
            curr += l - idx;
            l = 0, r = idx;
            while(l < r)
            {
                int mid = (l + r)/2;
                if(lca_.lift(level_order[depth][mid], b) != parent)
                    l = mid+1;
                else 
                    r = mid;
            }
            curr += idx - l;
            ans[i] = curr;
        }
    }
    for(int i=0;i<m;i++)
        cout << ans[i] << " ";
    cout << "\n";


        
    return 0;
}

